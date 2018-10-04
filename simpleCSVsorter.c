#include "simpleCSVsorter.h"
#include "mergesort.h"
//------------Functions-----------------------//
int commaCounter(char* firstLine, char* catCheck, int bigLineCount){
	int functionCommaCount=0;
	char *token;
	token = strtok(firstLine, ",");
	while(token!=NULL){
		if(strcmp(token,catCheck)==0){
			return functionCommaCount;
		}
		token = strtok(NULL, ",");	
		functionCommaCount++;
	}	
	return -1;
}
//------------Main-----------------------------//
int main(int argc, char** argv){
	char* categoryToSort = argv[2];
	char *buffer;
   	size_t bufsize = 0;
	//int lineCount=0;
	int len;
	int mainCommaCount;
	if(categoryToSort == NULL){
		return -1;
	}
   	buffer = NULL;
	line* head = NULL;
	line* ptr = head;
	getline(&buffer, &bufsize,stdin);
	len = strlen(buffer);
	char* heading = (char*)malloc(len*sizeof(char));
	strncpy(heading,buffer,len);
	printf("%s",heading);
	mainCommaCount = commaCounter(heading, categoryToSort, len);
	if(mainCommaCount == -1){
		return -1;	
	}
	//while(lineCount !=10){
	while((getline(&buffer,&bufsize,stdin) != -1)){
		//getline(&buffer,&bufsize,stdin);
		len = strlen(buffer);
		char* tempBuff = (char*)malloc((len)*sizeof(char));
		strncpy(tempBuff, buffer, len);
		int i = 0;
		int currentComma = 0;
		while(currentComma!=mainCommaCount){
			if(tempBuff[i] == '"'){
				while(tempBuff[i]!='"'){
					i++;				
				}			
			}
			if(tempBuff[i] == ','){
				currentComma++;
			}
			i++;		
		}
		int j = i;
		while(tempBuff[j] != ','){
			j++;		
		}
		char *tempCompare = (char*)malloc((j-i)+2);//putting a big number 100 to replace (j-i) for this line
		if(tempBuff[i] == '"'){
			strncpy(tempCompare, tempBuff+(i+1), ((j-i)-1));		
		}
		else{
		strncpy(tempCompare, tempBuff+i, (j-i));
		}
		int length = strlen(tempCompare);
		j = length-1;
		i=0;
		if(strcmp(tempCompare,"")==0){
			j=0;
		}
		while(tempCompare[i]==' '||tempCompare[i]=='\t'){
			i++;
		}
		while(tempCompare[j]==' ' || tempCompare[j]=='\t'){
			j--;
		}
		j++;
		char *trimCompare = (char*)malloc(length+1);
		strncpy(trimCompare, tempCompare+i, (j-i));
		free(tempCompare);		
		line* newLine = (line*)malloc(sizeof(line));
		newLine->wholeLine =tempBuff;
		newLine->compareCat = trimCompare;
		if(head==NULL){
			head=newLine;
			head->next = NULL;
		}
		else{
			newLine->next = head;
			head = newLine;	
		}	
		//lineCount++;
	}
//reverse linked list here
        line* prev = NULL;
	line* current = head;
	line* next;
	while(current!=NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;	
	}
	head = prev;
//~~~~~~~~~~~~~~~~~~~~~~~list reversal ends here
	mergeSort(&head);
	ptr = head;
	//printf("\n");
	//printf("\n");
	while(ptr!=NULL){
		printf("%s",ptr->wholeLine);
		//printf("compareCat: %s\n", ptr->compareCat);
		ptr=ptr->next;
	}
   	return(0);		
}
