#include <stdio.h>

int size(char text[]){
	int i =0;
	while (text[i] != '\0'){
		i++;
	}
	return i;
}

int main(int argc, char *argv[]){
	for(int i=0; i<argc; i++){
		printf("%d \n",size(argv[i]));
	}
	return 0;
}
