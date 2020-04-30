#include "ConvoyMenu.h"
#include "InfoShip.h"
#include "ModernShip.h"
#include "qinputdialog.h"
#include "qfiledialog.h"
#include "qtextcodec.h"
#include "NewShip.h"
#include "..\Library\Guard.h"
#include "..\Library\Transport.h"
#include "..\Library\Warship.h"
#include "Sea.h"
#include "qmessagebox.h"
#include "Variable.h"
using namespace lab4;
//#include "..\Library\Consts.h"

ConvoyMenu::ConvoyMenu(QWidget *parent)
	: QMainWindow(parent), DoubleVal(0, std::numeric_limits<double>::max(), 5, this)
{
	ui.setupUi(this);
	QLocale locale(QLocale::English);
	DoubleVal.setLocale(locale);
	DoubleVal.setNotation(QDoubleValidator::ScientificNotation);
	ui.lineEdit_2->setValidator(&DoubleVal);
	sh = new NewShip;
	sea = new Sea;
	setWindowTitle(toQ("Меню конвоя"));
	setWindowIcon(QIcon("Icon.png"));
	//connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(on_pushButton_2_clicked));
	connect(ui.pushButton_3, SIGNAL(clicked()), this, SLOT(quan()));
	connect(ui.pushButton_4, SIGNAL(clicked()), this, SLOT(modern()));
	connect(ui.pushButton_5, SIGNAL(clicked()), this, SLOT(dist()));
	connect(ui.pushButton_7, SIGNAL(clicked()), this, SLOT(include()));
	connect(ui.pushButton_8, SIGNAL(clicked()), this, SLOT(save_convoy()));
	connect(ui.pushButton_9, SIGNAL(clicked()), this, SLOT(start()));
	connect(ui.pushButton_10, SIGNAL(clicked()), this, SLOT(delete_ship()));
	connect(sea, SIGNAL(close()), this, SLOT(sea.~Sea()));
	connect(sh, SIGNAL(closewin()), this, SLOT(add_elem()));
	ui.pushButton_6->hide();
}

void ConvoyMenu::add_box()
{
	QList<QString> list;
	int n = convoy.size(); QString str;
	for (int i = 0; i < n; ++i) {
		str.setNum(i);
		list << str;
	}
	ui.comboBox->addItems(list);
}

void ConvoyMenu::on_pushButton_clicked()
{
	int t = convoy.size();
	if (t == 0) {
		string a = "Конвой пуст!"; QString b = toQ(a);
		QMessageBox* pmbx =
			new QMessageBox;
		pmbx->setText(b);
		pmbx->setIcon(QMessageBox::Warning);
		pmbx->setWindowTitle(toQ("Ошибка!"));
		pmbx->setWindowIcon(QIcon("Icon.png"));
		pmbx->exec();
		delete pmbx;
	}
	else {
		int ind = index();
		InfoShip* sh = new InfoShip(NULL);
		sh->setindex(ind);
		sh->sett();
		sh->show();
	}
}

void ConvoyMenu::on_pushButton_2_clicked()
{
	int t = convoy.size();
	if (t == 0) {
		string a = "Конвой пуст!"; QString b = toQ(a);
		QMessageBox* pmbx =
			new QMessageBox;
		pmbx->setText(b);
		pmbx->setIcon(QMessageBox::Warning);
		pmbx->setWindowTitle(toQ("Ошибка!"));
		pmbx->setWindowIcon(QIcon("Icon.png"));
		pmbx->exec();
	}
	else {
		int ind = index();
		ModernShip* m = new ModernShip(NULL);
		m->setindex(ind);
		m->sett();
		m->show();
	}
}

int ConvoyMenu::index()
{
	int index = ui.comboBox->currentIndex();
	return index;
}

void ConvoyMenu::inputdouble(int* dou)
{
	bool bOk;
	QString str = QInputDialog::getText(0,
		"Input",
		"double:",
		QLineEdit::Normal,
		"",
		&bOk
		);
	if (!bOk) {
		// Была нажата кнопка Cancel 
	}
	*dou = str.toDouble();

}

void ConvoyMenu::add_box2()
{
	QList<QString> list;
	string s1 = "Охранное"; string s2 = "Транспортное"; string s3 = "Военное";
	QString ss1, ss2, ss3;
		ss1 = toQ(s1);
		ss2 = toQ(s2);
		ss3 = toQ(s3);
		list << ss1; list << ss2; list << ss3;
	ui.comboBox_2->addItems(list);
}

QString ConvoyMenu::toQ(const string& a)
{
	QTextCodec* codec = QTextCodec::codecForName("CP 1251");
	const char* s = a.c_str();
	QString t = codec->toUnicode(s, strlen(s));
	return t;
}

