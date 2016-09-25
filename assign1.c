/*
 * ==================================================================
 * Name			: toString.c
 * Author		: Michel Cantacuzene
 * Version		: 0.1
 * Copyright		: GNU common license
 * Description		: main program for ECSE 202 assignment 1
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
	for (int i=0; i<len_in; i++){
		out[(len_out+i)] = in[(i)]; //the char array starts at 0 if the string is n characters long, the n'th character will be the EOS (End Of String) character that is why we start appending at len_out (since i=0 on the first itteration).
	}
}

void toString(int argc, char *argv[], char buffer[]){ //function to concat all strings inserted after the name of the program
	for (int i=1;i<argc;i++){ //We start at 1 since the first element of argv is the location of the program being run.
		append(buffer,argv[i]);
	}
}

int array_size(int argc, char *argv[]){ //funtion to get the exact number of caracter inputed as to create an array of the correct length
	int s = 0;
	for (int i=1;i<argc;i++){ // We start i at 1 since the First string is the program name / it's location
		s += size(argv[i]);
	}
	return s; //return the number of caracters
}

int getMax(char hist[]){ //get the max occurence of one character as a baseline
	int max = 0;
	for(int i=0;i<256;i++){
		if(hist[i]>max){max=hist[i];}
	}
	return max;
}

void doHist(char buffer[], char hist[]){ //doHist function 
	for(int i=0;i<256;i++){ //we put every entry in the hist array to zero
		hist[i]=0;
	}
	for(int i=0;i<size(buffer);i++){
		hist[buffer[i]] += 1; // we increment the value of hist[k] by one whenever we see a character with the acsii value of k
	}
}

void displayHist(char hist[], int distinct_chars){ //function to display our results
	int max = getMax(hist);
	int MAXSCALE = 25;
	int barlength;
	for(int i=0;i<256;i++){
		if (hist[i] > 0){
			barlength = (int)(((double)hist[i])/((double)max)*((double)MAXSCALE));
			printf("%c \t [%d] \t",i,hist[i]);
			for(int i=0;i<barlength;i++){printf("*");}
			printf("\n");
		}
	}
}

int main(int argc, char *argv[]){ //main function
	int arr_sze = array_size(argc,argv);
	char text[arr_sze];
	for (int j =0;j<arr_sze;j++){text[j]='\0';}
	char hist[256];
	toString(argc,argv,text);
	printf("%s \n",text);
	doHist(text,hist);
	displayHist(hist,0);
	return 0;
	
}
