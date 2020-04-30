#pragma once

#include <QMainWindow>
#include "ui_NewShip.h"
//#include "Variable.h"
#include "..\Library\Armament_Description.h"
#include "..\Library\Convoy.h"
#include "qvalidator.h"
using vctr::vector;
//using lab4::Armament_Description;

class NewShip : public QMainWindow
{
	Q_OBJECT

public:
	NewShip(QWidget *parent = Q_NULLPTR);
	~NewShip();
	//void setElem(lab4::Element& el) { this->el = el; }
	//lab4::Element getElem(){ return el; }
	void setShip(lab4::Ship* ship) { this->ship = ship; }
	//void setConvoy(lab4::Convoy& convoy) { this->convoy = convoy; }
	//lab4::Convoy& getConvoy() { return convoy; }
	void add_box();
	QString toQ(const string& a);
	string fromQ(const QString&a);
	void hid(int type);
	signals:
	void closewin();

private:
	Ui::NewShip ui;
	lab4::Element el;
	//lab4::Convoy convoy;
	lab4::Ship* ship;
	vector<lab4::Armament_Description> guns;
	QIntValidator IntVal;
	QDoubleValidator DoubleVal;
	private slots:
	lab4::Element read();
	void readgun();
	//void to();
};
