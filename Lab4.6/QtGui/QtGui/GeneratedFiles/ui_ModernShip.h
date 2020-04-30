/********************************************************************************
** Form generated from reading UI file 'ModernShip.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODERNSHIP_H
#define UI_MODERNSHIP_H

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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModernShip
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *Draught;
    QLabel *label_2;
    QLineEdit *Quan;
    QLabel *label_3;
    QLineEdit *Max_Speed;
    QLabel *label_4;
    QLineEdit *Ship_Name;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *Family;
    QLabel *label_7;
    QLineEdit *Name;
    QLabel *label_8;
    QLineEdit *Patr;
    QLabel *label_9;
    QLineEdit *Rank;
    QLabel *label_10;
    QLineEdit *Exp;
    QPushButton *pushButton;
    QComboBox *comboBox;
    QLabel *label_11;
    QLineEdit *Mass;
    QDialogButtonBox *buttonBox;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ModernShip)
    {
        if (ModernShip->objectName().isEmpty())
            ModernShip->setObjectName(QStringLiteral("ModernShip"));
        ModernShip->resize(421, 515);
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(14);
        ModernShip->setFont(font);
        centralWidget = new QWidget(ModernShip);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        Draught = new QLineEdit(centralWidget);
        Draught->setObjectName(QStringLiteral("Draught"));

        formLayout->setWidget(0, QFormLayout::FieldRole, Draught);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        Quan = new QLineEdit(centralWidget);
        Quan->setObjectName(QStringLiteral("Quan"));

        formLayout->setWidget(1, QFormLayout::FieldRole, Quan);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        Max_Speed = new QLineEdit(centralWidget);
        Max_Speed->setObjectName(QStringLiteral("Max_Speed"));

        formLayout->setWidget(2, QFormLayout::FieldRole, Max_Speed);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        Ship_Name = new QLineEdit(centralWidget);
        Ship_Name->setObjectName(QStringLiteral("Ship_Name"));

        formLayout->setWidget(3, QFormLayout::FieldRole, Ship_Name);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(4, QFormLayout::SpanningRole, label_5);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        Family = new QLineEdit(centralWidget);
        Family->setObjectName(QStringLiteral("Family"));

        formLayout->setWidget(5, QFormLayout::FieldRole, Family);

        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_7);

        Name = new QLineEdit(centralWidget);
        Name->setObjectName(QStringLiteral("Name"));

        formLayout->setWidget(6, QFormLayout::FieldRole, Name);

        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_8);

        Patr = new QLineEdit(centralWidget);
        Patr->setObjectName(QStringLiteral("Patr"));

        formLayout->setWidget(7, QFormLayout::FieldRole, Patr);

        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_9);

        Rank = new QLineEdit(centralWidget);
        Rank->setObjectName(QStringLiteral("Rank"));

        formLayout->setWidget(8, QFormLayout::FieldRole, Rank);

        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout->setWidget(9, QFormLayout::LabelRole, label_10);

        Exp = new QLineEdit(centralWidget);
        Exp->setObjectName(QStringLiteral("Exp"));

        formLayout->setWidget(9, QFormLayout::FieldRole, Exp);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        formLayout->setWidget(10, QFormLayout::LabelRole, pushButton);

        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        formLayout->setWidget(10, QFormLayout::FieldRole, comboBox);

        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));

        formLayout->setWidget(12, QFormLayout::LabelRole, label_11);

        Mass = new QLineEdit(centralWidget);
        Mass->setObjectName(QStringLiteral("Mass"));

        formLayout->setWidget(12, QFormLayout::FieldRole, Mass);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(centralWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

        ModernShip->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ModernShip);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 421, 21));
        ModernShip->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ModernShip);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ModernShip->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ModernShip);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ModernShip->setStatusBar(statusBar);

        retranslateUi(ModernShip);

        QMetaObject::connectSlotsByName(ModernShip);
    } // setupUi

    void retranslateUi(QMainWindow *ModernShip)
    {
        ModernShip->setWindowTitle(QApplication::translate("ModernShip", "ModernShip", Q_NULLPTR));
        label->setText(QApplication::translate("ModernShip", "\320\222\320\276\320\264\320\276\320\270\320\267\320\274\320\265\321\211\320\265\320\275\320\270\320\265", Q_NULLPTR));
        label_2->setText(QApplication::translate("ModernShip", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\207\320\273\320\265\320\275\320\276\320\262 \321\215\320\272\320\270\320\277\320\260\320\266\320\260", Q_NULLPTR));
        label_3->setText(QApplication::translate("ModernShip", "\320\234\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\260\321\217 \321\201\320\272\320\276\321\200\320\276\321\201\321\202\321\214", Q_NULLPTR));
        label_4->setText(QApplication::translate("ModernShip", "\320\230\320\274\321\217 \320\272\320\276\321\200\320\260\320\261\320\273\321\217", Q_NULLPTR));
        label_5->setText(QApplication::translate("ModernShip", "<html><head/><body><p align=\"center\">\320\232\320\260\320\277\320\270\321\202\320\260\320\275</p></body></html>", Q_NULLPTR));
        label_6->setText(QApplication::translate("ModernShip", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", Q_NULLPTR));
        label_7->setText(QApplication::translate("ModernShip", "\320\230\320\274\321\217", Q_NULLPTR));
        label_8->setText(QApplication::translate("ModernShip", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", Q_NULLPTR));
        label_9->setText(QApplication::translate("ModernShip", "\320\227\320\262\320\260\320\275\320\270\320\265", Q_NULLPTR));
        label_10->setText(QApplication::translate("ModernShip", "\320\241\321\202\320\260\320\266", Q_NULLPTR));
        pushButton->setText(QApplication::translate("ModernShip", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\276\321\200\321\203\320\264\320\270\321\217", Q_NULLPTR));
        label_11->setText(QApplication::translate("ModernShip", "\320\234\320\260\321\201\321\201\320\260 \320\263\321\200\321\203\320\267\320\260", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ModernShip: public Ui_ModernShip {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODERNSHIP_H
