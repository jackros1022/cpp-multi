#include "XThread.h"
#include <process.h> 
#include <Windows.h>

/*
Q��Ϊʲôû�зŵ�ͷ�ļ���#include <process.h>

A�� �û���������Ҳ����˵cpp�ļ��޸ı䶯��ֻҪ�����ӿڲ��䣬���û���û��Ӱ��
*/

/*
Q: Ϊʲôʹ�þ�̬������ static void ThreadMain����

A: ��̬����ֻ�ڱ�cpp�ļ���Ч�������ļ���ͬ�����������ͻ��

*/
static void ThreadMain(void *para)
{
	XThread* th = (XThread*)para;
	th->Main();
	/*
	Q�� Main()Ϊ���鹹���������ã�
	A�� ����ֻ�ܷ��ʵ���ǰ��ĺ�������Ϊ�鹹�����Ϳ��Է��ʵ��û�����ĺ���
	*/
	_endthread();
}

bool XThread::Start()
{
	th = _beginthread(ThreadMain, 0, this);
	/*
		Q: thisָ�������⣿

		A�� 
			1. this������������_beginthread�����û����ݵĲ�����
			2. ͨ����Ա���ݲ�����Ҳ����ʹ��thisָ�루�Ǿ�̬����У�����Ϊthisָ��ָ��ǰ�������׵�ַ��
				Ҳ���ǻ���XThread���׵�ַ�ͼ̳�����׵�ַ��ͬ��ʹ��this�Ϳ��԰Ѳ������ݸ��̳��ࡣ

		Q���̳���ͻ���ĵ�ַ��ϵ��
		
		A�������ַ�������棬�̳��������棬���м̳е������������С�
	*/
	if (((int)th) <= 0)
	{
		return false;
	}
	return true;
}
void XThread::Wait()
{
	WaitForSingleObject((HANDLE)th, INFINITE); //��������
}

XThread::XThread()
{
}


XThread::~XThread()
{
}
