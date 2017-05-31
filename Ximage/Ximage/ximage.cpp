#include "ximage.h"
#include "imageThread.h"
#include <qfiledialog.h>
#include <QTime>

Ximage::Ximage(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

Ximage::~Ximage()
{

}

void Ximage::viewImage(QImage *img)
{
	// ���ļ�����ʾ�ļ���С��ͬ
	QImage simg;
	if (img->width()>img->height())
	{
		simg = img->scaledToWidth(ui.view->width());
	}
	else
	{
		simg = img->scaledToHeight(ui.view->height());
	}

	//��ʾͼƬ
	ui.view->setPixmap(QPixmap::fromImage(simg));


}
void Ximage::Deal()
{
	float b = (float)ui.bright->value() / 100;
	int thread = ui.thread->value();

	if (!img) return;
	imgDeal = img->copy();

	unsigned char *data = imgDeal.bits();	//�����ֽ���
	int pixCount = img->width()*img->height();
	QTime t;
	t.start();
	//----------------
	imageThread::dealImage(data, pixCount, b, thread);
	for (;;)
	{
		int percent = imageThread::dealPrecent();
		ui.progress->setValue(percent);

		if (percent >= 100)
			break;
	}

	imageThread::Wait();
	int ms = t.elapsed();
	char buf[128] = { 0 };
	sprintf(buf, "%d����", ms);
	ui.dealtime->setText(QString::fromLocal8Bit(buf));

	//QThread::msleep(1000); 
	/*
	��Ϊ�̴߳������������ʾ��
	��ʵ���ϣ�ĳ���߳̿��ܻ�û�д����꣬�����Ҫwait()�ȴ���
	�˴�û���õȴ�������ֱ��ʹ��sleep�ȴ�
	*/

	//----------------
	//for (int i = 0; i < pixCount; i++)
	//{
	//	int B = data[i * 4] * b;
	//	int G = data[i * 4 + 1] * b;
	//	int R = data[i * 4 + 2] * b;
	//	if (B > 255) B = 255;
	//	if (G > 255) G = 255;
	//	if (R > 255) R = 255;
	//	data[i * 4] = B;
	//	data[i * 4 + 1] = G;
	//	data[i * 4 + 2] = R;
	//}
	viewImage(&imgDeal);

}
void Ximage::Open()
{
	QString filename = QFileDialog::getOpenFileName(this,
		QString::fromLocal8Bit("ѡ��ͼƬ"));

	if (filename.isEmpty())
	{
		return;
	}
	/*
	Q: Ϊʲô��ǰȥɾ��img��
	A�� ÿ�δ��ļ����ܻᱣ����һ�δ򿪵��ļ�����ǰɾ��Ч�ʽϸ�
	*/
	if (!img)
	{
		delete img;
		img = NULL;
	}
	img = new QImage(filename); //���ļ�
	if (!img)
	{
		return;
	}
	viewImage(img);

}
