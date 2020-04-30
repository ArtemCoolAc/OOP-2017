#include "ModernShip.h"
#include "..\Library\Consts.h"
#include "qtextcodec.h"
#include "qinputdialog.h"
#include "ChangeGuns.h"
#include "Variable.h"
#include "qmessagebox.h"
using namespace lab4;

ModernShip::ModernShip(QWidget *parent)
	: QMainWindow(parent), IntVal(0, INT_MAX, this), DoubleVal(0, std::numeric_limits<double>::max(), 5, this)
{
	ui.setupUi(this);
	QLocale locale(QLocale::English);
	DoubleVal.setLocale(locale);
	DoubleVal.setNotation(QDoubleValidator::ScientificNotation);
	ui.Draught->setValidator(&IntVal);
	ui.Quan->setValidator(&IntVal);
	ui.Max_Speed->setValidator(&DoubleVal);
	ui.Mass->setValidator(&DoubleVal);
	ui.Exp->setValidator(&IntVal);
	//connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(changedata()));
	setWindowTitle(QString::fromLocal8Bit("Модификация корабля"));
	setWindowIcon(QIcon("Icon.png"));
	connect(ui.buttonBox, SIGNAL(accepted()), this, SLOT(changedata()));
	connect(ui.buttonBox, SIGNAL(rejected()), this, SLOT(close()));
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(changeguns()));
}

void ModernShip::sett()
{
	Table& tab = convoy.getTable();
	int type = tab.cur(index)->ship->getType();
	Ship* ship = tab.cur(index)->ship;
	int dra = ship->getDra();
	QString v;
	v.setNum(dra);
	ui.Draught->setText(v);
	int q = ship->getQuan();
	v.setNum(q);
	ui.Quan->setText(v);
	double max = ship->getMax();
	v.setNum(max);
	ui.Max_Speed->setText(v);
	string sname = ship->getShipName();
	QString a = toQ(sname);
	ui.Ship_Name->setText(a);
	string fam = ship->getCapFamily();
	a = toQ(fam);
	ui.Family->setText(a);
	string nam = ship->getCapName();
	a = toQ(nam);
	ui.Name->setText(a);
	string patr = ship->getCapPatronymic();
	a = toQ(patr);
	ui.Patr->setText(a);
	string rank = ship->getCapRank();
	a = toQ(rank);
	ui.Rank->setText(a);
	int exp = ship->getCapExperience();
	v.setNum(exp);
	ui.Exp->setText(v);
	if ((type == 1) || (type == 3)) {
		Guard* ship1 = dynamic_cast<Guard*> (ship);
		int qg = ship1->getVec().size();
		add_box(qg);
	}
	if (type == 1) {
		ui.label_11->hide();
		ui.Mass->hide();
	}
	if (type == 2) {
		ui.comboBox->hide();
		ui.pushButton->hide();
		Transport* ship1 = dynamic_cast<Transport*> (ship);
		double mass = ship1->getMass();
		v.setNum(mass);
		ui.Mass->setText(v);
	}
	if (type == 3) {
		Warship* ship1 = dynamic_cast<Warship*> (ship);
		double mass = ship1->getMass();
		v.setNum(mass);
		ui.Mass->setText(v);
	}
}

QString ModernShip::toQ(const string& a)
{
	QTextCodec* codec = QTextCodec::codecForName("CP 1251");
	const char* s = a.c_str();
	QString t = codec->toUnicode(s, strlen(s));
	return t;
}

void ModernShip::add_box(int q)
{
	QList<QString> list;
	QString str;
	for (int i = 0; i < q; ++i) {
		str.setNum(i);
		list << str;
	}
	ui.comboBox->addItems(list);
}

void ModernShip::changedata()
{
	Ship* ship = convoy.getTable().cur(index)->ship;
	int type = ship->getType();
	try {
		if ((ui.Draught->text().isEmpty()) || (ui.Quan->text().isEmpty()) || (ui.Max_Speed->text().isEmpty()) || (ui.Ship_Name->text().isEmpty()) || (ui.Family->text().isEmpty()) || (ui.Name->text().isEmpty()) || (ui.Patr->text().isEmpty()) || (ui.Rank->text().isEmpty()) || (ui.Exp->text().isEmpty())) throw std::invalid_argument("Заполните все пустые поля!");
		if (!(ui.Draught->text().isEmpty())) ship->setDra(ui.Draught->text().toInt());
		if (!(ui.Quan->text().isEmpty())) ship->setQuan(ui.Quan->text().toInt());
		if (!(ui.Max_Speed->text().isEmpty())) ship->setMax(ui.Max_Speed->text().toDouble());
		if (!(ui.Ship_Name->text().isEmpty())) ship->setShipName(fromQ(ui.Ship_Name->text()));
		if (!(ui.Family->text().isEmpty())) ship->setFamily(fromQ(ui.Family->text()));
		if (!(ui.Name->text().isEmpty())) ship->setName(fromQ(ui.Name->text()));
		if (!(ui.Patr->text().isEmpty())) ship->setPatronymic(fromQ(ui.Patr->text()));
		if (!(ui.Rank->text().isEmpty())) ship->setRank(fromQ(ui.Rank->text()));
		if (!(ui.Exp->text().isEmpty())) ship->setExperience(ui.Exp->text().toInt());
		if ((type == 2) || (type == 3)) {
			Transport* ship1 = dynamic_cast<Transport*> (ship);
			if (ui.Mass->text().isEmpty()) std::invalid_argument("Заполните все пустые поля!");
			if (!(ui.Mass->text().isEmpty())) ship1->setMass(ui.Mass->text().toDouble());
			ship1->Speed();
			convoy.getTable().setShip(ship1, index);
		}
		else {
			convoy.getTable().setShip(ship, index);
		}
		close();
	}
	catch (std::exception& ex) {
		string a(ex.what());;
		QString b = toQ(a);
		QMessageBox* pmbx =
			new QMessageBox; pmbx->setText(b);
		pmbx->setWindowIcon(QIcon("Icon.png"));
		pmbx->setWindowTitle(QString::fromLocal8Bit("Ошибочка вышла!"));
		pmbx->setIcon(QMessageBox::Icon::Warning);
		pmbx->exec();
	}
}

string ModernShip::fromQ(const QString& a)
{
	QTextCodec* codec = QTextCodec::codecForName("CP 1251");
	QByteArray st = codec->fromUnicode(a);
	string v = st.toStdString();
	return v;
}

void ModernShip::changeguns()
{
	int ind = ui.comboBox->currentIndex();
	ChangeGuns* g = new ChangeGuns;
	Ship* ship = convoy.getTable().cur(index)->ship;
	g->setShip(ship);
	g->sett(ind);
	g->show();

}


ModernShip::~ModernShip()
{
}
