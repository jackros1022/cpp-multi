#include <iostream>
using namespace std;
#include "XThread.h"
#include <Windows.h>

static char* arr = NULL;
/*
T: һ�㲻����ʹ��ȫ�ֱ��������Ľ�������ʹ��
*/

class MyThread :public XThread
{
public:
	int b = 0;
	int e = 0;
	void Main()
	{
		for (int i = b; i < e; i++)
		{
			arr[i] = i;
		}
	}
	/*
	Q: ��ô֪����ǰ�߳̽������Լ�֪����������Σ�
	A��ֱ�ӵ���ϵͳ��api������֪��������ʱ��������
	*/
};


int main()
{
	int size = 1000 * 1000 * 1000;
	arr = new char[size];
	int tsize = 8;
	MyThread* ths = new MyThread[tsize];	//����4���̶߳���

	long long start = GetTickCount();
	//for (int i = 0; i < size; i++)
	//{
	//	arr[i] = i;
	//}

	for (int i = 0; i < tsize; i++)
	{
		ths[i].b = i*(size / tsize);
		ths[i].e = ths[i].b + (size / tsize);
		if (ths[i].e >= size)
		{
			ths[i].e = size - 1;
		}
		ths[i].Start();
	}
	for (int i = 0; i < tsize; i++)
	{
		ths[i].Wait();
	}


	long long end = GetTickCount();
	cout << "main deal (ms): " << end-start << endl;

	getchar();

	return 0;

}