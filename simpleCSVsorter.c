#include "simpleCSVsorter.h"

int main(int argc, char** argv){
	char *buffer;
   	size_t bufsize = 0;
	size_t characters;
   	buffer = NULL;
	int lineCount=0;
	int tempcounter=0;
	line* head = NULL;
	line* ptr = head;
	char* tempBuff;
//	int len;
	while(tempcounter != 3){
   	//while(getline(&buffer,&bufsize,stdin) != -1){
		characters = getline(&buffer,&bufsize,stdin);
		line* newLine = (line*)malloc(sizeof(line));
		newLine->wholeLine =buffer;
		//finish building the struct here
		if(head==NULL){
			head=newLine;
			head->next = NULL;
		}
		else{
			newLine->next = head;
			head = newLine;	
		}
			
   		printf("You typed: '%s'\n", buffer);
		printf("\n");
		printf("\n");
		++lineCount;
		++tempcounter;
	}
	ptr = head;
	printf("2nd: %s\n", ptr->wholeLine);
	characters = getline(&buffer,&bufsize,stdin);
	strcpy(tempBuff,buffer);
	while(ptr!=NULL){
		printf("TESTTESTTEST: %s\n",ptr->wholeLine);
		ptr=ptr->next;
	}
	char* categoryToSort = argv[2];
	characters = characters;
	printf("The category we are sorting on is: '%s'\n",categoryToSort);
	printf("The number of lines in the CSV is: '%d'\n",lineCount);
	printf("The value of tempcounter is : '%d'\n",tempcounter);
   	return(0);		
}
