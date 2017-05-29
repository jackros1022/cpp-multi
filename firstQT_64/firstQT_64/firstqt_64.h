#ifndef FIRSTQT_64_H
#define FIRSTQT_64_H

#include <QtWidgets/QMainWindow>
#include "ui_firstqt_64.h"

class firstQT_64 : public QMainWindow
{
	Q_OBJECT

public:
	firstQT_64(QWidget *parent = 0);
	~firstQT_64();

private:
	Ui::firstQT_64Class ui;
};

#endif // FIRSTQT_64_H
