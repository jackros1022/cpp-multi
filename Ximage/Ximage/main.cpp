#include "ximage.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Ximage w;
	w.show();
	return a.exec();
}
