#pragma once

#include <QGraphicsView>
#include "qlayout.h"
#include "qpushbutton.h"
#include "qwidget.h"
#include "qgraphicsview.h"
#include "qgraphicsitem.h"
#include "qtimer.h"

class MyGraphics : public QGraphicsView
{
	Q_OBJECT

public:
	MyGraphics(QWidget *parent);
	~MyGraphics();

private:
	QGraphicsScene* scene;
	QTimer* timer;
	QGraphicsItemGroup* group1;
};
