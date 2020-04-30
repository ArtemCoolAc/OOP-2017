#include "QtGui.h"
#include "..\Library\Consts.h"
#include "qtextcodec.h"
#include "Variable.h"
using namespace lab4;
Convoy convoy;

QtGui::QtGui(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
	setWindowTitle(QString::fromLocal8Bit("Конвой"));
	setWindowIcon(QIcon("Icon.png"));
	connect(ui.pushButton, SIGNAL(ui.pushButton->clicked()), this, SLOT(hide()));
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(newconvoy()));
}

QString QtGui::on_convoy_button_clicked()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",
		tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));
	return fileName;
}

QString QtGui::on_pushButton_clicked()
{
	QString path = on_convoy_button_clicked();
	file_opened(path);
	return path;
}

void QtGui::file_opened(QString path)
{
	QTextCodec* codec = QTextCodec::codecForName("CP 1251");
	QByteArray st = codec->fromUnicode(path);
	string path1 = st.toStdString();
	convoy.ReadFromFile(path1);
	menu = new ConvoyMenu(NULL);
	menu->add_box();
	menu->add_box2();
	menu->show();
	hide();
}

void QtGui::newconvoy()
{
	menu = new ConvoyMenu(NULL);
	menu->show();
	hide();
}


void QtGui::exit()
{
	delete menu;
	QApplication::exit();
}