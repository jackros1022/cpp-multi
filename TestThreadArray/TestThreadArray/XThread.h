#pragma once
class XThread
{
public:
	bool Start();
	void Wait(); //�ȴ��߳̽���

	virtual void Main() = 0; 
	/*
	Q: ���崿�麯����Ŀ�ģ����麯�������ã�
	A: ������û��Զ���ĺ���
	*/
	XThread();
	~XThread();

private:
	unsigned int th = 0; //�ȴ��߳̽�������Ҫ�߳̾��
};

