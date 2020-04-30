#pragma once

#include <QMainWindow>
#include "ui_InfoShip.h"
//#include "Variable.h"

class InfoShip : public QMainWindow
{
	Q_OBJECT

public:
	InfoShip(QWidget *parent = Q_NULLPTR);
	~InfoShip();
	void setindex(int index) { this->index = index; }
	//void setconvoy(lab4::Convoy& convoy) { this->convoy = convoy; }
	void sett();
	void add_box(int q);

private:
	Ui::InfoShip ui;
	int index;
	//lab4::Convoy convoy;
private slots:
void ShowGun(int);
};
