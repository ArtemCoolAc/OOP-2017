#pragma once

#include <QWidget>
#include "ui_Sea.h"
#include "qtimer.h"
#include "qlabel.h"
#include "..\Library\Convoy.h"
#include <thread>
#include <atomic>
#include "qthread.h"
#include "MyScene.h"
const int lines = 6;
class Sea : public QWidget
{
	Q_OBJECT

public:
	Sea(QWidget *parent = Q_NULLPTR);
	~Sea();
	void add();
	//void setCon(lab4::Convoy& convoy) { this->convoy = convoy; }
signals:
	void finished();
	void paint();
private:
	Ui::Sea ui;
	MyScene* my;
	QTimer* timer;
	QTimer* timer1;
	QLabel**** a;
	//lab4::Convoy convoy;
	std::atomic<int> curType;
	QThread* thread1;
	QThread* thread2;
	QThread* thread3;
	std::atomic<double> SPEED;
	std::atomic<int> c;
private slots:
void start0();
void movee();
void multi();
void multi2();
void multi3();
void moveth();
void continuation();
void normal_move();
};
