#pragma once

#include <QWidget>
#include "ui_Input2Index.h"

class Input2Index : public QWidget
{
	Q_OBJECT

public:
	Input2Index(QWidget *parent = Q_NULLPTR);
	~Input2Index();
	void fulfill();
	

private:
	Ui::Input2Index ui;
private slots:
	void mod();
};
