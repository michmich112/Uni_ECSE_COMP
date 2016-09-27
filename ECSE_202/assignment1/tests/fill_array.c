#include <stdio.h>

int main(int argc, char *argv[]){
	char test[256]; //I wanted to see what values would be stored inside a 256 long array
	for (int i=0;i<256;i++){
		printf("%d \t",test[i]);
	}
	printf("\n %d \n",test[256]);
	printf("%s \n", test);
}
