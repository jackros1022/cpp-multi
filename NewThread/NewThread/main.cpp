#include <process.h>
#include <iostream>

using namespace std;

//Ҫ���������ַ
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
			1. __cdcel ˵��Ϊ�ձ麯����
			2. ջ�ռ��С��Ĭ��ֵ0
			3. ���ݵĲ�������ַ��
		*/
	
	getchar();
	return 0;

}