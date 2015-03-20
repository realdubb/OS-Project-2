#include "header.h"
void dispdb(link ptr)
{
	char NullTime[]="    ";
	char NullGate[]="  ";
	//system("cls");
	printf(" Flt Cities                         Time  Gt  Remarks  \t\tLast      This      Next\n");
	do
	{	printf("\n%4d %-30s",ptr-> flt, ptr->city);
		if(ptr->time==0)printf(" %s",NullTime);
		else printf(" %4d",ptr->time);
		if(ptr->gate==0)printf(" %s",NullGate);
		else printf(" %2d",ptr->gate);
		printf(" %-15s  %p  %p   %p",ptr->rmk,ptr->last,ptr,ptr->next);
		ptr=ptr->next;
	}while(ptr !=NULL);
	printf("\n\n");
	return;
}