#pragma once
class XThread
{
public:
	bool Start();
	void Wait(); //等待线程结束

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

