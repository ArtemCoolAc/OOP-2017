/********************************************************************************
** Form generated from reading UI file 'ChangeGuns.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEGUNS_H
#define UI_CHANGEGUNS_H

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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChangeGuns
{
public:
    QWidget *centralWidget;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *Amm;
    QLineEdit *Cal;
    QLineEdit *Range;
    QComboBox *comboBox;
    QDialogButtonBox *buttonBox;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ChangeGuns)
    {
        if (ChangeGuns->objectName().isEmpty())
            ChangeGuns->setObjectName(QStringLiteral("ChangeGuns"));
        ChangeGuns->resize(266, 215);
        centralWidget = new QWidget(ChangeGuns);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        formLayoutWidget = new QWidget(centralWidget);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(20, 20, 243, 111));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(14);
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        Amm = new QLineEdit(formLayoutWidget);
        Amm->setObjectName(QStringLiteral("Amm"));

        formLayout->setWidget(0, QFormLayout::FieldRole, Amm);

        Cal = new QLineEdit(formLayoutWidget);
        Cal->setObjectName(QStringLiteral("Cal"));

        formLayout->setWidget(1, QFormLayout::FieldRole, Cal);

        Range = new QLineEdit(formLayoutWidget);
        Range->setObjectName(QStringLiteral("Range"));

        formLayout->setWidget(2, QFormLayout::FieldRole, Range);

        comboBox = new QComboBox(formLayoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        formLayout->setWidget(3, QFormLayout::FieldRole, comboBox);

        buttonBox = new QDialogButtonBox(centralWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 140, 156, 23));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        ChangeGuns->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ChangeGuns);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 266, 21));
        ChangeGuns->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ChangeGuns);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ChangeGuns->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ChangeGuns);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ChangeGuns->setStatusBar(statusBar);

        retranslateUi(ChangeGuns);

        QMetaObject::connectSlotsByName(ChangeGuns);
    } // setupUi

    void retranslateUi(QMainWindow *ChangeGuns)
    {
        ChangeGuns->setWindowTitle(QApplication::translate("ChangeGuns", "ChangeGuns", Q_NULLPTR));
        label->setText(QApplication::translate("ChangeGuns", "\320\221\320\276\320\265\320\267\320\260\320\277\320\260\321\201", Q_NULLPTR));
        label_2->setText(QApplication::translate("ChangeGuns", "\320\232\320\260\320\273\320\270\320\261\321\200", Q_NULLPTR));
        label_3->setText(QApplication::translate("ChangeGuns", "\320\224\320\260\320\273\321\214\320\275\320\276\321\201\321\202\321\214 \321\201\321\202\321\200\320\265\320\273\321\214\320\261\321\213", Q_NULLPTR));
        label_4->setText(QApplication::translate("ChangeGuns", "\320\240\320\260\321\201\320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ChangeGuns: public Ui_ChangeGuns {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEGUNS_H
