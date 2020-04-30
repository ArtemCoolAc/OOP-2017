#include "InfoShip.h"
#include "qtextcodec.h"
#include "..\Library\Consts.h"
#include "Variable.h"
using namespace lab4;

InfoShip::InfoShip(QWidget *parent)
: QMainWindow(parent)
{
	ui.setupUi(this);
	QPixmap shipp("ship.jpg");
	setWindowTitle(QString::fromLocal8Bit("Информация о корабле"));
	setWindowIcon(QIcon("Icon.png"));
	ui.label->setPixmap(shipp);
	connect(ui.comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(ShowGun(int)));
}

void InfoShip::sett()
{
	QTextCodec* codec = QTextCodec::codecForName("CP 1251");
	Table& tab = convoy.getTable();
	int type = tab.cur(index)->ship->getType();
	string s1;
	if (type == 1)
		s1 = "Охранное"; 
	if (type == 2)
		s1 = "Транспортное";
	if (type == 3)
		s1 = "Военное";
	const char* ss1 = s1.c_str();
	QString sss1 = codec->toUnicode(ss1, strlen(ss1));
	ui.TYPE->setText(sss1);
	const char* t1 = tab.cur(index)->callsign.c_str();
	QString tt1 = codec->toUnicode(t1, strlen(t1));
	ui.CALLSIGN->setText(tt1);
	Ship* ship = tab.cur(index)->ship;
	int dra = ship->getDra();
	QString str1,str2,str3,str4,str5,str6,str7,str8,str9;
	str1.setNum(dra);
	ui.label_2->setText(str1);
	int quan = ship->getQuan();
	str2.setNum(quan);
	ui.label_5->setText(str2);
	double max = ship->getMax();
	str3.setNum(max);
	ui.label_7->setText(str3);
	string sname = ship->getShipName();
	const char* ssname = sname.c_str();
	str4 = codec->toUnicode(ssname, strlen(ssname));
	ui.label_9->setText(str4);
	string fam = ship->getCapFamily();
	const char* sfam = fam.c_str();
	str5 = codec->toUnicode(sfam, strlen(sfam));
	ui.label_11->setText(str5);
	string na = ship->getCapName();
	const char* sna = na.c_str();
	str6 = codec->toUnicode(sna, strlen(sna));
	ui.label_12->setText(str6);
	string pa = ship->getCapPatronymic();
	const char* spa = pa.c_str();
	str7 = codec->toUnicode(spa, strlen(spa));
	ui.label_13->setText(str7);
	int exp = ship->getCapExperience();
	str8.setNum(exp);
	ui.label_15->setText(str8);
	string ra = ship->getCapRank();
	const char* sra = ra.c_str();
	str9 = codec->toUnicode(sra, strlen(sra));
	ui.label_17->setText(str9);
	if ((type == 1) || (type == 3)) {
		Guard* ship1 = dynamic_cast<Guard*> (ship);
		int q = ship1->getVec().size();
		if (type == 1) {
			ui.label_27->hide();
			ui.label_28->hide();
			ui.label_29->hide();
			ui.label_30->hide();
		}
		if (type == 3) {
			Warship* ship2 = dynamic_cast<Warship*> (ship1);
			double mass = ship2->getMass();
			double speed = ship2->getSpeed();
			QString s;
			s.setNum(mass);
			ui.label_29->setText(s);
			s.setNum(speed);
			ui.label_30->setText(s);
		}
		add_box(q);
		int am = ship1->getAmm(0);
		double cal = ship1->getCal(0);
		double range = ship1->getRange(0);
		int loc = ship1->getLoc(0);
		QString s;
		s.setNum(am);
		ui.label_23->setText(s);
		s.setNum(cal);
		ui.label_24->setText(s);
		s.setNum(range);
		ui.label_25->setText(s);
		const char* s1 = "Корма"; const char* s2 = "Нос"; const char* s3 = "Левый борт"; const char* s4 = "Правый борт";
		QString ss1, ss2, ss3, ss4;
		ss1 = codec->toUnicode(s1, strlen(s1));
		ss2 = codec->toUnicode(s2, strlen(s2));
		ss3 = codec->toUnicode(s3, strlen(s3));
		ss4 = codec->toUnicode(s4, strlen(s4));
		if (loc == stern) ui.label_26->setText(ss1);
		if (loc == nose) ui.label_26->setText(ss2);
		if (loc == left_side) ui.label_26->setText(ss3);
		if (loc == rigth_side) ui.label_26->setText(ss4);
	}
	else {
		Transport* ship2 = dynamic_cast<Transport*> (ship);
		double mass = ship2->getMass();
		double speed = ship2->getSpeed();
		QString s;
		s.setNum(mass);
		ui.label_29->setText(s);
		s.setNum(speed);
		ui.label_30->setText(s);
		ui.label_18->hide();
		ui.label_19->hide();
		ui.label_20->hide();
		ui.label_21->hide();
		ui.label_22->hide();
		ui.label_23->hide();
		ui.label_24->hide();
		ui.label_25->hide();
		ui.label_26->hide();
		ui.comboBox->hide();
	}
}

void InfoShip::add_box(int q)
{
	QList<QString> list;
	QString str;
	for (int i = 0; i < q; ++i) {
		str.setNum(i);
		list << str;
	}
	ui.comboBox->addItems(list);
}

void InfoShip::ShowGun(int index1)
{
	QTextCodec* codec = QTextCodec::codecForName("CP 1251");
	Ship* ship = convoy.getTable().cur(index)->ship;
	int indexx = ui.comboBox->currentIndex();
	Guard* ship1 = dynamic_cast<Guard*> (ship);
	
	int am = ship1->getAmm(indexx);
	double cal = ship1->getCal(indexx);
	double range = ship1->getRange(indexx);
	int loc = ship1->getLoc(indexx);
	QString s;
	s.setNum(am);
	ui.label_23->setText(s);
	s.setNum(cal);
	ui.label_24->setText(s);
	s.setNum(range);
	ui.label_25->setText(s);
	const char* s1 = "Корма"; const char* s2 = "Нос"; const char* s3 = "Левый борт"; const char* s4 = "Правый борт";
	QString ss1, ss2, ss3, ss4;
	ss1 = codec->toUnicode(s1, strlen(s1));
	ss2 = codec->toUnicode(s2, strlen(s2));
	ss3 = codec->toUnicode(s3, strlen(s3));
	ss4 = codec->toUnicode(s4, strlen(s4));
	if (loc == stern) ui.label_26->setText(ss1);
	if (loc == nose) ui.label_26->setText(ss2);
	if (loc == left_side) ui.label_26->setText(ss3);
	if (loc == rigth_side) ui.label_26->setText(ss4);

}

InfoShip::~InfoShip()
{
}
