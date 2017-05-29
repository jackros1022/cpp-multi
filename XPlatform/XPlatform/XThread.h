#pragma once

#ifdef XPLATFORM_EXPORTS
#define XPLATFORM_API __declspec(dllexport)
#else
#define XPLATFORM_API __declspec(dllimport)
#endif

/*
Q: dllexport与dllimport啥区别？

T: 自己定义动态库文件，一定要添加 XPLATFORM_API。否则无法加载
*/
class XPLATFORM_API XThread
{
public:
	bool Start();
	void Wait(); //等待线程结束

	void Suspend();	//挂起
	void Resume();	//恢复

	virtual void Main() = 0; 
	/*
	Q: 定义纯虚函数的目的？纯虚函数的作用？
	A: 会调用用户自定义的函数
	*/
	XThread();
	~XThread();

private:
	unsigned int th = 0; //等待线程结束，需要线程句柄
};

