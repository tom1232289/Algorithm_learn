/********************************************************************************
** Form generated from reading UI file 'CHistogram.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHISTOGRAM_H
#define UI_CHISTOGRAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CHistogramClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CHistogramClass)
    {
        if (CHistogramClass->objectName().isEmpty())
            CHistogramClass->setObjectName(QStringLiteral("CHistogramClass"));
        CHistogramClass->resize(600, 400);
        menuBar = new QMenuBar(CHistogramClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        CHistogramClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CHistogramClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        CHistogramClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(CHistogramClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        CHistogramClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(CHistogramClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        CHistogramClass->setStatusBar(statusBar);

        retranslateUi(CHistogramClass);

        QMetaObject::connectSlotsByName(CHistogramClass);
    } // setupUi

    void retranslateUi(QMainWindow *CHistogramClass)
    {
        CHistogramClass->setWindowTitle(QApplication::translate("CHistogramClass", "CHistogram", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CHistogramClass: public Ui_CHistogramClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHISTOGRAM_H
