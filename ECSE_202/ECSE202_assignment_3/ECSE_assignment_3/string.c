#include <stdio.h>

int main(int argc, char *argv[]){
	int j=0;
	char a=argv[0][0];
	while(a != '\0'){
		printf("%c",argv[0][j]);
		j++;
		a=argv[0][j];
	}
	return 0;
}
