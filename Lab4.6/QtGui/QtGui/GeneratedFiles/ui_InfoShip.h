/********************************************************************************
** Form generated from reading UI file 'InfoShip.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOSHIP_H
#define UI_INFOSHIP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InfoShip
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout_2;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_27;
    QLabel *label_29;
    QLabel *label_28;
    QLabel *label_30;
    QLabel *label_18;
    QComboBox *comboBox;
    QLabel *label_19;
    QLabel *label_23;
    QLabel *label_20;
    QLabel *label_24;
    QLabel *label_21;
    QLabel *label_25;
    QLabel *label_22;
    QLabel *label_26;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout;
    QLabel *type;
    QLabel *calls;
    QLabel *TYPE;
    QLabel *CALLSIGN;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *InfoShip)
    {
        if (InfoShip->objectName().isEmpty())
            InfoShip->setObjectName(QStringLiteral("InfoShip"));
        InfoShip->resize(993, 766);
        centralWidget = new QWidget(InfoShip);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(-30, -13, 1024, 768));
        formLayoutWidget = new QWidget(centralWidget);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(40, 60, 241, 451));
        formLayout_2 = new QFormLayout(formLayoutWidget);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_3);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, label_2);

        label_8 = new QLabel(formLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_8);

        label_9 = new QLabel(formLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, label_9);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_4);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, label_5);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_6);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);

        formLayout_2->setWidget(3, QFormLayout::FieldRole, label_7);

        label_10 = new QLabel(formLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_10);

        label_11 = new QLabel(formLayoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font);

        formLayout_2->setWidget(4, QFormLayout::FieldRole, label_11);

        label_12 = new QLabel(formLayoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font);

        formLayout_2->setWidget(6, QFormLayout::LabelRole, label_12);

        label_13 = new QLabel(formLayoutWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font);

        formLayout_2->setWidget(6, QFormLayout::FieldRole, label_13);

        label_14 = new QLabel(formLayoutWidget);
        label_14->setObjectName(QStringLiteral("label_14"));

        formLayout_2->setWidget(7, QFormLayout::LabelRole, label_14);

        label_15 = new QLabel(formLayoutWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setFont(font);

        formLayout_2->setWidget(7, QFormLayout::FieldRole, label_15);

        label_16 = new QLabel(formLayoutWidget);
        label_16->setObjectName(QStringLiteral("label_16"));

        formLayout_2->setWidget(8, QFormLayout::LabelRole, label_16);

        label_17 = new QLabel(formLayoutWidget);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setFont(font);

        formLayout_2->setWidget(8, QFormLayout::FieldRole, label_17);

        label_27 = new QLabel(formLayoutWidget);
        label_27->setObjectName(QStringLiteral("label_27"));

        formLayout_2->setWidget(9, QFormLayout::LabelRole, label_27);

        label_29 = new QLabel(formLayoutWidget);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setFont(font);

        formLayout_2->setWidget(9, QFormLayout::FieldRole, label_29);

        label_28 = new QLabel(formLayoutWidget);
        label_28->setObjectName(QStringLiteral("label_28"));

        formLayout_2->setWidget(10, QFormLayout::LabelRole, label_28);

        label_30 = new QLabel(formLayoutWidget);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setFont(font);

        formLayout_2->setWidget(10, QFormLayout::FieldRole, label_30);

        label_18 = new QLabel(formLayoutWidget);
        label_18->setObjectName(QStringLiteral("label_18"));

        formLayout_2->setWidget(11, QFormLayout::LabelRole, label_18);

        comboBox = new QComboBox(formLayoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        formLayout_2->setWidget(11, QFormLayout::FieldRole, comboBox);

        label_19 = new QLabel(formLayoutWidget);
        label_19->setObjectName(QStringLiteral("label_19"));

        formLayout_2->setWidget(12, QFormLayout::LabelRole, label_19);

        label_23 = new QLabel(formLayoutWidget);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setFont(font);

        formLayout_2->setWidget(12, QFormLayout::FieldRole, label_23);

        label_20 = new QLabel(formLayoutWidget);
        label_20->setObjectName(QStringLiteral("label_20"));

        formLayout_2->setWidget(13, QFormLayout::LabelRole, label_20);

        label_24 = new QLabel(formLayoutWidget);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setFont(font);

        formLayout_2->setWidget(13, QFormLayout::FieldRole, label_24);

        label_21 = new QLabel(formLayoutWidget);
        label_21->setObjectName(QStringLiteral("label_21"));

        formLayout_2->setWidget(14, QFormLayout::LabelRole, label_21);

        label_25 = new QLabel(formLayoutWidget);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setFont(font);

        formLayout_2->setWidget(14, QFormLayout::FieldRole, label_25);

        label_22 = new QLabel(formLayoutWidget);
        label_22->setObjectName(QStringLiteral("label_22"));

        formLayout_2->setWidget(15, QFormLayout::LabelRole, label_22);

        label_26 = new QLabel(formLayoutWidget);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setFont(font);

        formLayout_2->setWidget(15, QFormLayout::FieldRole, label_26);

        formLayoutWidget_2 = new QWidget(centralWidget);
        formLayoutWidget_2->setObjectName(QStringLiteral("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(40, 0, 241, 61));
        formLayout = new QFormLayout(formLayoutWidget_2);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        type = new QLabel(formLayoutWidget_2);
        type->setObjectName(QStringLiteral("type"));

        formLayout->setWidget(0, QFormLayout::LabelRole, type);

        calls = new QLabel(formLayoutWidget_2);
        calls->setObjectName(QStringLiteral("calls"));

        formLayout->setWidget(1, QFormLayout::LabelRole, calls);

        TYPE = new QLabel(formLayoutWidget_2);
        TYPE->setObjectName(QStringLiteral("TYPE"));
        TYPE->setFont(font);

        formLayout->setWidget(0, QFormLayout::FieldRole, TYPE);

        CALLSIGN = new QLabel(formLayoutWidget_2);
        CALLSIGN->setObjectName(QStringLiteral("CALLSIGN"));
        CALLSIGN->setFont(font);

        formLayout->setWidget(1, QFormLayout::FieldRole, CALLSIGN);

        InfoShip->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(InfoShip);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        InfoShip->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(InfoShip);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        InfoShip->setStatusBar(statusBar);

        retranslateUi(InfoShip);

        QMetaObject::connectSlotsByName(InfoShip);
    } // setupUi

    void retranslateUi(QMainWindow *InfoShip)
    {
        InfoShip->setWindowTitle(QApplication::translate("InfoShip", "InfoShip", Q_NULLPTR));
        label->setText(QApplication::translate("InfoShip", "<html><head/><body><p><br/></p></body></html>", Q_NULLPTR));
        label_3->setText(QApplication::translate("InfoShip", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">\320\222\320\276\320\264\320\276\320\270\320\267\320\274\320\265\321\211\320\265\320\275\320\270\320\265</span></p></body></html>", Q_NULLPTR));
        label_2->setText(QApplication::translate("InfoShip", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">TextLabel</span></p></body></html>", Q_NULLPTR));
        label_8->setText(QApplication::translate("InfoShip", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">\320\230\320\274\321\217 \320\272\320\276\321\200\320\260\320\261\320\273\321\217</span></p></body></html>", Q_NULLPTR));
        label_9->setText(QApplication::translate("InfoShip", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">TextLabel</span></p></body></html>", Q_NULLPTR));
        label_4->setText(QApplication::translate("InfoShip", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\207\320\273\320\265\320\275\320\276\320\262</span></p><p align=\"center\"><span style=\" font-size:10pt;\">\321\215\320\272\320\270\320\277\320\260\320\266\320\260</span></p></body></html>", Q_NULLPTR));
        label_5->setText(QApplication::translate("InfoShip", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">TextLabel</span></p></body></html>", Q_NULLPTR));
        label_6->setText(QApplication::translate("InfoShip", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">\320\234\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\260\321\217</span></p><p align=\"center\"><span style=\" font-size:10pt;\">\321\201\320\272\320\276\321\200\320\276\321\201\321\202\321\214</span></p></body></html>", Q_NULLPTR));
        label_7->setText(QApplication::translate("InfoShip", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">TextLabel</span></p></body></html>", Q_NULLPTR));
        label_10->setText(QApplication::translate("InfoShip", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">\320\232\320\260\320\277\320\270\321\202\320\260\320\275</span></p></body></html>", Q_NULLPTR));
        label_11->setText(QApplication::translate("InfoShip", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">TextLabel</span></p></body></html>", Q_NULLPTR));
        label_12->setText(QApplication::translate("InfoShip", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">TextLabel</span></p></body></html>", Q_NULLPTR));
        label_13->setText(QApplication::translate("InfoShip", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">TextLabel</span></p></body></html>", Q_NULLPTR));
        label_14->setText(QApplication::translate("InfoShip", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">\320\241\321\202\320\260\320\266</span></p></body></html>", Q_NULLPTR));
        label_15->setText(QApplication::translate("InfoShip", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">TextLabel</span></p></body></html>", Q_NULLPTR));
        label_16->setText(QApplication::translate("InfoShip", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">\320\227\320\262\320\260\320\275\320\270\320\265</span></p></body></html>", Q_NULLPTR));
        label_17->setText(QApplication::translate("InfoShip", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">TextLabel</span></p></body></html>", Q_NULLPTR));
        label_27->setText(QApplication::translate("InfoShip", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">\320\234\320\260\321\201\321\201\320\260 \320\263\321\200\321\203\320\267\320\260</span></p></body></html>", Q_NULLPTR));
        label_29->setText(QApplication::translate("InfoShip", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">TextLabel</span></p></body></html>", Q_NULLPTR));
        label_28->setText(QApplication::translate("InfoShip", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214</span></p></body></html>", Q_NULLPTR));
        label_30->setText(QApplication::translate("InfoShip", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">TextLabel</span></p></body></html>", Q_NULLPTR));
        label_18->setText(QApplication::translate("InfoShip", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\276\321\200\321\203\320\264\320\270\321\217</span></p></body></html>", Q_NULLPTR));
        label_19->setText(QApplication::translate("InfoShip", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">\320\221\320\276\320\265\320\267\320\260\320\277\320\260\321\201</span></p></body></html>", Q_NULLPTR));
        label_23->setText(QApplication::translate("InfoShip", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">TextLabel</span></p></body></html>", Q_NULLPTR));
        label_20->setText(QApplication::translate("InfoShip", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">\320\232\320\260\320\273\320\270\320\261\321\200</span></p></body></html>", Q_NULLPTR));
        label_24->setText(QApplication::translate("InfoShip", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">TextLabel</span></p></body></html>", Q_NULLPTR));
        label_21->setText(QApplication::translate("InfoShip", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">\320\224\320\260\320\273\321\214\320\275\320\276\321\201\321\202\321\214</span></p></body></html>", Q_NULLPTR));
        label_25->setText(QApplication::translate("InfoShip", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">TextLabel</span></p></body></html>", Q_NULLPTR));
        label_22->setText(QApplication::translate("InfoShip", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">\320\240\320\260\321\201\320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265</span></p></body></html>", Q_NULLPTR));
        label_26->setText(QApplication::translate("InfoShip", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">TextLabel</span></p></body></html>", Q_NULLPTR));
        type->setText(QApplication::translate("InfoShip", "<html><head/><body><p><span style=\" font-size:10pt;\">\320\242\320\270\320\277 \321\201\321\203\320\264\320\275\320\260</span></p></body></html>", Q_NULLPTR));
        calls->setText(QApplication::translate("InfoShip", "<html><head/><body><p><span style=\" font-size:10pt;\">\320\237\320\276\320\267\321\213\320\262\320\275\321\213\320\265</span></p></body></html>", Q_NULLPTR));
        TYPE->setText(QApplication::translate("InfoShip", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">TextLabel </span></p></body></html>", Q_NULLPTR));
        CALLSIGN->setText(QApplication::translate("InfoShip", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">TextLabel</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class InfoShip: public Ui_InfoShip {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOSHIP_H
