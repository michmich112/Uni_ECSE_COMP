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

void doHist(char buffer[], char hist[]){
	for(int i=0;i<256;i++){
		hist[i]=0;
	}
	for(int i=0;i<size(buffer);i++){
		hist[buffer[i]] += 1;
	}
}

int main(int argc, char *argv[]){
	char text[] = "Jesuisbobdacords";
	char hist[256];
	doHist(text,hist);
	for (int i=0;i<256;i++){
		printf("%d \t",hist[i]);
	}
}
