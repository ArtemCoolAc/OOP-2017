/********************************************************************************
** Form generated from reading UI file 'ConvoyMenu.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONVOYMENU_H
#define UI_CONVOYMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConvoyMenu
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QComboBox *comboBox;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ConvoyMenu)
    {
        if (ConvoyMenu->objectName().isEmpty())
            ConvoyMenu->setObjectName(QStringLiteral("ConvoyMenu"));
        ConvoyMenu->resize(588, 807);
        ConvoyMenu->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(ConvoyMenu);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(200, 0, 221, 41));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(40, 60, 191, 61));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(370, 60, 181, 61));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(170, 340, 191, 61));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(170, 440, 231, 61));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(170, 530, 151, 61));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(-110, 720, 231, 61));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(280, 80, 41, 41));
        comboBox->setStyleSheet(QStringLiteral("font: 10pt \"MS Shell Dlg 2\";"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(250, 50, 111, 20));
        comboBox_2 = new QComboBox(centralWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(370, 280, 111, 22));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(370, 360, 113, 20));
        lineEdit->setReadOnly(true);
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(350, 570, 113, 20));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(350, 530, 111, 31));
        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(170, 250, 171, 61));
        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(170, 620, 151, 61));
        pushButton_9 = new QPushButton(centralWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(380, 620, 64, 64));
        pushButton_9->setStyleSheet(QStringLiteral("background-image: url(:/QtGui/Start.jpg);"));
        pushButton_10 = new QPushButton(centralWidget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(200, 150, 201, 61));
        ConvoyMenu->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ConvoyMenu);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 588, 21));
        ConvoyMenu->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ConvoyMenu);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ConvoyMenu->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ConvoyMenu);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ConvoyMenu->setStatusBar(statusBar);

        retranslateUi(ConvoyMenu);

        QMetaObject::connectSlotsByName(ConvoyMenu);
    } // setupUi

    void retranslateUi(QMainWindow *ConvoyMenu)
    {
        ConvoyMenu->setWindowTitle(QApplication::translate("ConvoyMenu", "ConvoyMenu", Q_NULLPTR));
        label->setText(QApplication::translate("ConvoyMenu", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">\320\234\320\265\320\275\321\216 \320\272\320\276\320\275\320\262\320\276\321\217:</span></p></body></html>", Q_NULLPTR));
        pushButton->setText(QApplication::translate("ConvoyMenu", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\320\276\320\274 \321\201\321\203\320\264\320\275\320\265", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("ConvoyMenu", "\320\234\320\276\320\264\320\270\321\204\320\270\320\272\320\260\321\206\320\270\321\217 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\320\276\320\263\320\276 \321\201\321\203\320\264\320\275\320\260", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("ConvoyMenu", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\201\321\203\320\264\320\276\320\262 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\320\276\320\263\320\276 \321\202\320\270\320\277\320\260", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("ConvoyMenu", "\320\234\320\276\320\264\320\265\321\200\320\275\320\270\320\267\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\202\321\200\320\260\320\275\321\201\320\277\320\276\321\200\321\202 \320\264\320\276 \320\262\320\276\320\265\320\275\320\275\320\276\320\263\320\276", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("ConvoyMenu", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\272\320\276\320\275\320\262\320\276\320\271 \320\263\321\200\321\203\320\267\320\276\320\274", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("ConvoyMenu", "\320\237\320\265\321\200\320\265\320\275\320\265\321\201\321\202\320\270 \321\207\320\260\321\201\321\202\321\214 \320\263\321\200\321\203\320\267\320\260", Q_NULLPTR));
        label_2->setText(QApplication::translate("ConvoyMenu", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:600;\">\320\235\320\276\320\274\320\265\321\200 \321\201\321\203\320\264\320\275\320\260</span></p></body></html>", Q_NULLPTR));
        label_3->setText(QApplication::translate("ConvoyMenu", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">\320\223\321\200\321\203\320\267</span></p></body></html>", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("ConvoyMenu", "\320\222\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \321\201\321\203\320\264\320\275\320\276", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("ConvoyMenu", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\262 \321\204\320\260\320\271\320\273", Q_NULLPTR));
        pushButton_9->setText(QString());
        pushButton_10->setText(QApplication::translate("ConvoyMenu", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\201\321\203\320\264\320\275\320\276", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ConvoyMenu: public Ui_ConvoyMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONVOYMENU_H
