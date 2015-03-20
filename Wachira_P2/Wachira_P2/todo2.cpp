#include <windows.h>
#include <iostream>
using namespace std;

void main5()
{
	double numbers[] = {1.1,2.2,3.3,4.4,5.5};
	double value;

	DWORD count;
	char data[250] = { 0 };
	HANDLE file;


	TCHAR fileName[] = TEXT("C:\\Users\\alex\\Documents\\GitHub\\OS-Project-2\\Wachira_P2\\Wachira_P2\\random.out");


	file = CreateFile(fileName, GENERIC_WRITE | GENERIC_READ, 0, NULL, CREATE_ALWAYS,FILE_FLAG_RANDOM_ACCESS, NULL);

	WriteFile(file, numbers, sizeof(numbers), &count, NULL);

	for (int i = 4; i >= 0; i--)
	{
		SetFilePointer(file, i * sizeof(double), 0, FILE_BEGIN);
		ReadFile(file, &value, sizeof(value), &count, NULL);
		cout << "File entry " << i << " contains " << value << endl;
	}

	CloseHandle(file);
	Sleep(12000);
}



/*
Create File is opening a file in the directory specified for a generic read & write.

Write File, writes the array of doubles to the file.

SetFilePointer, moves the file pointer i times the size of a double, in this case it sets it to point at the last item read in to the file.

ReadFile then reads the value of the item being pointed to, making sure it's of "size value"

CloseHandle, terminates access to the file so it can now be open with other programs

*/