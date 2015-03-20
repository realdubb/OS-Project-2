#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <iostream>
#include <iomanip>

#pragma once

using namespace std;

typedef struct item * link;

const int MaxLength = 64;
struct item
{
	link next;
	int itemID;
	int quantity;
	double price;
	char description[MaxLength];
	link last;
};

void insert(HANDLE file);
void insert(link ptr);
HANDLE createdb(link ptr);
link newflt(void);
link parse(char* pindat, link ptr);
void dispdb(link ptr);
link deleteItem(void);
void writedb(link firstptr);
link readdb(void);

