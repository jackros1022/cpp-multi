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
	// 打开文件和显示文件大小不同
	QImage simg;
	if (img->width()>img->height())
	{
		simg = img->scaledToWidth(ui.view->width());
	}
	else
	{
		simg = img->scaledToHeight(ui.view->height());
	}

	//显示图片
	ui.view->setPixmap(QPixmap::fromImage(simg));


}
void Ximage::Deal()
{
	float b = (float)ui.bright->value() / 100;
	int thread = ui.thread->value();

	if (!img) return;
	imgDeal = img->copy();

	unsigned char *data = imgDeal.bits();	//像素字节数
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
	sprintf(buf, "%d毫秒", ms);
	ui.dealtime->setText(QString::fromLocal8Bit(buf));

	//QThread::msleep(1000); 
	/*
	因为线程处理完后，立刻显示。
	而实际上，某个线程可能还没有处理完，因此需要wait()等待。
	此处没有用等待，而是直接使用sleep等待
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
		QString::fromLocal8Bit("选择图片"));

	if (filename.isEmpty())
	{
		return;
	}
	/*
	Q: 为什么提前去删除img？
	A： 每次打开文件，总会保留上一次打开的文件。提前删除效率较高
	*/
	if (!img)
	{
		delete img;
		img = NULL;
	}
	img = new QImage(filename); //打开文件
	if (!img)
	{
		return;
	}
	viewImage(img);

}
