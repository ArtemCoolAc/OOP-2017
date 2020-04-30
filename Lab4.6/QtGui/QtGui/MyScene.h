#pragma once

#include <QGraphicsScene>
#include <QMouseEvent>

class MyScene : public QGraphicsScene
{
	Q_OBJECT

protected:
	//virtual void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
	virtual void keyPressEvent(QKeyEvent * keyEvent);
	//virtual void keyReleaseEvent(QKeyEvent * keyEvent);
	virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *mouseEvent);
private:
	QGraphicsPixmapItem* war;
	QGraphicsLineItem* top;
	QGraphicsLineItem* bottom;
	QGraphicsLineItem* left;
	QGraphicsLineItem* right;
	int dx; int dy; int t;

public:
	MyScene(QObject *parent);
	~MyScene();
	QGraphicsItem * itemCollidesWith(QGraphicsItem * item);
	QPointF np;
	QPointF np2;
	QPoint mouse;
	private slots:
 	//void movet();
};
