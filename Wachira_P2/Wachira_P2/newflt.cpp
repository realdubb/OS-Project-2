#include "header.h"
link newflt(void)
{
	char indat[64];		//inout line to be parsed
	char *pindat;		//pointer to input line
	link ptr;			//pointer to parsed data structure
	ptr=(link)malloc(sizeof(struct db));	//allocate memory for structure
	ptr->last=NULL;
	ptr->next=NULL;
	printf("Enter data line:  ");	//request input data
	gets_s(indat);					//get input data
	pindat=indat;					//set pointer to start of input data
	if(indat[0]== 'x' || indat[0] == 'X') return NULL;
	ptr=parse(pindat,ptr);
	return ptr;
}