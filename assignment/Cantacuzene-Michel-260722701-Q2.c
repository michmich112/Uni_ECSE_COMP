/*
 * ================================================================
 * Name			: doHist.c
 * Author		: Michel Cantacuzene
 * Version		: 0.1
 * Copyright		: Creative Commons
 * Description		: doHist function for ECSE 202 assignment 1
 * ================================================================
 */

#include <stdio.h>

// We know that hist is a 256 wide array

int size(char text[]){ //size function to get the size of an string
	int start = 0;
	char character = text[0];
	while(character != '\0'){
		start += 1;
		character = text[start];
	}
	return start;
}

int doHist(char buffer[], char hist[]){ //doHist function that creates and fills the histogram
	int distinct_chars = 0;
	for(int i=0;i<256;i++){
		hist[i]=0;
	}
	for(int j=0;j<size(buffer);j++){
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

int main(void){
	char buffer[] = "allo";
	char hist[256];
	printf("%d \n", doHist(buffer,hist));
}
