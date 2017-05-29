/********************************************************************************
** Form generated from reading UI file 'firstqt_64.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIRSTQT_64_H
#define UI_FIRSTQT_64_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_firstQT_64Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *firstQT_64Class)
    {
        if (firstQT_64Class->objectName().isEmpty())
            firstQT_64Class->setObjectName(QStringLiteral("firstQT_64Class"));
        firstQT_64Class->resize(600, 400);
        menuBar = new QMenuBar(firstQT_64Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        firstQT_64Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(firstQT_64Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        firstQT_64Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(firstQT_64Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        firstQT_64Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(firstQT_64Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        firstQT_64Class->setStatusBar(statusBar);

        retranslateUi(firstQT_64Class);

        QMetaObject::connectSlotsByName(firstQT_64Class);
    } // setupUi

    void retranslateUi(QMainWindow *firstQT_64Class)
    {
        firstQT_64Class->setWindowTitle(QApplication::translate("firstQT_64Class", "firstQT_64", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class firstQT_64Class: public Ui_firstQT_64Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIRSTQT_64_H
