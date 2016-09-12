/*
================================================
Name		: main.c
Author		: Michel Cantcuzene
Version		: 0.1
Copyright	: Your copyright notice
Description	: Hello World in C, Ansi style
================================================
*/


#include <stdio.h>
#include <stdlib.h>

int main(void){
	// you can write main(int arg,char *argv[])
	printf("hello World \n");
	int sum = 0;
	for (int i=0;i<10;i++){
		sum = sum + i;
	}
	printf("%d \n",sum);
	return EXIT_SUCCESS;
}
