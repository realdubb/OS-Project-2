#include "header.h"
link parse(char* pindat,link ptr)
{
	int index=0;		//parser index variable
	char *mark;			//temporary line pointer

	//flight number detect and copy

	while(*(pindat+index)!=' ') index++;
	*(pindat+index)=0;
	ptr->flt = atoi(pindat);
	pindat+=index;

	//city detect and copy

	while(*pindat++ ==' ');	//locate next nonspace value
	mark=pindat;			//mark start of city code field
	while(*pindat < '0' || *pindat > '9')pindat++;
	*(--pindat)=0;
	strcpy_s(ptr->city, mark);

	//time detect and copy

	index=0;				//reset index to zero;
	while(*pindat++ ==' ');	//locate next nonspace value
	while(*(pindat+index)!=' ') index++;
	*(pindat+index)=0;
	ptr->time = atoi(pindat);
	pindat+=index;

	//gate detect and copy

	index=0;				//reset index to zero;
	while(*pindat++ ==' ');	//locate next nonspace value
	while(*(pindat+index)!=' ') index++;
	*(pindat+index)=0;
	ptr->gate = atoi(pindat);
	pindat+=index;

	//remarks detect and copy

	while(*pindat++ ==' ');	//locate next nonspace value
	strcpy_s(ptr->rmk, pindat);
	return ptr;
}