#include <stdio.h>

int size(char text[]){
	int start = 0;
	char character = text[0];
	while (character != '\0'){
		start += 1;
		character = text[start];
	}
	return start;
}
	
void append(char out[], char in[]){
	int len_out = size(out);
	int len_in = size(in);
	for (int i=0; i<len_in; i++){
		out[(len_out+i)] = in[(i)];
	}
	out[(len_out + len_in + 1)] = '\0';
}



void toString(int argc, char *argv[], char buffer[]){
	for (int i=1;i<argc;i++){ //We start at 1 since the first element of argv is the location of the program being run.
		printf("%s \n", argv[i]);
		append(buffer,argv[i]);
	}
}

int main(int argc, char *argv[]){
	char text[256];
	toString(argc,argv,text);
	printf("\n %s \n",text);
	int s = size(text);
	return 0;
}


