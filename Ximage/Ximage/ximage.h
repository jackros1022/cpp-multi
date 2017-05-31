#ifndef XIMAGE_H
#define XIMAGE_H

#include <QtWidgets/QWidget>
#include "ui_ximage.h"

class Ximage : public QWidget
{
	Q_OBJECT

public:
	Ximage(QWidget *parent = 0);
	~Ximage();
	void viewImage(QImage *img);
	/*
	Tips： void viewImage(QImage *img);这样的函数只能在槽当中访问
	，在线程中不能访问。在线程中访问，只能调用信号，信号可多线程访问
	，槽只能单线程访问。
	
	*/

public slots:
	void Open();
	void Deal();

private:
	Ui::XimageClass ui;
	QImage *img = NULL;
	QImage imgDeal;

};

#endif // XIMAGE_H
