#include "header.h"
#include <string>

void main(void)
{
	link ptr, firstptr, lastptr;
	firstptr = NULL;
	HANDLE file;
	char sel;


	firstptr = readdb();

	//if no file exists create one, otherwise read it in
	if (!firstptr)
		file = createdb(firstptr);
	else
		firstptr = readdb();

	while(true)
	{
		printf("\nSelect Option:\n");
		printf("(1) Add Item\n");
		printf("(2) Remove Item\n");
		printf("(3) Display all items\n");
		printf("(4) Save and exit\n");
		sel=_getch();
		switch(sel)
		{
		case '1':

			firstptr = NULL;					//set pointers to nothing.
			lastptr = NULL;
			while (true)
			{
				if ((ptr = newflt()) == NULL)	//if ptr is NULL, database entry is finished
				{
					free(ptr);				//release memory for bogus allocation
					break;					//get out of input loop
				}
				if (!firstptr) firstptr = ptr;		//for first object only, assign firstptr
				else  lastptr->next = ptr;	//for all other objects, point last to this one

				ptr->last = lastptr;				//for all, point to prevfious object
				lastptr = ptr;					//update last pointer to point to this object
			}
			dispdb(firstptr);
			writedb(firstptr);

			break;
		case '2':
			firstptr = deleteItem();
			break;
			
		case '3':
			//firstptr=delflt(firstptr);
			dispdb(firstptr);
			break;


		case '4':
			writedb(firstptr);
			exit(0);

		default:
			printf("This was an invalid option. Try again");
		}
	}
}



void insert(link firstptr){
	DWORD  count;
	HANDLE file;
	link ptr;
	TCHAR fname[] = TEXT("OrderData.dat");

	file = CreateFile(fname, GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);


	firstptr = newflt();


	WriteFile(file, firstptr, sizeof(struct item), &count, NULL);

	CloseHandle(file);

	return;

}


link newflt(void)
{
	char indat[64];		//inout line to be parsed
	char *pindat;		//pointer to input line
	link ptr;			//pointer to parsed data structure
	ptr = (link)malloc(sizeof(struct item));	//allocate memory for structure
	//ptr->last = NULL;
	//ptr->next = NULL;
	printf("\nProvide the following or enter x to exit.\n");
	printf("itemID   quantity   price    description  \n");	//request input data
	gets_s(indat);					//get input data
	pindat = indat;					//set pointer to start of input data
	if (indat[0] == 'x' || indat[0] == 'X') return NULL;
	ptr = parse(pindat, ptr);
	ptr->next = NULL;
	ptr->last = NULL;
	return ptr;
}
