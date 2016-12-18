#include <stdio.h>

void swap(int* pa, int* pb){
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}

int main(int argc, char *argv[]){
	int a=10;
	int b=50;
	int *pa = &a;
	int *pb = &b;
	swap(pa,pb);
	printf("a= %d \t b= %d \n",*pa, *pb);
}
