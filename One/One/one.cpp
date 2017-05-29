#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
	cout << "In this process!\n" << endl;
	HANDLE hMutex = CreateMutex(NULL, true, L"XONE"); 
	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		if (hMutex) CloseHandle(hMutex);

		MessageBox(0, L"XONE already runing!", L"", 0);
		return -1;
	}

	getchar();
	return 0;
}