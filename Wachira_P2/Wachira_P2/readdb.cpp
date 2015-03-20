#include "header.h"
link readdb(void)
{
	link ptr, firstptr, lastptr;
	DWORD  count;
	HANDLE rfile;
	TCHAR fname[] = TEXT("OrderData.dat");
	rfile = CreateFile(fname, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	firstptr = NULL;
	lastptr = NULL;
	while(true)
	{
		ptr = (link)malloc(sizeof(struct item));
		ReadFile(rfile, ptr, sizeof(struct item), &count, NULL);
		if (count == 0) break;
		else
		{
			if (!firstptr)firstptr=ptr;
			else lastptr->next = ptr;
			ptr->last = lastptr;
			lastptr=ptr;
		}
	}
	CloseHandle(rfile);
	return firstptr;
}


link deleteItem(void)
{
	link ptr, firstptr, lastptr;
	DWORD  count;
	HANDLE rfile;
	int deleteID;
	TCHAR fname[] = TEXT("OrderData.dat");
	rfile = CreateFile(fname, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	firstptr = NULL;
	lastptr = NULL;

	cout << "Which Item ID do you want to delete ?" << endl;
	cin >> deleteID;

	while (true)
	{
		ptr = (link)malloc(sizeof(struct item));
		ReadFile(rfile, ptr, sizeof(struct item), &count, NULL);

		cout << ptr->itemID << endl;
		/*if (ptr->next->itemID == deleteID)
		{
			link temp = ptr->next;
			ptr->next = ptr->next->next;
			ptr->next->last = ptr;
			delete temp;
		}*/
		if (count == 0) break;
		else
		{	
			if (!firstptr)firstptr = ptr;
			else lastptr->next = ptr;
			ptr->last = lastptr;
			lastptr = ptr;
		}
	}
	CloseHandle(rfile);
	return firstptr;
}