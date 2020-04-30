#include "MyScene.h"
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QGraphicsItem>
#include <QtCore>

MyScene::MyScene(QObject *parent)
	: QGraphicsScene(parent)
{
	war = addPixmap(QPixmap("Warship.jpg"));
	war->setData(0, "war");
	//war = addPixmap(QPixmap("Warship.jpg"));
	/*left = addLine(-500, -500, -500 , 500);
	right = addLine(500, -500, 500, 500);
	top = addLine(-500, -500, 500, -500);
	bottom = addLine(-500, 500, 500, 500);*/
	war->show();
	
}

void MyScene::keyPressEvent(QKeyEvent * keyEvent)
{
	//np.setX(0);
	//np.setY(0);
	int x = np.x();
	int y = np.y();
	switch (keyEvent->key()) {
	case Qt::Key_Left:
		if (x-10>-500)
		np.setX(x-10);
		break;
	case Qt::Key_Right:
		if (x+10<500)
		np.setX(x+10);
		break;
	case Qt::Key_Up:
		if (y-10>-500)
		np.setY(y-10);
		break;
	case Qt::Key_Down:
		if (y+10<500)
		np.setY(y+10);
		break;
	}
	
	war->setX(np.x());
	war->setY(np.y());
	/*war->translate(np.x(), np.y());
	QGraphicsItem * obstacle = itemCollidesWith(war);
	if (obstacle) {
		if (obstacle->data(0) == "Wall") {
			war->translate(-np.x(), -np.y());
			printf("Hello wall!\n");
		}
		else
			if (obstacle->data(0) == "Box") {
				obstacle->translate(np.x(), np.y());
				if (itemCollidesWith(obstacle) || itemCollidesWith(war)) {
					obstacle->translate(-np.x(), -np.y());
					war->translate(-np.x(), -np.y());
					printf("Cannot move!\n");
				}
			}

	}*/

}

/*void MyScene::keyReleaseEvent(QKeyEvent * keyEvent)
{
	int x = np.x();
	int y = np.y();
	switch (keyEvent->key()) {
	case Qt::Key_Left:
		if (x - 10>-500)
			np.setX(x - 10);
		break;
	case Qt::Key_Right:
		if (x + 10<500)
			np.setX(x + 10);
		break;
	case Qt::Key_Up:
		if (y - 10>-500)
			np.setY(y - 10);
		break;
	case Qt::Key_Down:
		if (y + 10<500)
			np.setY(y + 10);
		break;
	}
}*/

void MyScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent * mouseEvent)
{
	mouse.setX(mouseEvent->pos().x());
	mouse.setY(mouseEvent->pos().y());
	war = addPixmap(QPixmap("Shell.jpg"));
	dx = mouse.x() - np.x();
	dy = mouse.y() - np.x();
	t = 0;
	while (t < 1) {
		int x1 = np.x() + dx*t;
		int y1 = np.y() + dx*t;
		np.setX(x1);
		np.setY(y1);
		t += 0.01;

	}
}

MyScene::~MyScene()
{
}
