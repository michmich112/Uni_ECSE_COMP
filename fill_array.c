#include <stdio.h>

int main(int argc, char *argv[]){
	char test[256];
	for (int i=0;i<256;i++){
		printf("%d \t",test[i]);
	}
	printf("\n %d \n",test[256]);
	printf("%s \n", test);
}
