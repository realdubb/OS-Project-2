#include "header.h"



HANDLE createdb(link firstptr)
{

	DWORD  count;
	HANDLE file;
	link ptr;
	TCHAR fname[] = TEXT("OrderData.dat");
	file = CreateFile(fname, GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	ptr = firstptr;
	WriteFile(file, ptr, sizeof(struct item), &count, NULL);

	
	return file;
}


void writedb(link firstptr)
{
	TCHAR fname[] = TEXT("OrderData.dat");
	HANDLE file;
	DWORD count;
	link ptr;

	file = CreateFile(fname, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	ptr = firstptr;
	while(ptr != NULL)
	{
		WriteFile(file, ptr, sizeof(struct item), &count, NULL);
		ptr = ptr->next;
	}
	CloseHandle(file);
	return;
}