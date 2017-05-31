/*
方案一：先把线程处理好，然后把任务分配给线程。效率高，麻烦

方案二：每次重新开线程，去处理
*/
#include "imageThread.h"
#include <vector>
using namespace std;

static vector<imageThread*> threads;
/*
保存线程对象。
Q: 保存指针类型和非指针类型的区别？

A: 直接保存对象可能涉及对象的析构，等问题
*/

imageThread::imageThread()
{
}


imageThread::~imageThread()
{
}

void imageThread::run()
{
	if (!img || begin < 0 || end < 0 || end - begin < 0) return;
	for (int i = begin; i <= end; i++)
	{
		int B = img[i * 4] * bright;
		int G = img[i * 4 + 1] * bright;
		int R = img[i * 4 + 2] * bright;

		if (B > 255) B = 255;
		if (G > 255) G = 255;
		if (R > 255) R = 255;

		img[i * 4] = B;
		img[i * 4 + 1] = G;
		img[i * 4 + 2] = R;
		cur = i; //当前处理位置移动一下
	}
	
}

void imageThread::dealImage(unsigned char*img, unsigned int size,
							float bright, int threadCount)
{
	/*
	首先处理，上一次遗留的线程
	*/
	for (int i = 0; i < threads.size(); i++)
	{
		threads[i]->wait();
		delete threads[i];
	}
	threads.clear();

	int tsize = size / threadCount; 
	//创建线程
	for (int i = 0; i < threadCount; i++)
	{
		imageThread *th = new imageThread();
		th->begin = i*tsize;
		th->end = th->begin + tsize;
		th->img = img; //图像传进来
		th->bright = bright; //亮度
		if (i == threadCount - 1)	//考虑到值溢出。
		{
			th->end = size - 1;
		}

		threads.push_back(th);
	}
	
	// 启动线程
	for (int i = 0; i < threads.size(); i++)
	{
		threads[i]->start();

	}

}

int imageThread::dealPrecent()
{
	int cur = 0;
	int total = 0;
	for (int i = 0; i < threads.size(); i++)
	{
		cur += (threads[i]->cur - threads[i]->begin);
		total += (threads[i]->end - threads[i]->begin);
	}
	if (total == 0) return 0; //除以total一定要对total检查
	int per = cur * 100 / total;
	return per;
}

void imageThread::Wait()
{
	for (int i = 0; i < threads.size(); i++)
	{
		threads[i]->wait();
	}
}