#include "Input2Index.h"
#include "Variable.h"
Input2Index::Input2Index(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowTitle(QString::fromLocal8Bit("Модернизация"));
	setWindowIcon(QIcon("Icon.png"));
	connect(ui.buttonBox, SIGNAL(accepted()), this, SLOT(mod()));
	connect(ui.buttonBox, SIGNAL(rejected()), this, SLOT(close()));
}

void Input2Index::fulfill()
{
	int t2 = convoy.count(2);
	int* a = new int(t2);
	convoy.writeType(a, 2);
	QList<QString> list;
	QString str;
	for (int i = 0; i < t2; ++i) {
		str.setNum(a[i]);
		list << str;
	}
	ui.TransportBox->addItems(list);
	int t3 = convoy.count(3);
	int * b = new int(t3);
	convoy.writeType(b, 3);
	QList<QString> list1;
	for (int i = 0; i < t3; ++i) {
		str.setNum(b[i]);
		list1 << str;
	}
	ui.WarBox->addItems(list1);
}

void Input2Index::mod()
{
	int ind1 = ui.TransportBox->currentText().toInt();
	int ind2 = ui.WarBox->currentText().toInt();
	convoy.modern(ind1, ind2);
	close();
}

Input2Index::~Input2Index()
{
}
