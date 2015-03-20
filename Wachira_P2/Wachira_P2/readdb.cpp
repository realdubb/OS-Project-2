#include "header.h"
link readdb(void)
{
	link ptr, firstptr, lastptr;
	DWORD  count;
	HANDLE rfile;
	TCHAR fname[] = TEXT("dbdata.dat");
	rfile = CreateFile(fname, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	firstptr = NULL;
	lastptr = NULL;
	while(true)
	{
		ptr = (link)malloc(sizeof(struct db));
		ReadFile(rfile, ptr, sizeof(struct db), &count, NULL);
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
