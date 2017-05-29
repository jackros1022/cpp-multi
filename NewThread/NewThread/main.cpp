#include <process.h>
#include <iostream>

using namespace std;

//要求传入参数地址
void ThreadMain(void *para)
{
	int *p = (int *)para;
	cout << *p << endl;

	_endthread();
}

int main()
{
	int i = 1234;
	_beginthread(ThreadMain, 0, &i);
		/*
		(_In_ void (__cdecl * _StartAddress) (void *),_In_ unsigned _StackSize, _In_opt_ void * _ArgList)
			1. __cdcel 说明为普遍函数，
			2. 栈空间大小，默认值0
			3. 传递的参数（地址）
		*/
	
	getchar();
	return 0;

}