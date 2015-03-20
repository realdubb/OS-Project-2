#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
typedef struct db * link;
struct db
{
	link last;
	int flt;
	char city[30];
	int time;
	int gate;
	char rmk[20];
	link next;
};
link newflt(void);
link parse(char* pindat,link ptr);
void dispdb(link ptr);
void writedb(link firstptr);
link readdb(void);