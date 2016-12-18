/*
 * ================================================================
 * Name			: doHist.c
 * Author		: Michel Cantacuzene
 * Version		: 0.1
 * Copyright		: GNU common license
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

int getMax(char hist[]){ //get the max occurence of one character as a baseline
	int max = 0;
	for(int i=0;i<256;i++){
		if(hist[i]>max){max=hist[i];}
	}
	return max;
}
/*
void doHist(char buffer[], char hist[]){ //doHist function 
	for(int i=0;i<256;i++){ //we put every entry in the hist array to zero
		hist[i]=0;
	}
	for(int i=0;i<size(buffer);i++){
		hist[buffer[i]] += 1; // we increment the value of hist[k] by one whenever we see a character with the acsii value of k
	}
}
*/

int doHist(char buffer[], char hist[]){
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

int main(int argc, char *argv[]){ //main function to test our function(s)
	char text[] = "Jesuisbobdacords";
	char hist[256];
	displayHist(hist,doHist(text, hist));
}
