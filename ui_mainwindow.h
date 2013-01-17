/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri Nov 30 17:43:50 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QSlider>
#include <QtGui/QWidget>
#include "basicopenglview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    BasicOpenGLView *widget;
    QSlider *verticalSlider;
    QSlider *verticalSlider_2;
    QSlider *verticalSlider_3;
    QSlider *horizontalSlider;
    QSlider *horizontalSlider_2;
    QSlider *horizontalSlider_3;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_7;
    QLabel *label_10;
    QSlider *horizontalSlider_4;
    QLabel *label_14;
    QLabel *label_15;
    QSlider *horizontalSlider_5;
    QSlider *verticalSlider_5;
    QFrame *frame;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_27;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_13;
    QLabel *label_16;
    QSlider *horizontalSlider_6;
    QLabel *label_30;
    QLabel *label_31;
    QLabel *label_32;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_17;
    QLabel *label_18;
    QSlider *verticalSlider_4;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1022, 858);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget = new BasicOpenGLView(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));

        gridLayout->addWidget(widget, 0, 1, 1, 1);

        verticalSlider = new QSlider(centralWidget);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setMaximum(100);
        verticalSlider->setSingleStep(1);
        verticalSlider->setValue(20);
        verticalSlider->setOrientation(Qt::Vertical);

        gridLayout->addWidget(verticalSlider, 0, 3, 1, 1);

        verticalSlider_2 = new QSlider(centralWidget);
        verticalSlider_2->setObjectName(QString::fromUtf8("verticalSlider_2"));
        verticalSlider_2->setMaximum(100);
        verticalSlider_2->setValue(20);
        verticalSlider_2->setOrientation(Qt::Vertical);

        gridLayout->addWidget(verticalSlider_2, 0, 4, 1, 1);

        verticalSlider_3 = new QSlider(centralWidget);
        verticalSlider_3->setObjectName(QString::fromUtf8("verticalSlider_3"));
        verticalSlider_3->setMaximum(100);
        verticalSlider_3->setValue(1);
        verticalSlider_3->setOrientation(Qt::Vertical);

        gridLayout->addWidget(verticalSlider_3, 0, 5, 1, 1);

        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setMaximum(99);
        horizontalSlider->setValue(0);
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider, 4, 1, 1, 1);

        horizontalSlider_2 = new QSlider(centralWidget);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setMinimum(2);
        horizontalSlider_2->setValue(16);
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_2, 6, 1, 1, 1);

        horizontalSlider_3 = new QSlider(centralWidget);
        horizontalSlider_3->setObjectName(QString::fromUtf8("horizontalSlider_3"));
        horizontalSlider_3->setMinimum(3);
        horizontalSlider_3->setValue(20);
        horizontalSlider_3->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_3, 8, 1, 1, 1);

        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 6, 0, 1, 1);

        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 8, 0, 1, 1);

        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 4, 2, 1, 1);

        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout->addWidget(label_12, 4, 0, 1, 1);

        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 6, 2, 1, 1);

        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 8, 2, 1, 1);

        horizontalSlider_4 = new QSlider(centralWidget);
        horizontalSlider_4->setObjectName(QString::fromUtf8("horizontalSlider_4"));
        horizontalSlider_4->setMinimum(2);
        horizontalSlider_4->setMaximum(50);
        horizontalSlider_4->setValue(20);
        horizontalSlider_4->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_4, 10, 1, 1, 1);

        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout->addWidget(label_14, 10, 0, 1, 1);

        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout->addWidget(label_15, 10, 2, 1, 1);

        horizontalSlider_5 = new QSlider(centralWidget);
        horizontalSlider_5->setObjectName(QString::fromUtf8("horizontalSlider_5"));
        horizontalSlider_5->setMaximum(2);
        horizontalSlider_5->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_5, 12, 1, 1, 1);

        verticalSlider_5 = new QSlider(centralWidget);
        verticalSlider_5->setObjectName(QString::fromUtf8("verticalSlider_5"));
        verticalSlider_5->setMaximum(30);
        verticalSlider_5->setValue(10);
        verticalSlider_5->setOrientation(Qt::Vertical);

        gridLayout->addWidget(verticalSlider_5, 0, 7, 1, 1);

        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_19 = new QLabel(frame);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(10, 10, 62, 16));
        label_20 = new QLabel(frame);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(20, 30, 121, 16));
        label_21 = new QLabel(frame);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(20, 50, 121, 16));
        label_22 = new QLabel(frame);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(20, 70, 121, 16));
        label_23 = new QLabel(frame);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(20, 90, 121, 16));
        label_24 = new QLabel(frame);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(20, 110, 121, 16));
        label_25 = new QLabel(frame);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(20, 130, 121, 16));
        label_26 = new QLabel(frame);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(20, 150, 121, 16));
        label_27 = new QLabel(frame);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(20, 170, 161, 16));
        label_28 = new QLabel(frame);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(150, 30, 121, 16));
        label_29 = new QLabel(frame);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(150, 50, 151, 16));

        gridLayout->addWidget(frame, 5, 3, 9, 5);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 1, 1, 1);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 5, 1, 1, 1);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 7, 1, 1, 1);

        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout->addWidget(label_13, 9, 1, 1, 1);

        label_16 = new QLabel(centralWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout->addWidget(label_16, 11, 1, 1, 1);

        horizontalSlider_6 = new QSlider(centralWidget);
        horizontalSlider_6->setObjectName(QString::fromUtf8("horizontalSlider_6"));
        horizontalSlider_6->setMinimum(10);
        horizontalSlider_6->setMaximum(40);
        horizontalSlider_6->setValue(30);
        horizontalSlider_6->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_6, 2, 1, 1, 1);

        label_30 = new QLabel(centralWidget);
        label_30->setObjectName(QString::fromUtf8("label_30"));

        gridLayout->addWidget(label_30, 1, 1, 1, 1);

        label_31 = new QLabel(centralWidget);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        gridLayout->addWidget(label_31, 2, 0, 1, 1);

        label_32 = new QLabel(centralWidget);
        label_32->setObjectName(QString::fromUtf8("label_32"));

        gridLayout->addWidget(label_32, 2, 2, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 3, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 4, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 5, 1, 1);

        label_17 = new QLabel(centralWidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout->addWidget(label_17, 1, 6, 1, 1);

        label_18 = new QLabel(centralWidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout->addWidget(label_18, 1, 7, 1, 1);

        verticalSlider_4 = new QSlider(centralWidget);
        verticalSlider_4->setObjectName(QString::fromUtf8("verticalSlider_4"));
        verticalSlider_4->setMaximum(30);
        verticalSlider_4->setValue(14);
        verticalSlider_4->setOrientation(Qt::Vertical);

        gridLayout->addWidget(verticalSlider_4, 0, 6, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "99", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "99", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MainWindow", "50", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("MainWindow", "Controls:", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("MainWindow", "W - Move Forward", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("MainWindow", "A - Move Left", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("MainWindow", "S - Move Backward", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("MainWindow", "D - Move Right", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("MainWindow", "\342\206\220 - Turn Left", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("MainWindow", "\342\206\222 - Turn Right", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("MainWindow", "\342\206\221 - Turn Upwards", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("MainWindow", "\342\206\223 - Turn Downwards", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("MainWindow", "+ - Move Upwards", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("MainWindow", "- - Move Downwards", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Damping", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Number of Vertical Springs", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Number of Horizontal Springs", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "Number Of Spring Calculations Per Time Step", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("MainWindow", "Flag Pattern", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("MainWindow", "Timestep", 0, QApplication::UnicodeUTF8));
        label_31->setText(QApplication::translate("MainWindow", "0.1", 0, QApplication::UnicodeUTF8));
        label_32->setText(QApplication::translate("MainWindow", "0.4", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "X Wind", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Y Wind", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Z Wind", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("MainWindow", "Flag Width", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("MainWindow", "FlagHeight", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
