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
	Q:����void*���͵�section�ô���
	A�� �κ����ͣ���������ͷ�ļ���
	*/

};

