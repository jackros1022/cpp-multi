#pragma once
#ifdef XPLATFORM_EXPORTS
#define XPLATFORM_API __declspec(dllexport)
#else
#define XPLATFORM_API __declspec(dllimport)
#endif

class XPLATFORM_API XMutex
{
public:
	void lock();
	void unlock();
	XMutex();
	~XMutex();
private:
	void* section;
	/*
	Q:定义void*类型的section好处？
	A： 任何类型，不用引用头文件。
	*/

};

