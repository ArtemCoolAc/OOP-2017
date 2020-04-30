/********************************************************************************
** Form generated from reading UI file 'Sea.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEA_H
#define UI_SEA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Sea
{
public:

    void setupUi(QWidget *Sea)
    {
        if (Sea->objectName().isEmpty())
            Sea->setObjectName(QStringLiteral("Sea"));
        Sea->resize(1280, 720);
        Sea->setStyleSheet(QStringLiteral("background-image: url(:/QtGui/Sea.jpg);"));

        retranslateUi(Sea);

        QMetaObject::connectSlotsByName(Sea);
    } // setupUi

    void retranslateUi(QWidget *Sea)
    {
        Sea->setWindowTitle(QApplication::translate("Sea", "Sea", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Sea: public Ui_Sea {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEA_H
