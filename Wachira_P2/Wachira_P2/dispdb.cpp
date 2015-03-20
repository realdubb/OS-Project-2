#include "header.h"
void dispdb(link ptr)
{

	printf("itemID    Quantity   Price     Description  \t\tLast      This      Next\n");
	do
	{	
		printf("\n%4d       %2d",ptr->itemID, ptr->quantity);
		printf("      %.2f",ptr->price);
		printf("           %-15s  %p  %p   %p",ptr->description,ptr->last,ptr,ptr->next);
		ptr=ptr->next;
	}while(ptr != NULL);
	printf("\n\n");
	return;
}