#include "header.h"
void writedb(link firstptr)
{
	TCHAR fname[] = TEXT("dbdata.dat");
	HANDLE file;
	DWORD count;
	link ptr;

	file = CreateFile(fname, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	ptr = firstptr;
	while(ptr != NULL)
	{
		WriteFile(file, ptr, sizeof(struct db), &count, NULL);
		ptr = ptr->next;
	}
	CloseHandle(file);
	return;
}