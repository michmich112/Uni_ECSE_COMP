#include <stdio.h>
#include <string.h>

void toString(int argc, char *argv[], char buffer[]){
	
}

void append(char out[], char in[]){
	out = strcat(out,in);
}

int size(char text[]){
	int start = 0;
	char character = text[0];
	while (character != '\0'){
		start += 1;
		character = text[start];
	}
	return start;
}
	
int main(int argc, char *argv[]){
	char text[] = "bob";
	char dot[] = "lol";
	append(text,dot);
	int s = size(text);
	printf("%d \n",s);
	printf("%s \n",text);
	return 0;
}


