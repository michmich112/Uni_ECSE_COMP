#include <stdio.h>

int binary_search(int list[], int element, int NOE);
void response(int resp);

int main(int argc, char *argv[]){
	int test[10] = {1,4,6,7,9,12,13,14,17,89};
	int num = 10;
	response(binary_search(test,12,num));
	return 0;
}

int binary_search(int list[],int element, int NOE){
	int Left = 0;
	int Right = (NOE-1);
	int middle;
	int i=0;
	while(i<(NOE/2)){ //we don't do an infinite loop since there might be an error and the algorithm may not find the correct value and loop forever
		middle = (int) ((Left+Right)/2);
		if(Left>Right){
			return 0;
		}
		if(list[middle]<element){
			Left=middle+1;
		}else if(list[middle]>element){
			Right=middle-1;
		} else if(list[middle]==element){
			return (middle+1);
		}

	}
	return 0; //return an error since the algorithm is stuck in a loop
}

void response(int resp){
	int ERROR=0;
	if(resp==ERROR){
		printf("Error 404, entry not found.\n");
	}else {
		printf("The element is the %dth entry\n",resp);
	}
}
