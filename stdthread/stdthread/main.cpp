#include <iostream>
#include <thread>
#include <mutex>
#include <windows.h>
using namespace std;

static int ticks = 100;
static mutex mu;



class SaleTick
{
public:
	void Main()
	{
		cout << "In saletick" << id << endl;
		for (;;)
		{
			mu.lock();
			if (ticks <= 0)
			{
				mu.unlock(); //²»ÒªÍü¼Ç£¬±ÜÃâËÀËø
				break;
			}
			ticks--;
			mu.unlock();
			sale++;
			Sleep(1);
		}
	}
	int sale = 0;
	int id = 0;

};

int main()
{
	SaleTick st1;
	st1.id = 9;
	SaleTick st2;
	st2.id = 8;

	thread th1(&SaleTick::Main, &st1);
	Sleep(20);
	thread th2(&SaleTick::Main, &st2);

	//th1.detach();
	//th2.detach();

	th1.join();
	th2.join();
	cout << "st1 sales " << st1.sale << " st2 sales" << st2.sale << endl;

	getchar();
	return 0;
}