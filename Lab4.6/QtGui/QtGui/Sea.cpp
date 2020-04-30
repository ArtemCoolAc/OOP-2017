#include "Sea.h"
#include "qlayout.h"
#include "Variable.h"
#include "qgraphicsview.h"
Sea::Sea(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	timer = new QTimer;
	timer1 = new QTimer;
	thread1 = new QThread;
	thread2 = new QThread;
	thread3 = new QThread;
	setWindowIcon(QIcon("Icon.png"));
	//timer->start(50);
	//connect(timer, SIGNAL(timeout()), this, SLOT(movee()));
	connect(timer1, SIGNAL(timeout()), this, SLOT(start0()));
	connect(thread1, SIGNAL(paint()), this, SLOT(multi()));
	connect(timer, SIGNAL(timeout()), this, SLOT(normal_move()));
	connect(thread1, SIGNAL(started()), this, SLOT(movee()));
	connect(thread1, SIGNAL(finished()), this, SLOT(multi2()));
	connect(thread2, SIGNAL(timeout()), this, SLOT(moveth()));
	connect(thread2, SIGNAL(finished()), this, SLOT(multi3()));
	connect(thread3, SIGNAL(timeout()), this, SLOT(moveth()));
	connect(thread3, SIGNAL(finished()), this, SLOT(continuation()));
	//connect(thread2, SIGNAL(started()), this, SLOT(moveth()));
	//connect(thread3, SIGNAL(started()), this, SLOT(moveth()));
	my = new MyScene(NULL);
	QGraphicsView* b = new QGraphicsView;
	b->setMinimumHeight(400);
	b->setMinimumWidth(400);
	b->setScene(my);
	b->show();
	curType = 1;
	a = new QLabel***[3];
	c = -1;
}


void Sea::start0()
{
	++c;
	int os = c % 3;
	if (os == 0)
	curType = 1;
	thread1->start();
	if (os == 1)
	curType = 2;
	thread2->start();
	if (os == 2)
	curType = 3;
	thread3->start();
	
	//this->moveToThread(thread1);
	//emit paint();
}

void Sea::continuation()
{
	QRect rec = a[0][0][0]->geometry();
	int x, y, z, t; rec.getCoords(&x, &y, &z, &t);
	QRect rec1 = a[1][lines][0]->geometry();
	int x1, y1, z1, t1; rec.getCoords(&x1, &y1, &z1, &t1);
	QRect rec2 = a[2][2*lines][0]->geometry();
	int x2, y2, z2, t2; rec.getCoords(&x2, &y2, &z2, &t2);
	if ((x >= 1200) && (x1 >= 1200) && (x2 >= 1200)) {
		thread1->quit();
		thread1->wait();
		delete thread1;
		thread2->quit();
		thread2->wait();
		delete thread2;
		thread3->quit();
		thread3->wait();
		delete thread3;
	}
	else {
		this->moveToThread(thread1);
		thread1->sleep(5);
		emit paint();
	}
}

void Sea::multi()
{
	curType = 1;
	this->moveToThread(thread1);
	moveth();
}

void Sea::multi2()
{
	curType = 2;
	this->moveToThread(thread2);
	moveth();
}

void Sea::multi3()
{
	curType = 3;
	this->moveToThread(thread3);
	moveth();
}

void Sea::add()
{
	//this->setStyleSheet("background-image:url(Sea.jpg)");
	int s;
	for (int j = 0; j < 3; ++j) {
		curType = j + 1;
		a[j] = new QLabel**[lines];
		for (int p = 0; p < lines; ++p) {
			int t = convoy.count(curType);
			int start = lines * (curType - 1) * 32;
			a[j][p] = new QLabel*[t];
			s = t;
			for (int i = 0; i < t; ++i) {
				--s;
				a[j][p][i] = new QLabel(this);
				a[j][p][i]->setGeometry(s * 64, start + p * 32, 64, 32);
				QPixmap t; QString path;
				if (curType == 1) path = "Guard.jpg";
				if (curType == 2) path = "Transport.jpg";
				if (curType == 3) path = "Warship.jpg";
				//t.load("Guard.jpg");
				t.load(path);
				a[j][p][i]->setPixmap(t);
				a[j][p][i]->show();
			}
		}
	}
	timer->start(50);
	my = new MyScene(NULL);

}

void Sea::movee()
{
	for (int j = 0; j < 3; ++j) {
		curType = j + 1;
		for (int p = 0; p < lines; ++p) {
			double k = 64;
			double speed = curType;
			double dx = speed; double dy = 20;
			int t = convoy.count(curType);
			for (int i = 0; i < t; ++i) {
				QRect rec = a[curType - 1][p][i]->geometry();
				int x, y, z, t; rec.getCoords(&x, &y, &z, &t);
				if (x < 1200 - i * 64) {
					int x1 = x + dx;
					a[curType - 1][p][i]->move(x1, y);
					timer->start(5);
				}
				setUpdatesEnabled(true);
				repaint();
				setUpdatesEnabled(false);
			}
		}
	}
}

void Sea::moveth()
{
	//QThread::sleep(5);
	for (int p = 0; p < lines; ++p) {
		double k = 64;
		double speed = curType;
		double dx = speed; double dy = 20;
		int t = convoy.count(curType);
		for (int i = 0; i < t; ++i) {
			QRect rec = a[curType - 1][p][i]->geometry();
			int x, y, z, t; rec.getCoords(&x, &y, &z, &t);
			if (x < 1200 - i * 64) {
				int x1 = x + dx;
				a[curType - 1][p][i]->move(x1, y);
				//timer->start(5);
			}
			setUpdatesEnabled(true);
			repaint();
			setUpdatesEnabled(false);
		}
	}
	emit finished();
}

void Sea::normal_move()
{
	for (int j = 0; j < 3; ++j) {
		curType = j + 1;
		for (int p = 0; p < lines; ++p) {
			double k = 64;
			double speed = curType;
			double dx = speed; double dy = 20;
			int t = convoy.count(curType);
			for (int i = 0; i < t; ++i) {
				QRect rec = a[curType - 1][p][i]->geometry();
				int x, y, z, t; rec.getCoords(&x, &y, &z, &t);
				if (x < 1200 - i * 64) {
					int x1 = x + dx;
					a[curType - 1][p][i]->move(x1, y);
					//timer->start(5);
				}
				/*setUpdatesEnabled(true);
				repaint();
				setUpdatesEnabled(false);*/
			}
		}
	}
	timer->start(10);
}

Sea::~Sea()
{
	for (int j = 0; j < 3; ++j) {
		for (int p = 0; p < lines; ++p) {
			int t = convoy.count(curType);
			for (int i = 0; i < t; ++i) {
				delete a[j][p][i];
				a[j][p][i] = nullptr;
			}
			delete a[j][p];
			a[j][p] = nullptr;
		}
		delete a[j];
		a[j] = nullptr;
	}
	delete a; a = nullptr;
	delete thread1; thread1 = nullptr;
	delete thread2; thread2 = nullptr;
	delete thread3; thread3 = nullptr;
}
