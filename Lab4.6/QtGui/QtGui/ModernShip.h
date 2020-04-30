#pragma once

#include <QMainWindow>
#include "ui_ModernShip.h"
#include <string>
#include "qvalidator.h"
//#include "Variable.h"
using std::string;

class ModernShip : public QMainWindow
{
	Q_OBJECT

public:
	ModernShip(QWidget *parent = Q_NULLPTR);
	~ModernShip();
	//void setConvoy(lab4::Convoy& convoy) { this->convoy = convoy; }
	void setindex(int index) { this->index = index; }
	void sett();
	QString toQ(const string& a);
	void add_box(int q);
	string fromQ(const QString& a);

private:
	Ui::ModernShip ui;
	QIntValidator IntVal;
	QDoubleValidator DoubleVal;
	//lab4::Convoy convoy;
	int index;
private slots:
void changedata();
void changeguns();
};
