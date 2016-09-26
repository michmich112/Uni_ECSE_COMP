/*
 * ==================================================================
 * Name			: toString.c
 * Author		: Michel Cantacuzene
 * Version		: 0.1
 * Copyright		: Creative Commons
 * Description		: toString function for ECSE 202 assignment 1
 * ==================================================================
 */


#include <stdio.h> //include the standard library for the printf() function

int size(char text[]){ // Function to determine the size of a char array
	int start = 0;
	char character = text[0];
	while (character != '\0'){ //if the character that we are currently reading is different from a EOS (End Of String) character/pointer, continue the loop.
		start += 1;
		character = text[start];
	}
	return start; //return the value of the length of the string
}
	
void append(char out[], char in[]){ //function to append a string onto another one
	int len_out = size(out);
	int len_in = size(in);
	for (int i=0; i<=len_in; i++){
		out[(len_out+i)] = in[(i)]; //the char array starts at 0 if the string is n characters long, the n'th character will be the EOS (End Of String) character that is why we start appending at len_out (since i=0 on the first itteration).
	}
}

void toString(int argc, char *argv[], char buffer[]){ //function to concat all strings inserted after the name of the program
	buffer[0] = '\0';
	for (int i=1;i<argc;i++){ //We start at 1 since the first element of argv is the location of the program being run.
		append(buffer,argv[i]);
	}
}

