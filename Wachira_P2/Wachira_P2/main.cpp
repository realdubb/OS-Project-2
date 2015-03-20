#include "header.h"
void main(void)
{
	link ptr, firstptr, lastptr;
	char sel;
	while(true)
	{
		printf("\nSelect Option:\n");
		printf("(1) Enter new database\n");
		printf("(2) Read database from disk\n");
		printf("(3) Insert new flight into database\n");
		printf("(4) Delete flight from database\n");
		printf("(5) Modify entry in database\n");
		printf("(6) Time sort database\n");
		printf("(7) Save current database to disk\n");
		printf("(8) Display current databse in memory\n");
		printf("(9) Exit the database\n");
		sel=_getch();
		switch(sel)
		{
		case '1':

			firstptr=NULL;					//set pointers to nothing.
			lastptr=NULL;
			while(true)
			{	
				if((ptr=newflt())==NULL)	//if ptr is NULL, database entry is finished
				{
					free(ptr);				//release memory for bogus allocation
					break;					//get out of input loop
				}
				if(!firstptr) firstptr=ptr;		//for first object only, assign firstptr
					else  lastptr->next = ptr;	//for all other objects, point last to this one

				ptr->last=lastptr;				//for all, point to prevfious object
				lastptr=ptr;					//update last pointer to point to this object
			}
			dispdb(firstptr);
			writedb(firstptr);
			break;
		case '2':
			firstptr=readdb();
			if(firstptr==NULL)
			{
				printf("\nThe specified file does not exist. Try again\n");
				break;
			}
		//	firstptr=bsort(firstptr);
		//	dispdb(firstptr);
			break;
		case '3':
		//	insert(firstptr);
		//	firstptr=bsort(firstptr);
		//	dispdb(firstptr);
			break;
		case '4':
		//	firstptr=delflt(firstptr);
		//	dispdb(firstptr);
		//	break;
		case '5':
		//	modflt(firstptr);
			break;
		case '6':
		//	firstptr=bsort(firstptr);
			break;
		case '7':
			writedb(firstptr);
			break;
		case '8':
			dispdb(firstptr);
			break;
		case '9':
			exit(0);
		default:
			printf("This was an invalid option. Try again");
		}
	}
}


