#include <Windows.h>

void main()
{
	DWORD count;
	char data[250] = { 0 };
	char prompt[] = "Here is the content of your last recording session.\n";
	HANDLE file, output;


	TCHAR fileName[] = TEXT("C:\\Users\\aleqs_000\\Documents\\GitHub\\OS-Project-2\\Wachira_P2\\Wachira_P2\\record.out");


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