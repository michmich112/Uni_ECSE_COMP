/*
 Assignment 2 ECSE202
 This program assumes that
 a names and IDs data file (location and name) is passed as the first argument
 a marks data files is passed as the second argument
 an ID number is passed as the third argument
*/

/*
Name:			ECSE202ASSIGNMENT2.c
Author:			Michel Cantacuzene
Description:	Second assignment for ECSE 202. Based on Assignment2Template.c.
Date:			October 15, 2016
*/

#define NUMRECORDS 50
#define MAXNAMELENGTH 15
#include <stdio.h>
#include <stdlib.h>

//Define structure to hold student data
struct StudentRecord
{
	char FirstNames[MAXNAMELENGTH];
	char LastNames[MAXNAMELENGTH];
	int IDNums;
	int Marks;
};

void swap(struct StudentRecord *x, struct StudentRecord *y) { //swaps the value of x for y (specificaly for struct elements)
	struct StudentRecord temp = *x;
	*x = *y;
	*y = temp;
}

void quickSort(struct StudentRecord arr[], unsigned int left, unsigned int right) { //quicksorts StudentRecord elements by their ID number
	unsigned int i, mid;
	int pivot;
	if (left >= right) { //condition for break
		return;
	}
	swap(arr + left, arr + (left + right)/2);
	pivot = arr[mid = left].IDNums;
	for (i = left + 1; i <= right; i++) {
		if (arr[i].IDNums < pivot){
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

int binarySearch(struct StudentRecord list[],int element, int NOE){ //binary search for a specific student ID
	int Left = 0;
	int Right = (NOE-1);
	int middle;
	int i=0;
	while(i<(NOE/2)){ //we don't do an infinite loop since there might be an error and the algorithm may not find the correct value and loop forever
		middle = (int) ((Left+Right)/2);
		if(Left>Right){
			return 0;
		}
		if(list[middle].IDNums<element){
			Left=middle+1;
		}else if(list[middle].IDNums>element){
			Right=middle-1;
		} else if(list[middle].IDNums==element){
			return (middle+1);
		}

	}
	return 0; //return an error since the algorithm is stuck in a loop
}

void response(int res,struct StudentRecord list[],char* argv[]){ //small response funcion to make the main function more readable
	if(res==0){
		printf("\nID: %s does not exist\n",argv[3]);
		exit(0);
	}else {
		printf("\nID: %d\tStudent: %s, %s\t Mark: %d\n",list[res-1].IDNums,list[res-1].LastNames,list[res-1].FirstNames,list[res-1].Marks);
	}
}

int main(int argc, char * argv[]) { //main function

	struct StudentRecord SRecords[NUMRECORDS];
	int recordnum;
	unsigned int pointers[NUMRECORDS];

	//Read in Names and ID data
	FILE * NamesIDsDataFile;
	if((NamesIDsDataFile = fopen(argv[1], "r")) == NULL){
		printf("Can't read from file %s\n", argv[1]);
		exit(1);
	}
	for (recordnum=0;recordnum<NUMRECORDS;recordnum++){
		fscanf (NamesIDsDataFile, "%s%s%d", &(SRecords[recordnum].FirstNames[0]),&(SRecords[recordnum].LastNames[0]),&(SRecords[recordnum].IDNums));
	}
	fclose(NamesIDsDataFile);

	//Read in marks data
	FILE * MarksDataFile;
	if((MarksDataFile = fopen(argv[2], "r")) == NULL){
		printf("Can't read from file %s\n", argv[2]);
		exit(1);
	}
	for (recordnum=0;recordnum<NUMRECORDS;recordnum++){
		fscanf (MarksDataFile, "%d", &(SRecords[recordnum].Marks));
	}
	fclose(MarksDataFile);
	
	//Print out data as read in
	for(recordnum=0;recordnum<NUMRECORDS;recordnum++){
		printf("%s %s %d %d\n",SRecords[recordnum].FirstNames,SRecords[recordnum].LastNames,SRecords[recordnum].IDNums, SRecords[recordnum].Marks);
	}
	
	//Quicksorts data by ID number
	quickSort(SRecords,0,NUMRECORDS-1);
	
	//Prints out success message
	printf("\nRecords sorted by ID\n");
	
	//Print out the sorted values
	for(recordnum=0;recordnum<NUMRECORDS;recordnum++){
		printf("%s %s %d %d\n",SRecords[recordnum].FirstNames,SRecords[recordnum].LastNames,SRecords[recordnum].IDNums, SRecords[recordnum].Marks);
	}
	
	//Print out the correct response depending on the case
	response(binarySearch(SRecords,atoi(argv[3]),NUMRECORDS),SRecords,argv);

	return 0; //EXIT_SUCCESS does not compile on gcc Mac (Undefined)
}
