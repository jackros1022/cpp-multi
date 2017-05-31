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
	Tips�� void viewImage(QImage *img);�����ĺ���ֻ���ڲ۵��з���
	�����߳��в��ܷ��ʡ����߳��з��ʣ�ֻ�ܵ����źţ��źſɶ��̷߳���
	����ֻ�ܵ��̷߳��ʡ�
	
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
