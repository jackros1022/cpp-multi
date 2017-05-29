#include "stdafx.h"
#include "XMutex.h"


XMutex::XMutex()
{
	//初始化临界区变量
	this->section = new CRITICAL_SECTION();
	InitializeCriticalSection((CRITICAL_SECTION*)this->section);
}
void XMutex::lock()
{
	EnterCriticalSection((CRITICAL_SECTION*)this->section);

}

void XMutex::unlock()
{
	LeaveCriticalSection((CRITICAL_SECTION*)this->section);

}

XMutex::~XMutex()
{
}
