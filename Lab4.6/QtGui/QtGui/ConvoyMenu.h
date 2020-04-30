#pragma once

#include <QMainWindow>
#include "ui_ConvoyMenu.h"
//#include "..\Library\Convoy.h"
//#include "Variable.h"
#include "NewShip.h"
#include "Sea.h"
#include "Input2Index.h"
#include "qvalidator.h"

class ConvoyMenu : public QMainWindow
{
	Q_OBJECT

public:
	ConvoyMenu(QWidget *parent = Q_NULLPTR);
	~ConvoyMenu();
	//void setConvoy(lab4::Convoy& convoy) { this->convoy = convoy; } 
	//lab4::Convoy& getConvoy() { return convoy; }
	void add_box();
	void add_box2();
	QString toQ(const string& a);
	string fromQ(const QString&a);
	QString save_in_file();

protected:
	void closeEvent(QCloseEvent* e);

private:
	Ui::ConvoyMenu ui;
	//lab4::Convoy convoy;
	lab4::Ship* ship;
	NewShip* sh;
	Sea* sea;
	Input2Index * mod;
	QDoubleValidator DoubleVal;

private slots:
int index();
void on_pushButton_clicked();
void on_pushButton_2_clicked();
void quan();
void dist();
void include();
void inputdouble(int*);
void add_gun();
void add_elem();
void start();
void save_convoy();
void delete_ship();
void modern();
};
