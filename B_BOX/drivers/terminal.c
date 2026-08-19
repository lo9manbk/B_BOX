/*
 * B_BOX Operating System
 *
 * Copyright (C) 2026 lo9manbk
 *
 * Licensed under the GNU General Public License v3.0.
 */

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
/*
// this a future pass function to test lowlevel control commend

void B_BOX_VERIFICATION (char c){
	char pass[] = { 'B', 'B', 'O', 'X' };  int i = 0; int bbox = 0;
 if (c != 0) { putchar(c);  
	if (pass[i] == c)  { bbox++; i++; 
		if (bbox == 4) { 
			new_line(); 
			print(" admin verificated "); 
			new_line(); print(" future command not now u fucher"); 
			new_line();    i = 0;    bbox = 0; 
		} } 
			else { i = 0; bbox = 0; }
    }}
*/
