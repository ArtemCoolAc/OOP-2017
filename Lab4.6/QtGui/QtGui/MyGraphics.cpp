#include "MyGraphics.h"


MyGraphics::MyGraphics(QWidget *parent)
	: QGraphicsView(parent)
{
	//QHBoxLayout* layout = new QHBoxLayout;
	//QPushButton* button1 = new QPushButton;
	//scene = new QGraphicsScene;
	//group1 = new QGraphicsItemGroup;
	//layout->addWidget(button1);
	//parent->setLayout(layout);
	//QPixmap pix;
	//pix.load("Guard.jpg");
	//pix.load("D:\\Documents\\Visual Studio 2013\\Projects\\C++\\Lab4.3\\QtGui\\QtGui\\Guard.jpg");
	//scene->addPixmap(pix);
	//group1->addToGroup(scene->addPixmap(pix));
	//scene->addItem(group1);
	
}

MyGraphics::~MyGraphics()
{
	delete scene;
	delete group1;

}
