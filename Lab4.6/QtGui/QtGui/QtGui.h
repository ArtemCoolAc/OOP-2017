#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtGui.h"
#include "qfiledialog.h"
#include "ConvoyMenu.h"
//#include "Variable.h"

class QtGui : public QMainWindow
{
	Q_OBJECT

public:
	QtGui(QWidget *parent = Q_NULLPTR);
	void OpenFile();
	void exit();
	QString on_convoy_button_clicked();
private:
	Ui::QtGuiClass ui;
	ConvoyMenu* menu;
	//ConvoyMenu* menu;
	//lab4::Convoy convoy;
private slots:
	QString on_pushButton_clicked();
	void file_opened(QString);
	void newconvoy();
};
