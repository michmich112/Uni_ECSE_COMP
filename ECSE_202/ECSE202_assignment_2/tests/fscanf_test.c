#include <stdio.h>

int main(int argc, char *argv[])
{
	char str1[20], str2[20];
	int ID;
	FILE * fp;
	fp = fopen("NamesIDs.txt","r+");

	for(int i=0; i<50;i++){
		fscanf(fp,"%s %s", str1,str2);
		fscanf(fp,"%d",&ID);
		printf("%s\t\t%s\t\t%d\n",str1,str2,ID);
	}
}
