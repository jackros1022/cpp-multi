#pragma once
class XThread
{
public:
	bool Start();

	virtual void Main() = 0; 
	/*
	Q: ���崿�麯����Ŀ�ģ����麯�������ã�
	A: ������û��Զ���ĺ���
	*/
	XThread();
	~XThread();
};

