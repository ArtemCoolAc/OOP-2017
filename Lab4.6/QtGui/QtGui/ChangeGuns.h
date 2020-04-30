#pragma once

#include <QMainWindow>
#include "ui_ChangeGuns.h"
#include "..\Library\Convoy.h"
#include "qvalidator.h"
//#include "Variable.h"
using lab4::Ship;
class ChangeGuns : public QMainWindow
{
	Q_OBJECT

public:
	ChangeGuns(QWidget *parent = Q_NULLPTR);
	~ChangeGuns();
	void setShip(Ship* ship) { this->ship = ship; }
	void setGunInd(int index) { this->Gind = index; }
	void sett(int index);
	QString toQ(const string& a);
	string FromQ(const QString& a);
	void add_box();

private:
	Ui::ChangeGuns ui;
	Ship* ship;
	int Gind;
	QIntValidator IntVal;
	QDoubleValidator DoubleVal;
private slots:
void saveGuns();
};
