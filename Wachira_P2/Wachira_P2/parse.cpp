#include "header.h"
link parse(char* pindat,link ptr)
{
	int index=0;		//parser index variable
	char *mark;			//temporary line pointer

	//item ID detect and copy

	while(*(pindat+index)!=' ') index++;
	*(pindat+index)=0;
	ptr->itemID = atoi(pindat);
	pindat+=index;

	//quantity

	index = 0;				//reset index to zero;
	while (*pindat++ == ' ');	//locate next nonspace value
	while (*(pindat + index) != ' ') index++;
	*(pindat + index) = 0;
	ptr->quantity = atoi(pindat);
	pindat += index;

	//price

	index=0;				//reset index to zero;
	while(*pindat++ ==' ');	//locate next nonspace value
	while(*(pindat+index)!=' ') index++;
	*(pindat+index)=0;
	ptr->price = atof(pindat);
	pindat+=index;


	//description

	while(*pindat++ ==' ');	//locate next nonspace value
	strcpy_s(ptr->description, pindat);
	return ptr;
}