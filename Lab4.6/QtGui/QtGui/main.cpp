#include "QtGui.h"
#include <QtWidgets/QApplication>
#include "qtextcodec.h"


int main(int argc, char *argv[])
{
	QTextCodec* codec = QTextCodec::codecForName("CP 1251");
	QApplication a(argc, argv);
	QtGui w;
	w.show();
	return a.exec();
}
