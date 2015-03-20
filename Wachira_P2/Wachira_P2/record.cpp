#include <windows.h>

void main8()
{
	DWORD count;
	char data[250] = { 0 };
	char prompt[] = "Enter some text. When you are done, enter quit.\n";
	HANDLE file, input, output;


	TCHAR fileName[] = TEXT("C:\\Users\\aleqs_000\\Documents\\GitHub\\OS-Project-2\\Wachira_P2\\Wachira_P2\\record.out");

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
	Sleep(5000);
}