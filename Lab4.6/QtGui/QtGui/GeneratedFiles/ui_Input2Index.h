/********************************************************************************
** Form generated from reading UI file 'Input2Index.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUT2INDEX_H
#define UI_INPUT2INDEX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Input2Index
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QComboBox *TransportBox;
    QComboBox *WarBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QWidget *Input2Index)
    {
        if (Input2Index->objectName().isEmpty())
            Input2Index->setObjectName(QStringLiteral("Input2Index"));
        Input2Index->resize(215, 117);
        formLayoutWidget = new QWidget(Input2Index);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(20, 10, 171, 51));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(0, QFormLayout::FieldRole, label_2);

        TransportBox = new QComboBox(formLayoutWidget);
        TransportBox->setObjectName(QStringLiteral("TransportBox"));

        formLayout->setWidget(1, QFormLayout::LabelRole, TransportBox);

        WarBox = new QComboBox(formLayoutWidget);
        WarBox->setObjectName(QStringLiteral("WarBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, WarBox);

        buttonBox = new QDialogButtonBox(Input2Index);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(20, 70, 156, 23));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(Input2Index);

        QMetaObject::connectSlotsByName(Input2Index);
    } // setupUi

    void retranslateUi(QWidget *Input2Index)
    {
        Input2Index->setWindowTitle(QApplication::translate("Input2Index", "Input2Index", Q_NULLPTR));
        label->setText(QApplication::translate("Input2Index", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">\320\242\321\200\320\260\320\275\321\201\320\277\320\276\321\200\321\202\320\275\321\213\320\271</span></p></body></html>", Q_NULLPTR));
        label_2->setText(QApplication::translate("Input2Index", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">\320\222\320\276\320\265\320\275\320\275\321\213\320\271</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Input2Index: public Ui_Input2Index {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUT2INDEX_H
