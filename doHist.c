#include <stdio.h>

// We know that hist is a 256 wide array

int size(char text[]){
	int start = 0;
	char character = text[0];
	while(character != '\0'){
		start += 1;
		character = text[start];
	}
	return start;
}

int getMax(char hist[]){
	int max = 0;
	for(int i=0;i<256;i++){
		if(hist[i]>max){max=hist[i];}
	}
	return max;
}

void doHist(char buffer[], char hist[]){
	for(int i=0;i<256;i++){
		hist[i]=0;
	}
	for(int i=0;i<size(buffer);i++){
		hist[buffer[i]] += 1;
	}
}

void displayHist(char hist[], int distinct_chars){
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

int main(int argc, char *argv[]){
	char text[] = "Jesuisbobdacords";
	char hist[256];
	doHist(text,hist);
	displayHist(hist,0);
}
