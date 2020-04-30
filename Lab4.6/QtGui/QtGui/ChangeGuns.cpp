#include "ChangeGuns.h"
#include "..\Library\Consts.h"
#include "qtextcodec.h"
#include "qmessagebox.h"
using namespace lab4;
ChangeGuns::ChangeGuns(QWidget *parent)
	: QMainWindow(parent), IntVal(0, INT_MAX, this), DoubleVal(0, std::numeric_limits<double>::max(), 5, this)
{
	ui.setupUi(this);
	QLocale locale(QLocale::English);
	DoubleVal.setLocale(locale);
	DoubleVal.setNotation(QDoubleValidator::ScientificNotation);
	ui.Amm->setValidator(&IntVal);
	ui.Cal->setValidator(&DoubleVal);
	ui.Range->setValidator(&DoubleVal);
	setWindowTitle(QString::fromLocal8Bit("Изменение параметров орудия"));
	setWindowIcon(QIcon("Icon.png"));
	connect(ui.buttonBox, SIGNAL(accepted()), this, SLOT(saveGuns()));
	connect(ui.buttonBox, SIGNAL(rejected()), this, SLOT(close()));
}

void ChangeGuns::sett(int index)
{
	Gind = index;
	Guard* ship1 = dynamic_cast<Guard*> (ship);
	vector<Armament_Description>& tab = ship1->getVec();
	int amm = tab[index].getAmm();
	QString v;
	v.setNum(amm);
	ui.Amm->setText(v);
	double cal = tab[index].getCal();
	v.setNum(cal);
	ui.Cal->setText(v);
	double range = tab[index].getRange();
	v.setNum(range);
	ui.Range->setText(v);
	int loc = tab[index].getLoc();
	string s;
	QString ss = toQ(s);
	add_box();
	ui.comboBox->setCurrentIndex(loc - 1);
}

QString ChangeGuns::toQ(const string& a)
{
	QTextCodec* codec = QTextCodec::codecForName("CP 1251");
	const char* s = a.c_str();
	QString t = codec->toUnicode(s, strlen(s));
	return t;
}

string ChangeGuns::FromQ(const QString& a)
{
	QTextCodec* codec = QTextCodec::codecForName("CP 1251");
	QByteArray st = codec->fromUnicode(a);
	string v = st.toStdString();
	return v;
}

void ChangeGuns::add_box()
{
	Guard* ship1 = dynamic_cast<Guard*> (ship);
	int q = ship1->getVec().size();
	QList<QString> list;
	string s1, s2, s3, s4;
	s1 = "Корма";
	s2 = "Нос";
	s3 = "Левый борт";
	s4 = "Правый борт";
	QString ss1, ss2, ss3, ss4;
	ss1 = toQ(s1); ss2 = toQ(s2); ss3 = toQ(s3); ss4 = toQ(s4);
	list << ss1; list << ss2; list << ss3; list << ss4;
	ui.comboBox->addItems(list);
}

void ChangeGuns::saveGuns()
{
	int Cind = ui.comboBox->currentIndex();
	int loc = Cind + 1;
	Guard* ship1 = dynamic_cast<Guard*> (ship);
	vector<Armament_Description>& tab = ship1->getVec();
	if ((ui.Amm->text().isEmpty()) || (ui.Cal->text().isEmpty()) || (ui.Range->text().isEmpty())) {
		QMessageBox* pmbx =
			new QMessageBox;
		pmbx->setText(QString::fromLocal8Bit("Заполните все поля!"));
		pmbx->setIcon(QMessageBox::Warning);
		pmbx->setWindowTitle(QString::fromLocal8Bit("Ошибка!"));
		pmbx->setWindowIcon(QIcon("Icon.png"));
		pmbx->exec();
	}
	else {
		if (!(ui.Amm->text().isEmpty())) tab[Gind].setAmm(ui.Amm->text().toInt());
		if (!(ui.Cal->text().isEmpty())) tab[Gind].setCal(ui.Cal->text().toDouble());
		if (!(ui.Range->text().isEmpty())) tab[Gind].setRange(ui.Range->text().toDouble());
		tab[Gind].setLoc(loc);
		close();
	}
}

ChangeGuns::~ChangeGuns()
{
}