void ConvoyMenu::quan()
{
	int t = convoy.size();
	if (t == 0) {
		string a = "Конвой пуст!"; QString b = toQ(a);
		QMessageBox* pmbx =
			new QMessageBox; pmbx->setText(b);
		pmbx->exec();
		delete pmbx;
	}
	else {
		int ind = ui.comboBox_2->currentIndex();
		int type = ind + 1;
		int q = convoy.count(type);
		QString s;
		s.setNum(q);
		ui.lineEdit->setText(s);
	}
}

void ConvoyMenu::dist()
{
	QMessageBox* pmbx = new QMessageBox;
	pmbx->setWindowTitle(QString::fromLocal8Bit("Груз"));
	pmbx->setWindowIcon(QIcon("Icon.png"));
	pmbx->setIcon(QMessageBox::Icon::Information);
	int t = convoy.count(2);	
	if (t == 0) {
		string a = "Нет судов транспортного типа - некуда грузить!"; QString b = toQ(a); 
		pmbx->setText(b);
		pmbx->exec();
	}
	else {
		if (!(ui.lineEdit_2->text().isEmpty())) {
			double mass = ui.lineEdit_2->text().toDouble();
			convoy.distribute(mass);
			string a = "Конвой успешно загружен!";
			QString b = toQ(a);
			pmbx->setText(b);
		}
		else {
			string a = "Пустое поле!";
			QString b = toQ(a);
			pmbx->setText(b);
		}		
		pmbx->exec();
		delete pmbx;
	}
}

void ConvoyMenu::include()
{
	int q = convoy.size();
	int ind = ui.comboBox_2->currentIndex();
	int type = ind + 1;
	if (type == 1) ship = new Guard;
	if (type == 2) ship = new Transport;
	if (type == 3) ship = new Warship;
	ship->setType(type);
	sh->hid(type);
	sh->setShip(ship);
	sh->show();
}

void ConvoyMenu::add_elem()
{
	int q = convoy.size();
	Element elem = *convoy.getTable().cur(q-1);
	QString a; 
	a.setNum(q-1);
	ui.comboBox->addItem(a);
}

void ConvoyMenu::start()
{
	
	sea->show();
	sea->add();
}

void ConvoyMenu::add_gun()
{

}

void ConvoyMenu::save_convoy()
{
	QString path = save_in_file();
	string path1 = fromQ(path);
	convoy.Save_Convoy_in_file(path1);
}

QString ConvoyMenu::save_in_file()
{
	QString fileName = QFileDialog::getSaveFileName(this,
		QString::fromLocal8Bit("Сохранить файл"),
		QDir::currentPath(),
		"Text files (*.txt);;All files (*.*)");
	return fileName;
}

string ConvoyMenu::fromQ(const QString& a)
{
	QTextCodec* codec = QTextCodec::codecForName("CP 1251");
	QByteArray st = codec->fromUnicode(a);
	string v = st.toStdString();
	return v;
}

void ConvoyMenu::closeEvent(QCloseEvent* event)
{
	QMessageBox* pmbx =
		new QMessageBox(QString::fromLocal8Bit("Выход из программы"),
		QString::fromLocal8Bit("Хотите ли сохранить текущий конвой в файл?"),
		QMessageBox::Question,
		QMessageBox::Yes,
		QMessageBox::No,
		QMessageBox::Escape);
	pmbx->setWindowIcon(QIcon("Icon.png"));
	int n = pmbx->exec();
	delete pmbx;
	if (n == QMessageBox::Yes)
	{
		QString fileName = QFileDialog::getSaveFileName(this,
			QString::fromLocal8Bit("Сохранить файл"),
			QDir::currentPath(),
			"Text files (*.txt);;All files (*.*)");
		string path = fromQ(fileName);
		convoy.Save_Convoy_in_file(path);
	}
	
}

void ConvoyMenu::delete_ship()
{
	int t = convoy.size();
	if (t == 0) {
		string a = "Конвой пуст!"; QString b = toQ(a);
		QMessageBox* pmbx =
			new QMessageBox; 
		pmbx->setText(b);
		pmbx->setIcon(QMessageBox::Warning);
		pmbx->setWindowTitle(toQ("Ошибка!"));
		pmbx->setWindowIcon(QIcon("Icon.png"));
		pmbx->exec();
		delete pmbx;
	}
	else {
		int ind = index();
		convoy.deleteShip(ind);
		ui.comboBox->clear();
		add_box();
	}
}

void ConvoyMenu::modern()
{
	int q1 = convoy.count(2);
	int q2 = convoy.count(3);
	if ((q1 == 0) || (q2 == 0)) {
		string a = "Нет суден хотя бы одного из типов"; QString b = toQ(a);
		QMessageBox* pmbx =
			new QMessageBox; pmbx->setText(b);
		pmbx->setIcon(QMessageBox::Warning);
		pmbx->setWindowTitle(toQ("Ошибка!"));
		pmbx->setWindowIcon(QIcon("Icon.png"));
		pmbx->exec();
		delete pmbx;
	}
	else {
		mod = new Input2Index;
		mod->fulfill();
		mod->show();
	}
}

ConvoyMenu::~ConvoyMenu()
{
	delete sh;
	delete sea;
}
