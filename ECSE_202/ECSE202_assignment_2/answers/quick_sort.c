/*
 * quick_sort.c
 *
 *  Created on: Oct 13, 2016
 *      Author: eliott649
 */
#include <stdio.h>

void swap(int *x, int *y) { //swaps the value of x for y
	int temp = *x;
	*x = *y;
	*y = temp;
}

void quickSort(int arr[],unsigned int left, unsigned int right) {
	unsigned int i, mid;
	int pivot;
	if (left >= right) { //condition for break
		return;
	}
	swap(arr + left, arr + (left + right)/2); //swaps first value w/ value at half
	pivot = arr[mid = left];
	for (i = left + 1; i <= right; i++) {
		if (arr[i] < pivot){
			swap(arr + ++mid, arr + i);
		}
	}
	swap(arr+left, arr+mid);
	if (mid > left) {
		quickSort(arr,left, mid-1);
	}
	if (mid < right) {
		quickSort(arr,mid+1, right);
	}
}

int main(int argc, char* argv[]){
	int arr[10]={1,5,6,2,4,9,3,7,0,8};
	quickSort(arr,&arr[0],&arr[10]);
	for(int i=0;i<10;i++){printf("%d\n",arr[i]);}
	return 0;
}
