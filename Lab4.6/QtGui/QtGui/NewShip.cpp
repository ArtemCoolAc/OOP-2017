#include "NewShip.h"
#include "qtextcodec.h"
#include "..\Library\Consts.h"
#include "qmessagebox.h"
#include "Variable.h"
using namespace lab4;

NewShip::NewShip(QWidget *parent)
	: QMainWindow(parent), IntVal(0, INT_MAX, this), DoubleVal(0, std::numeric_limits<double>::max(), 5, this)
{
	ui.setupUi(this);
	QLocale locale(QLocale::English);
	DoubleVal.setLocale(locale);
	DoubleVal.setNotation(QDoubleValidator::ScientificNotation);
	ui.dist->setValidator(&IntVal);
	ui.draught->setValidator(&IntVal);
	ui.quan->setValidator(&IntVal);
	ui.max_xpeed->setValidator(&DoubleVal);
	ui.mass->setValidator(&DoubleVal);
	ui.amm->setValidator(&IntVal);
	ui.cal->setValidator(&DoubleVal);
	ui.range->setValidator(&DoubleVal);
	ui.exp->setValidator(&IntVal);
	setWindowTitle(QString::fromLocal8Bit("Создание нового корабля"));
	setWindowIcon(QIcon("Icon.png"));
	connect(ui.buttonBox, SIGNAL(accepted()), this, SLOT(read()));
	connect(ui.buttonBox, SIGNAL(rejected()), this, SLOT(close()));
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(readgun()));
	add_box();
}

void NewShip::add_box()
{
	QList<QString> list;
	string s1 = "Корма"; string s2 = "Нос"; string s3 = "Левый борт"; string s4 = "Правый борт";
	QString ss1, ss2, ss3, ss4;
	ss1 = toQ(s1);
	ss2 = toQ(s2);
	ss3 = toQ(s3);
	ss4 = toQ(s4);
	list << ss1; list << ss2; list << ss3; list << ss4;
	ui.comboBox->addItems(list);
}

QString NewShip::toQ(const string& a)
{
	QTextCodec* codec = QTextCodec::codecForName("CP 1251");
	const char* s = a.c_str();
	QString t = codec->toUnicode(s, strlen(s));
	return t;
}

string NewShip::fromQ(const QString& a)
{
	QTextCodec* codec = QTextCodec::codecForName("CP 1251");
	QByteArray st = codec->fromUnicode(a);
	string v = st.toStdString();
	return v;
}

lab4::Element NewShip::read()
{
	int type = ship->getType();
	Element elem;
	try {
		if ((ui.Callship->text().isEmpty()) || (ui.dist->text().isEmpty()) || (ui.draught->text().isEmpty()) || (ui.quan->text().isEmpty()) || (ui.max_xpeed->text().isEmpty()) || (ui.ship_name->text().isEmpty()) || (ui.family->text().isEmpty()) || (ui.name->text().isEmpty()) || (ui.patr->text().isEmpty()) || (ui.rank->text().isEmpty()) || (ui.exp->text().isEmpty())) throw std::invalid_argument("Заполните, пожалуйста, все поля!");
		else {
			elem.callsign = fromQ(ui.Callship->text());
			elem.distance = ui.dist->text().toInt();
			ship->setDra(ui.draught->text().toInt());
			ship->setQuan(ui.quan->text().toInt());
			ship->setMax(ui.max_xpeed->text().toDouble());
			ship->setShipName(fromQ(ui.ship_name->text()));
			ship->setFamily(fromQ(ui.family->text()));
			ship->setName(fromQ(ui.name->text()));
			ship->setPatronymic(fromQ(ui.patr->text()));
			ship->setRank(fromQ(ui.rank->text()));
			ship->setExperience(ui.exp->text().toInt());
		}
		if ((type == 2) || (type == 3)) {
			Transport* ship1 = dynamic_cast<Transport*> (ship);
			if (ui.mass->text().isEmpty()) throw std::invalid_argument("Заполните, пожалуйста, все поля!");
			if (!(ui.mass->text().isEmpty())) ship1->setMass(ui.mass->text().toDouble());
			ship1->Speed();
			elem.ship = ship1->clone();
		}
		if ((type == 1) || (type == 3)) {
			Guard* ship1 = dynamic_cast<Guard*> (ship);
			ship1->setGun(guns);
			elem.ship = ship1->clone();
		}
		close();
		convoy.getTable().includeElem(elem);
		//this->convoy = convoy;
		emit closewin();
	}
	catch (std::exception& ex) {
		string a(ex.what());
		QString b = toQ(a);
		QMessageBox* pmbx = new QMessageBox;
		pmbx->setText(b);
		pmbx->setWindowIcon(QIcon("Icon.png"));
		pmbx->setWindowTitle(QString::fromLocal8Bit("Ошибочка вышла!"));
		pmbx->setIcon(QMessageBox::Icon::Warning);
		pmbx->exec();
	}
	return elem;
}

void NewShip::readgun()
{
	if ((ui.amm->text().isEmpty()) || (ui.cal->text().isEmpty()) || (ui.range->text().isEmpty())){
		string a("Заполните все поля!");
		QString b = toQ(a);
		QMessageBox* pmbx =
			new QMessageBox; pmbx->setText(b);
		pmbx->setWindowTitle(toQ("Ошибка!"));
		pmbx->setWindowIcon(QIcon("Icon.png"));
		pmbx->setIcon(QMessageBox::Icon::Warning);
		pmbx->exec();
		delete pmbx;
	}
	else {
		Armament_Description gun;
		double cal = ui.cal->text().toDouble();
		double range = ui.range->text().toDouble();
		int amm = ui.amm->text().toInt();
		int loc = ui.comboBox->currentIndex() + 1;
		gun.setAmm(amm);
		gun.setCal(cal);
		gun.setRange(range);
		gun.setLoc(loc);
		guns.push_back(gun);
		string a = "Орудие успешно добавлено!"; QString b = toQ(a);
		QMessageBox* pmbx =
			new QMessageBox; pmbx->setText(b);
		pmbx->exec();
		delete pmbx;
	}
}

void NewShip::hid(int type)
{
	ui.cal->clear();
	ui.amm->clear();
	ui.range->clear();
	ui.Callship->clear();
	ui.dist->clear();
	ui.draught->clear();
	ui.quan->clear();
	ui.max_xpeed->clear();
	ui.ship_name->clear();
	ui.family->clear();
	ui.name->clear();
	ui.patr->clear();
	ui.rank->clear();
	ui.exp->clear();
	ui.mass->clear();
	ui.label_13->show();
	ui.cal->show();
	ui.amm->show();
	ui.comboBox->show();
	ui.range->show();
	ui.mass->show();
	ui.label_14->show();
	ui.label_15->show();
	ui.label_16->show();
	ui.label_17->show();
	ui.label_18->show();
	ui.pushButton->show();
	if (type == 1) { ui.mass->hide();
	ui.label_13->hide();
	}
	if (type == 2) {
		ui.cal->hide();
		ui.amm->hide();
		ui.comboBox->hide();
		ui.range->hide();
		ui.label_14->hide();
		ui.label_15->hide();
		ui.label_16->hide();
		ui.label_17->hide();
		ui.label_18->hide();
		ui.pushButton->hide(); 
	}
}


NewShip::~NewShip()
{
}
