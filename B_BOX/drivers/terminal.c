#include "terminal.h"

#define VGA_WIDTH 80
#define VGA_HEIGHT 25


int row =0;
int col =0;
char *video = (char*)0xb8000;

void clear_screen(){
	int i =0;

	while (i < VGA_WIDTH * VGA_HEIGHT ){
	video [i*2]=' ';
	video [i*2 + 1] = 0x07;
	i++;
	}

	row =0;
	col =0;
}


void new_line(){
	col = 0;
	row++;


	if (row >= VGA_HEIGHT){
	scroll_screen();
	}
}


void putchar(char c){
	if (c ==  '\n'){
	new_line();
	return;
	}

	int index = (row * VGA_WIDTH +col) *2;

	video[index] = c;
	video[index + 1] = 0x07;

	col++;
	if (col >= VGA_WIDTH){
	new_line();
	}
}


void print(char *str){

	int i = 0;
	while( str[i] !=  0){
	putchar( str[i] );
	i++;
	}
}


void scroll_screen(){
	video[0] = 'S';
	video[1] = 0x4F;

	int r = 1;

	while (r < VGA_HEIGHT){
	int c = 0;
		while (c < VGA_WIDTH){
		int from = ( r * VGA_WIDTH + c ) * 2;
		int to = (( r - 1 ) * VGA_WIDTH + c ) * 2;

		video[to] = video [from];
		video[to + 1] = video [from + 1];

		c++;
		}
	r++;
	}

	int c = 0;

	while (c < VGA_WIDTH){
		int index = ((VGA_HEIGHT - 1)* VGA_WIDTH + c) *2;
		video[index]=' ';
		video[index +1]=0x07;
		c++;
	}

row = VGA_HEIGHT - 1;
col = 0;

}

