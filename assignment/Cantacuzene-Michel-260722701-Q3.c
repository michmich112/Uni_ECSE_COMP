/*
 * ============================================================
 * Name			: displayHist.c
 * Author		: Michel Cantacuzene
 * Version		: 0.1
 * Copyright		: Creative Commons
 * Description		: displayHist for ECSE 202 assignment 1
 * ============================================================
 */

#include <stdio.h>

int getMax(char hist[]){
	int max = 0;
	for(int i=0;i<256;i++){
		if (hist[i]>max){max=hist[i];}
	}
	return max;
}

void displayHist(char hist[], int distinct_chars){
	int max = getMax(hist);
	int MAXSCALE = 10;
	int barlength;
	for (int i=0;i<256;i++){
		if (hist[i] != 0){
			barlength = (int)(((double)hist[i])/((double)max)*((double)MAXSCALE));
			printf("%c \t [%d] \t",i,hist[i]);for(int i=0;i<barlength;i++){printf("*");} //display everything pertaining to the bar 
			printf("\n"); //print the newline character to tell the console to got to a new line.
		}
	}
}

