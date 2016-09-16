#include <stdio.h>

void getHist(char text[], char hist[]){
	int i=0;
	while(text[i] != '\0'){
		hist[text[i]] += 1;
		i++;
	}
}


int getMax(char hist[]){
	int max = 0;
	for(int i=0;i<256;i++){
		if (hist[i]>max){max=hist[i];}
	}
	return max;
}

void displayHist(char hist[]){
	int max = getMax(hist);
	int MAXSCALE = 25;
	int barlength;
	for (int i=0;i<256;i++){
		if (hist[i] != 0){
			barlength = (int)(((double)hist[i])/((double)max)*((double)MAXSCALE));
			printf("%c \t [%d] \t",i,hist[i]);for(int i=0;i<barlength;i++){printf("*");} //display everything pertaining to the bar 
			printf("\n"); //print the newline character to tell the console to got to a new line.
		}
	}
}

int main(int argc, char *argv[]){
	char hist[256];
	for(int i=0;i<256;i++){hist[i]=0;} //put all of the values in hist to 0
	for(int i=1;i<argc;i++){
		getHist(argv[i],hist);
	}
	displayHist(hist);
	return 0;
}
