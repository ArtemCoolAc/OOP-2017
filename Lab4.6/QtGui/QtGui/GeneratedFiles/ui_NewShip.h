/********************************************************************************
** Form generated from reading UI file 'NewShip.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWSHIP_H
#define UI_NEWSHIP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
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

class Ui_NewShip
{
public:
    QWidget *centralWidget;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *Callship;
    QLabel *label_2;
    QLineEdit *dist;
    QLabel *label_3;
    QLineEdit *draught;
    QLabel *label_4;
    QLineEdit *max_xpeed;
    QLabel *label_5;
    QLineEdit *quan;
    QLabel *label_6;
    QLineEdit *ship_name;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *family;
    QLabel *label_9;
    QLineEdit *name;
    QLabel *label_10;
    QLineEdit *patr;
    QLabel *label_11;
    QLineEdit *rank;
    QLabel *label_12;
    QLineEdit *exp;
    QLabel *label_13;
    QLineEdit *mass;
    QLabel *label_18;
    QLabel *label_14;
    QLineEdit *amm;
    QLabel *label_15;
    QLineEdit *cal;
    QLabel *label_16;
    QLineEdit *range;
    QLabel *label_17;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QDialogButtonBox *buttonBox;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *NewShip)
    {
        if (NewShip->objectName().isEmpty())
            NewShip->setObjectName(QStringLiteral("NewShip"));
        NewShip->resize(447, 678);
        centralWidget = new QWidget(NewShip);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        formLayoutWidget = new QWidget(centralWidget);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(30, 10, 391, 581));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        Callship = new QLineEdit(formLayoutWidget);
        Callship->setObjectName(QStringLiteral("Callship"));

        formLayout->setWidget(0, QFormLayout::FieldRole, Callship);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        dist = new QLineEdit(formLayoutWidget);
        dist->setObjectName(QStringLiteral("dist"));

        formLayout->setWidget(1, QFormLayout::FieldRole, dist);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        draught = new QLineEdit(formLayoutWidget);
        draught->setObjectName(QStringLiteral("draught"));

        formLayout->setWidget(2, QFormLayout::FieldRole, draught);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        max_xpeed = new QLineEdit(formLayoutWidget);
        max_xpeed->setObjectName(QStringLiteral("max_xpeed"));

        formLayout->setWidget(3, QFormLayout::FieldRole, max_xpeed);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        quan = new QLineEdit(formLayoutWidget);
        quan->setObjectName(QStringLiteral("quan"));

        formLayout->setWidget(4, QFormLayout::FieldRole, quan);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        ship_name = new QLineEdit(formLayoutWidget);
        ship_name->setObjectName(QStringLiteral("ship_name"));

        formLayout->setWidget(5, QFormLayout::FieldRole, ship_name);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);

        formLayout->setWidget(6, QFormLayout::SpanningRole, label_7);

        label_8 = new QLabel(formLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);

        formLayout->setWidget(7, QFormLayout::LabelRole, label_8);

        family = new QLineEdit(formLayoutWidget);
        family->setObjectName(QStringLiteral("family"));

        formLayout->setWidget(7, QFormLayout::FieldRole, family);

        label_9 = new QLabel(formLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font);

        formLayout->setWidget(8, QFormLayout::LabelRole, label_9);

        name = new QLineEdit(formLayoutWidget);
        name->setObjectName(QStringLiteral("name"));

        formLayout->setWidget(8, QFormLayout::FieldRole, name);

        label_10 = new QLabel(formLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font);

        formLayout->setWidget(9, QFormLayout::LabelRole, label_10);

        patr = new QLineEdit(formLayoutWidget);
        patr->setObjectName(QStringLiteral("patr"));

        formLayout->setWidget(9, QFormLayout::FieldRole, patr);

        label_11 = new QLabel(formLayoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font);

        formLayout->setWidget(10, QFormLayout::LabelRole, label_11);

        rank = new QLineEdit(formLayoutWidget);
        rank->setObjectName(QStringLiteral("rank"));

        formLayout->setWidget(10, QFormLayout::FieldRole, rank);

        label_12 = new QLabel(formLayoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font);

        formLayout->setWidget(11, QFormLayout::LabelRole, label_12);

        exp = new QLineEdit(formLayoutWidget);
        exp->setObjectName(QStringLiteral("exp"));

        formLayout->setWidget(11, QFormLayout::FieldRole, exp);

        label_13 = new QLabel(formLayoutWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font);

        formLayout->setWidget(12, QFormLayout::LabelRole, label_13);

        mass = new QLineEdit(formLayoutWidget);
        mass->setObjectName(QStringLiteral("mass"));

        formLayout->setWidget(12, QFormLayout::FieldRole, mass);

        label_18 = new QLabel(formLayoutWidget);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setFont(font);

        formLayout->setWidget(13, QFormLayout::SpanningRole, label_18);

        label_14 = new QLabel(formLayoutWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFont(font);

        formLayout->setWidget(14, QFormLayout::LabelRole, label_14);

        amm = new QLineEdit(formLayoutWidget);
        amm->setObjectName(QStringLiteral("amm"));

        formLayout->setWidget(14, QFormLayout::FieldRole, amm);

        label_15 = new QLabel(formLayoutWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setFont(font);

        formLayout->setWidget(15, QFormLayout::LabelRole, label_15);

        cal = new QLineEdit(formLayoutWidget);
        cal->setObjectName(QStringLiteral("cal"));

        formLayout->setWidget(15, QFormLayout::FieldRole, cal);

        label_16 = new QLabel(formLayoutWidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setFont(font);

        formLayout->setWidget(16, QFormLayout::LabelRole, label_16);

        range = new QLineEdit(formLayoutWidget);
        range->setObjectName(QStringLiteral("range"));

        formLayout->setWidget(16, QFormLayout::FieldRole, range);

        label_17 = new QLabel(formLayoutWidget);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setFont(font);

        formLayout->setWidget(17, QFormLayout::LabelRole, label_17);

        comboBox = new QComboBox(formLayoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        formLayout->setWidget(17, QFormLayout::FieldRole, comboBox);

        pushButton = new QPushButton(formLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        formLayout->setWidget(18, QFormLayout::SpanningRole, pushButton);

        buttonBox = new QDialogButtonBox(centralWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(150, 590, 156, 23));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        NewShip->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(NewShip);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 447, 21));
        NewShip->setMenuBar(menuBar);
        mainToolBar = new QToolBar(NewShip);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        NewShip->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(NewShip);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        NewShip->setStatusBar(statusBar);

        retranslateUi(NewShip);

        QMetaObject::connectSlotsByName(NewShip);
    } // setupUi

    void retranslateUi(QMainWindow *NewShip)
    {
        NewShip->setWindowTitle(QApplication::translate("NewShip", "NewShip", Q_NULLPTR));
        label->setText(QApplication::translate("NewShip", "\320\237\320\276\320\267\321\213\320\262\320\275\321\213\320\265", Q_NULLPTR));
        label_2->setText(QApplication::translate("NewShip", "\320\240\320\260\321\201\321\201\321\202\320\276\321\217\320\275\320\270\320\265", Q_NULLPTR));
        label_3->setText(QApplication::translate("NewShip", "\320\222\320\276\320\264\320\276\320\270\320\267\320\274\320\265\321\211\320\265\320\275\320\270\320\265", Q_NULLPTR));
        label_4->setText(QApplication::translate("NewShip", "\320\234\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\260\321\217 \321\201\320\272\320\276\321\200\320\276\321\201\321\202\321\214", Q_NULLPTR));
        label_5->setText(QApplication::translate("NewShip", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\207\320\273\320\265\320\275\320\276\320\262 \321\215\320\272\320\270\320\277\320\260\320\266\320\260", Q_NULLPTR));
        label_6->setText(QApplication::translate("NewShip", "\320\230\320\274\321\217 \320\272\320\276\321\200\320\260\320\261\320\273\321\217", Q_NULLPTR));
        label_7->setText(QApplication::translate("NewShip", "<html><head/><body><p align=\"center\">\320\232\320\260\320\277\320\270\321\202\320\260\320\275</p></body></html>", Q_NULLPTR));
        label_8->setText(QApplication::translate("NewShip", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", Q_NULLPTR));
        label_9->setText(QApplication::translate("NewShip", "\320\230\320\274\321\217", Q_NULLPTR));
        label_10->setText(QApplication::translate("NewShip", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", Q_NULLPTR));
        label_11->setText(QApplication::translate("NewShip", "\320\227\320\262\320\260\320\275\320\270\320\265", Q_NULLPTR));
        label_12->setText(QApplication::translate("NewShip", "\320\241\321\202\320\260\320\266", Q_NULLPTR));
        label_13->setText(QApplication::translate("NewShip", "\320\234\320\260\321\201\321\201\320\260 \320\263\321\200\321\203\320\267\320\260", Q_NULLPTR));
        label_18->setText(QApplication::translate("NewShip", "<html><head/><body><p align=\"center\">\320\236\321\200\321\203\320\264\320\270\320\265</p></body></html>", Q_NULLPTR));
        label_14->setText(QApplication::translate("NewShip", "\320\221\320\276\320\265\320\267\320\260\320\277\320\260\321\201", Q_NULLPTR));
        label_15->setText(QApplication::translate("NewShip", "\320\232\320\260\320\273\320\270\320\261\321\200", Q_NULLPTR));
        label_16->setText(QApplication::translate("NewShip", "\320\224\320\260\320\273\321\214\320\275\320\276\321\201\321\202\321\214 \321\201\321\202\321\200\320\265\320\273\321\214\320\261\321\213", Q_NULLPTR));
        label_17->setText(QApplication::translate("NewShip", "\320\240\320\260\321\201\320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265", Q_NULLPTR));
        pushButton->setText(QApplication::translate("NewShip", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\276\321\200\321\203\320\264\320\270\320\265", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NewShip: public Ui_NewShip {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWSHIP_H
