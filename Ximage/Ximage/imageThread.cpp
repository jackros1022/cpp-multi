/*
����һ���Ȱ��̴߳���ã�Ȼ������������̡߳�Ч�ʸߣ��鷳

��������ÿ�����¿��̣߳�ȥ����
*/
#include "imageThread.h"
#include <vector>
using namespace std;

static vector<imageThread*> threads;
/*
�����̶߳���
Q: ����ָ�����ͺͷ�ָ�����͵�����

A: ֱ�ӱ����������漰�����������������
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
		cur = i; //��ǰ����λ���ƶ�һ��
	}
	
}

void imageThread::dealImage(unsigned char*img, unsigned int size,
							float bright, int threadCount)
{
	/*
	���ȴ�����һ���������߳�
	*/
	for (int i = 0; i < threads.size(); i++)
	{
		threads[i]->wait();
		delete threads[i];
	}
	threads.clear();

	int tsize = size / threadCount; 
	//�����߳�
	for (int i = 0; i < threadCount; i++)
	{
		imageThread *th = new imageThread();
		th->begin = i*tsize;
		th->end = th->begin + tsize;
		th->img = img; //ͼ�񴫽���
		th->bright = bright; //����
		if (i == threadCount - 1)	//���ǵ�ֵ�����
		{
			th->end = size - 1;
		}

		threads.push_back(th);
	}
	
	// �����߳�
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
	if (total == 0) return 0; //����totalһ��Ҫ��total���
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