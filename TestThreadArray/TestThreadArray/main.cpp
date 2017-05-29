#include <iostream>
using namespace std;
#include "XThread.h"
#include <Windows.h>

static char* arr = NULL;
/*
T: 一般不建议使用全局变量，本文仅作测试使用
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
	Q: 怎么知道当前线程结束，以及知道结束该如何？
	A：直接调用系统的api函数，知道结束的时候并阻塞。
	*/
};


int main()
{
	int size = 1000 * 1000 * 1000;
	arr = new char[size];
	int tsize = 8;
	MyThread* ths = new MyThread[tsize];	//创建4个线程对象

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