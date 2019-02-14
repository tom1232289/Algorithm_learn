/********************************************************************************
** Form generated from reading UI file 'Ex_1_1_31.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EX_1_1_31_H
#define UI_EX_1_1_31_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ex_1_1_31Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Ex_1_1_31Class)
    {
        if (Ex_1_1_31Class->objectName().isEmpty())
            Ex_1_1_31Class->setObjectName(QStringLiteral("Ex_1_1_31Class"));
        Ex_1_1_31Class->resize(600, 400);
        menuBar = new QMenuBar(Ex_1_1_31Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        Ex_1_1_31Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Ex_1_1_31Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Ex_1_1_31Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(Ex_1_1_31Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Ex_1_1_31Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Ex_1_1_31Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Ex_1_1_31Class->setStatusBar(statusBar);

        retranslateUi(Ex_1_1_31Class);

        QMetaObject::connectSlotsByName(Ex_1_1_31Class);
    } // setupUi

    void retranslateUi(QMainWindow *Ex_1_1_31Class)
    {
        Ex_1_1_31Class->setWindowTitle(QApplication::translate("Ex_1_1_31Class", "Ex_1_1_31", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ex_1_1_31Class: public Ui_Ex_1_1_31Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EX_1_1_31_H
