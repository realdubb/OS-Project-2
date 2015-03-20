#include <windows.h>
#include <stdio.h>

void main()
{
	DWORD count;
	char data[250] = { 0 };
	char prompt[] = "Enter some text. When you are done, enter quit.\n";
	HANDLE file, input, output;


	TCHAR fileName[] = TEXT("C:\\Users\\alex\\Documents\\GitHub\\OS-Project-2\\Wachira_P2\\Wachira_P2\\record.out");

	input = GetStdHandle(STD_INPUT_HANDLE);
	output = GetStdHandle(STD_OUTPUT_HANDLE);
	file = CreateFile(fileName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	WriteFile(output, prompt, sizeof(prompt)-1, &count, NULL);
	ReadFile(input, data, 250, &count, NULL);


	while (strncmp(data, "quit", 4) != 0)
	{
		WriteFile(file, data, count, &count, NULL);
		ReadFile(input, data, 250, &count, NULL);
	}

	CloseHandle(file);
	Sleep(2000);
}



/*
Create File is creating a file in the directory specified for a generic write.
Write File, the first command transfers data from memory where prompt variable is stored and outputs to console 67 characters.
The first Read File, reads from initializes the input buffer with the first user input from console upto 250 characters and stores that in data.

Write File #2, gets from "data", a 'count' number of characters and writes to the file that's open.
Read File #2 continues getting input from console via input handle and storing it in data

CloseHandle, terminates access to the file we created so it can now be open with other programs


Write File again gets the 
*/