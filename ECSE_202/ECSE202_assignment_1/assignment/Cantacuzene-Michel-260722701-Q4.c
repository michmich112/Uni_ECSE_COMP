/*
 * =============================================================
 * Name			: assign1.c
 * Author		: Michel Cantacuzene
 * Version		: 0.1
 * Copyright		: Creative Commons
 * Description		: main program for ECSE 202 assignment 1
 * =============================================================
 */

#include <stdio.h>

int size(char text[]){ //size function to get the size of an string
	int start = 0;
	char character = text[0];
	while(character != '\0'){
		start += 1;
		character = text[start];
	}
	return start;
}

int getMax(char hist[]){ //get the max occurence of one character as a baseline
	int max = 0;
	for(int i=0;i<256;i++){
		if(hist[i]>max){max=hist[i];}
	}
	return max;
}

int array_size(int argc, char *argv[]){ //funtion to get the exact number of caracter inputed as to create an array of the correct length
	int s = 0;
	for (int i=1;i<argc;i++){ // We start i at 1 since the First string is the program name / it's location
		s += size(argv[i]);
	}
	return s; //return the number of caracters
}

void append(char out[], char in[]){ //function to append a string onto another one
	int len_out = size(out);
	int len_in = size(in);
	for (int i=0; i<=len_in; i++){
		out[(len_out+i)] = in[(i)]; //the char array starts at 0 if the string is n characters long, the n'th character will be the EOS (End Of String) character that is why we start appending at len_out (since i=0 on the first itteration).
	}
}

void toString(int argc, char *argv[], char buffer[]){ //function to concat all strings inserted after the name of the program
	buffer[0]='\0'; //put the first element in the array to an EOS character.
	for (int i=1;i<argc;i++){ //We start at 1 since the first element of argv is the location of the program being run.
		append(buffer,argv[i]);
	}
}

int doHist(char buffer[], char hist[]){ //doHist Function
	int distinct_chars = 0;
	for(int i=0;i<256;i++){
		hist[i]=0;
	}
	for(int j=0;j<size(buffer);j++){ //this loops counts the numebr of distinct characters in the string
		if(hist[buffer[j]] == 0){
			distinct_chars += 1;
			hist[buffer[j]] += 1;
		}
		else{
			hist[buffer[j]] += 1;
		}
	}
	return distinct_chars;
}

void displayHist(char hist[], int distinct_chars){ //function to display our results
	printf("There are %d distinct characters \n",distinct_chars);
	int max = getMax(hist);
	int MAXSCALE = 25;
	int barlength;
	for(int i=0;i<256;i++){
		if (hist[i] != 0){
			barlength = (int)(((double)hist[i])/((double)max)*((double)MAXSCALE));
			printf("%c \t [%d] \t",i,hist[i]);
			for(int i=0;i<barlength;i++){printf("*");}
			printf("\n");
		}
	}
}

int main(int argc, char *argv[]){ //main function to make the whole run
	int sze = array_size(argc, argv);
	char text[sze];
	toString(argc,argv,text);
	char hist[256];
	displayHist(hist,doHist(text, hist));
}
