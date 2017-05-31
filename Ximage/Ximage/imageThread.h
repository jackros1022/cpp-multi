#pragma once
#include <qthread.h>

class imageThread:public QThread
{
public:
	imageThread();
	~imageThread();

	/*处理图片
	1.可以设置阻塞和
	2.非阻塞函数
	采用2。但是无法知道函数处理成功结束
	*/

	static void dealImage(unsigned char*img, unsigned int size, 
							float bright,int threadCount);
	static void Wait();
	//处理进度
	static int dealPrecent();

	/*
	Tips: 使用Qt线程需要自己定义run重载函数
	*/
	void run();

	/*处理时间
	1.内部处理好
	2.调用的时候。进行时间处理

	采用2
	
	*/

public:
	unsigned int begin = 0;
	unsigned int end = 0;
	unsigned int cur = 0;

	unsigned char* img = NULL; //像素字节数
	float bright = 1;
};

