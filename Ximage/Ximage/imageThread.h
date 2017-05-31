#pragma once
#include <qthread.h>

class imageThread:public QThread
{
public:
	imageThread();
	~imageThread();

	/*����ͼƬ
	1.��������������
	2.����������
	����2�������޷�֪����������ɹ�����
	*/

	static void dealImage(unsigned char*img, unsigned int size, 
							float bright,int threadCount);
	static void Wait();
	//�������
	static int dealPrecent();

	/*
	Tips: ʹ��Qt�߳���Ҫ�Լ�����run���غ���
	*/
	void run();

	/*����ʱ��
	1.�ڲ������
	2.���õ�ʱ�򡣽���ʱ�䴦��

	����2
	
	*/

public:
	unsigned int begin = 0;
	unsigned int end = 0;
	unsigned int cur = 0;

	unsigned char* img = NULL; //�����ֽ���
	float bright = 1;
};

