/********************************************************************************
** Form generated from reading UI file 'ximage.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XIMAGE_H
#define UI_XIMAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_XimageClass
{
public:
    QLabel *view;
    QPushButton *open;
    QPushButton *deal;
    QSpinBox *bright;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *thread;
    QLabel *label_3;
    QLabel *dealtime;
    QProgressBar *progress;

    void setupUi(QWidget *XimageClass)
    {
        if (XimageClass->objectName().isEmpty())
            XimageClass->setObjectName(QStringLiteral("XimageClass"));
        XimageClass->resize(614, 497);
        QIcon icon;
        icon.addFile(QStringLiteral("Resources/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        XimageClass->setWindowIcon(icon);
        view = new QLabel(XimageClass);
        view->setObjectName(QStringLiteral("view"));
        view->setEnabled(true);
        view->setGeometry(QRect(30, 20, 311, 451));
        view->setStyleSheet(QStringLiteral("background-color: rgb(0, 170, 255);"));
        view->setFrameShadow(QFrame::Raised);
        open = new QPushButton(XimageClass);
        open->setObjectName(QStringLiteral("open"));
        open->setGeometry(QRect(350, 60, 111, 51));
        open->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        deal = new QPushButton(XimageClass);
        deal->setObjectName(QStringLiteral("deal"));
        deal->setGeometry(QRect(470, 60, 111, 51));
        deal->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        bright = new QSpinBox(XimageClass);
        bright->setObjectName(QStringLiteral("bright"));
        bright->setGeometry(QRect(420, 130, 161, 22));
        bright->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        bright->setMinimum(1);
        bright->setMaximum(200);
        bright->setValue(80);
        label = new QLabel(XimageClass);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(350, 130, 51, 21));
        label->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_2 = new QLabel(XimageClass);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(350, 160, 51, 21));
        label_2->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        thread = new QSpinBox(XimageClass);
        thread->setObjectName(QStringLiteral("thread"));
        thread->setGeometry(QRect(420, 160, 161, 22));
        thread->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        thread->setMinimum(1);
        thread->setMaximum(100);
        thread->setValue(1);
        label_3 = new QLabel(XimageClass);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(350, 190, 121, 21));
        label_3->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        dealtime = new QLabel(XimageClass);
        dealtime->setObjectName(QStringLiteral("dealtime"));
        dealtime->setGeometry(QRect(480, 190, 91, 21));
        dealtime->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        dealtime->setFrameShape(QFrame::Box);
        progress = new QProgressBar(XimageClass);
        progress->setObjectName(QStringLiteral("progress"));
        progress->setGeometry(QRect(350, 230, 241, 23));
        progress->setValue(100);

        retranslateUi(XimageClass);
        QObject::connect(open, SIGNAL(clicked()), XimageClass, SLOT(Open()));
        QObject::connect(deal, SIGNAL(clicked()), XimageClass, SLOT(Deal()));

        QMetaObject::connectSlotsByName(XimageClass);
    } // setupUi

    void retranslateUi(QWidget *XimageClass)
    {
        XimageClass->setWindowTitle(QApplication::translate("XimageClass", "Ximage", Q_NULLPTR));
        view->setText(QString());
        open->setText(QApplication::translate("XimageClass", "\346\211\223\345\274\200", Q_NULLPTR));
        deal->setText(QApplication::translate("XimageClass", "\345\244\204\347\220\206", Q_NULLPTR));
        label->setText(QApplication::translate("XimageClass", "\344\272\256\345\272\246", Q_NULLPTR));
        label_2->setText(QApplication::translate("XimageClass", "\347\272\277\347\250\213", Q_NULLPTR));
        label_3->setText(QApplication::translate("XimageClass", "\345\244\204\347\220\206\346\227\266\351\227\264(ms)", Q_NULLPTR));
        dealtime->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class XimageClass: public Ui_XimageClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XIMAGE_H
