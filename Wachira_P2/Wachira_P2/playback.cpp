#include <Windows.h>

void main4()
{
	DWORD count;
	char data[250] = { 0 };
	char prompt[] = "Here is the content of your last recording session.\n";
	HANDLE file, output;


	TCHAR fileName[] = TEXT("C:\\Users\\alex\\Documents\\GitHub\\OS-Project-2\\Wachira_P2\\Wachira_P2\\record.out");


	output = GetStdHandle(STD_OUTPUT_HANDLE);

	file = CreateFile(fileName, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	WriteFile(output, prompt, sizeof(prompt)-1, &count, NULL);
	ReadFile(file, data, 250, &count, NULL);

	while (count != 0)
	{
		WriteFile(output, data, count, &count, NULL);
		ReadFile(file, data, count, &count, NULL);
	}

	CloseHandle(file);
	Sleep(5000);
}

/*
Create File is opening a file in the directory specified for a generic read.
Write File, the first command transfers data from memory where prompt variable is stored and outputs to console 72 characters.
The first Read File, reads from file the first 250 characters and stores that in data char array.

Write File #2, gets from "data", a 'count' number of characters and writes that to the output.
Read File #2 continues getting data from the file and storing it in data

CloseHandle, terminates access to the file so it can now be open with other programs

*/