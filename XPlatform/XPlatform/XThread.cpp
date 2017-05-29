#include "XThread.h"
#include <process.h> 
#include <Windows.h>

/*
Q：为什么没有放到头文件？#include <process.h>

A： 用户看不到，也就是说cpp文件修改变动，只要函数接口不变，对用户就没有影响
*/

/*
Q: 为什么使用静态函数？ static void ThreadMain（）

A: 静态函数只在本cpp文件有效，其它文件有同名函数不会冲突。

*/
static void ThreadMain(void *para)
{
	XThread* th = (XThread*)para;
	th->Main();	//用户自定义函数
	/*
	Q： Main()为纯虚构函数的作用？
	A： 否则，只能访问到当前类的函数。定为虚构函数就可以访问到用户定义的函数
	*/
	_endthread();
}

bool XThread::Start()
{
	th = _beginthread(ThreadMain, 0, this);
	/*
		Q: this指针如何理解？

		A： 
			1. this参数，首先是_beginthread（）用户传递的参数。
			2. 通过成员传递参数，也就是使用this指针（非静态类才有）。因为this指针指向当前类对象的首地址，
				也即是基类XThread的首地址和继承类的首地址相同。使用this就可以把参数传递给继承类。

		Q：继承类和基类的地址关系？
		
		A：基类地址在最上面，继承类在下面，再有继承的下面依次排列。
	*/ 
	if (((int)th) <= 0)
	{
		return false;
	}
	return true;
}
void XThread::Wait()
{
	if (th == 0)return;
	WaitForSingleObject((HANDLE)th, INFINITE); //阻塞函数
}

void XThread::Suspend()
{
	if (th == 0) return;
	SuspendThread((HANDLE)th);
}

void XThread::Resume()
{
	if (th == 0) return;
	ResumeThread((HANDLE)th);

}

XThread::XThread()
{
}


XThread::~XThread()
{
}
