#include <iostream>
#include "XThread.h"
#include "XMutex.h"
#include <Windows.h>

using namespace std;
static char buf[1024] = { 0 };

//CRITICAL_SECTION section;
static XMutex mutex;

class MyThread :public XThread
{
public:
	void Main()
	{
		cout << "In MyThread" << endl;
		for (;;)
		{
			int size = sizeof(buf);
			//EnterCriticalSection(&section);
			mutex.lock();
			for (int i = 0; i < size; i++)
			{
				buf[i] = c;
				Sleep(1);
			}
			buf[size - 1] = '\0';
			cout << "[" << buf << "]" << endl;
			//LeaveCriticalSection(&section);
			mutex.unlock();
			Sleep(1);
		}
		//Sleep(10000);
		
	}
	char c;
};

class TestSus :public XThread
{
public:
	void Main()
	{
		for (;;)
		{
			printf(c);
			Sleep(500);
		}
	
	}
	char* c;
};
int main()
{
	//InitializeCriticalSection(&section);

	//MyThread thread;
	//thread.Start();

	//---------------------------

	MyThread myth1;
	myth1.c = 'A';
	MyThread myth2;
	myth2.c = 'B';

	myth1.Start();
	myth2.Start();

	//---------------------------

	//TestSus t1;
	//t1.c = "t1\n";

	//TestSus t2;
	//t2.c = "t2\n";

	//t1.Start();
	//t2.Start();
	//Sleep(3000);

	//t2.Suspend();

	//Sleep(3000);
	//t2.Resume();



	getchar();
	return 0;

}