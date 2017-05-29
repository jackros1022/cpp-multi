#pragma once

#ifdef XPLATFORM_EXPORTS
#define XPLATFORM_API __declspec(dllexport)
#else
#define XPLATFORM_API __declspec(dllimport)
#endif

/*
Q: dllexport��dllimportɶ����

T: �Լ����嶯̬���ļ���һ��Ҫ��� XPLATFORM_API�������޷�����
*/
class XPLATFORM_API XThread
{
public:
	bool Start();
	void Wait(); //�ȴ��߳̽���

	void Suspend();	//����
	void Resume();	//�ָ�

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

