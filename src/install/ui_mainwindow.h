/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QFrame *frame_2;
    QGridLayout *gridLayout;
    QPushButton *pushButton_8;
    QPushButton *pushButton_1;
    QPushButton *pushButton_14;
    QPushButton *pushButton_19;
    QPushButton *pushButton_20;
    QPushButton *pushButton_16;
    QPushButton *pushButton_10;
    QPushButton *pushButton_23;
    QPushButton *pushButton_9;
    QPushButton *pushButton_17;
    QPushButton *pushButton_3;
    QPushButton *pushButton_15;
    QPushButton *pushButton_13;
    QPushButton *pushButton_12;
    QPushButton *pushButton_18;
    QPushButton *pushButton_22;
    QPushButton *pushButton_11;
    QPushButton *pushButton_5;
    QPushButton *pushButton_2;
    QPushButton *pushButton_24;
    QPushButton *pushButton_21;
    QPushButton *pushButton_7;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QPushButton *pushButton_25;
    QPushButton *pushButton_26;
    QPushButton *pushButton_27;
    QPushButton *pushButton_28;
    QPushButton *pushButton_29;
    QPushButton *pushButton_30;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_31;
    QPushButton *pushButton_32;
    QPushButton *pushButton_33;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(564, 456);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QFont font;
        font.setBold(true);
        font.setItalic(true);
        pushButton->setFont(font);

        horizontalLayout_3->addWidget(pushButton);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(false);
        lineEdit->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_3->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setEnabled(false);
        lineEdit_2->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color: rgb(0, 0, 0);\n"
"    font-weight: bold;"));

        horizontalLayout_3->addWidget(lineEdit_2);

        horizontalLayout_3->setStretch(1, 4);
        horizontalLayout_3->setStretch(2, 12);

        gridLayout_2->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::HLine);
        frame_2->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(frame_2, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setMinimumSize(QSize(50, 50));
        pushButton_8->setMaximumSize(QSize(50, 50));
        pushButton_8->setStyleSheet(QString::fromUtf8("background-color: rgb(154, 153, 150);\n"
"color: white;\n"
"font-weight: bold;"));

        gridLayout->addWidget(pushButton_8, 1, 1, 1, 1);

        pushButton_1 = new QPushButton(centralwidget);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setMinimumSize(QSize(50, 50));
        pushButton_1->setMaximumSize(QSize(50, 50));
        pushButton_1->setStyleSheet(QString::fromUtf8("background-color: rgb(154, 153, 150);\n"
"color: white;\n"
"font-weight: bold;"));

        gridLayout->addWidget(pushButton_1, 0, 0, 1, 1);

        pushButton_14 = new QPushButton(centralwidget);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));
        pushButton_14->setMinimumSize(QSize(50, 50));
        pushButton_14->setMaximumSize(QSize(50, 50));
        pushButton_14->setStyleSheet(QString::fromUtf8("background-color: rgb(154, 153, 150);\n"
"color: white;\n"
"font-weight: bold;"));

        gridLayout->addWidget(pushButton_14, 2, 1, 1, 1);

        pushButton_19 = new QPushButton(centralwidget);
        pushButton_19->setObjectName(QString::fromUtf8("pushButton_19"));
        pushButton_19->setMinimumSize(QSize(50, 49));
        pushButton_19->setMaximumSize(QSize(50, 50));
        pushButton_19->setStyleSheet(QString::fromUtf8("background-color: rgb(154, 153, 150);\n"
"color: white;\n"
"font-weight: bold;"));

        gridLayout->addWidget(pushButton_19, 3, 0, 1, 1);

        pushButton_20 = new QPushButton(centralwidget);
        pushButton_20->setObjectName(QString::fromUtf8("pushButton_20"));
        pushButton_20->setMinimumSize(QSize(50, 50));
        pushButton_20->setMaximumSize(QSize(50, 50));
        pushButton_20->setStyleSheet(QString::fromUtf8("background-color: rgb(154, 153, 150);\n"
"color: white;\n"
"font-weight: bold;"));

        gridLayout->addWidget(pushButton_20, 3, 1, 1, 1);

        pushButton_16 = new QPushButton(centralwidget);
        pushButton_16->setObjectName(QString::fromUtf8("pushButton_16"));
        pushButton_16->setMinimumSize(QSize(50, 50));
        pushButton_16->setMaximumSize(QSize(50, 50));
        pushButton_16->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: white;\n"
"    font-weight: bold;"));

        gridLayout->addWidget(pushButton_16, 2, 3, 1, 1);

        pushButton_10 = new QPushButton(centralwidget);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setMinimumSize(QSize(50, 50));
        pushButton_10->setMaximumSize(QSize(50, 50));
        pushButton_10->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: white;\n"
"    font-weight: bold;"));

        gridLayout->addWidget(pushButton_10, 1, 3, 1, 1);

        pushButton_23 = new QPushButton(centralwidget);
        pushButton_23->setObjectName(QString::fromUtf8("pushButton_23"));
        pushButton_23->setMinimumSize(QSize(50, 50));
        pushButton_23->setMaximumSize(QSize(50, 50));
        pushButton_23->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: white;\n"
"    font-weight: bold;"));

        gridLayout->addWidget(pushButton_23, 3, 4, 1, 1);

        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setMinimumSize(QSize(50, 50));
        pushButton_9->setMaximumSize(QSize(50, 50));
        pushButton_9->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: white;\n"
"    font-weight: bold;"));

        gridLayout->addWidget(pushButton_9, 1, 2, 1, 1);

        pushButton_17 = new QPushButton(centralwidget);
        pushButton_17->setObjectName(QString::fromUtf8("pushButton_17"));
        pushButton_17->setMinimumSize(QSize(50, 50));
        pushButton_17->setMaximumSize(QSize(50, 50));
        pushButton_17->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: white;\n"
"    font-weight: bold;"));

        gridLayout->addWidget(pushButton_17, 2, 4, 1, 1);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(50, 50));
        pushButton_3->setMaximumSize(QSize(50, 50));
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: red; color: white; font-weight: bold;"));

        gridLayout->addWidget(pushButton_3, 0, 2, 1, 1);

        pushButton_15 = new QPushButton(centralwidget);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));
        pushButton_15->setMinimumSize(QSize(50, 50));
        pushButton_15->setMaximumSize(QSize(50, 50));
        pushButton_15->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: white;\n"
"    font-weight: bold;"));

        gridLayout->addWidget(pushButton_15, 2, 2, 1, 1);

        pushButton_13 = new QPushButton(centralwidget);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));
        pushButton_13->setMinimumSize(QSize(50, 50));
        pushButton_13->setMaximumSize(QSize(50, 50));
        pushButton_13->setStyleSheet(QString::fromUtf8("background-color: rgb(154, 153, 150);\n"
"color: white;\n"
"font-weight: bold;"));

        gridLayout->addWidget(pushButton_13, 2, 0, 1, 1);

        pushButton_12 = new QPushButton(centralwidget);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setMinimumSize(QSize(100, 50));
        pushButton_12->setMaximumSize(QSize(100, 50));
        pushButton_12->setStyleSheet(QString::fromUtf8("background-color: rgb(28, 113, 216);\n"
"color: white;\n"
"font-weight: bold;"));

        gridLayout->addWidget(pushButton_12, 1, 5, 1, 1);

        pushButton_18 = new QPushButton(centralwidget);
        pushButton_18->setObjectName(QString::fromUtf8("pushButton_18"));
        pushButton_18->setMinimumSize(QSize(100, 50));
        pushButton_18->setMaximumSize(QSize(100, 50));
        pushButton_18->setStyleSheet(QString::fromUtf8("background-color: rgb(28, 113, 216);\n"
"color: white;\n"
"font-weight: bold;"));

        gridLayout->addWidget(pushButton_18, 2, 5, 1, 1);

        pushButton_22 = new QPushButton(centralwidget);
        pushButton_22->setObjectName(QString::fromUtf8("pushButton_22"));
        pushButton_22->setMinimumSize(QSize(50, 50));
        pushButton_22->setMaximumSize(QSize(50, 50));
        pushButton_22->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: white;\n"
"    font-weight: bold;"));

        gridLayout->addWidget(pushButton_22, 3, 3, 1, 1);

        pushButton_11 = new QPushButton(centralwidget);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setMinimumSize(QSize(50, 50));
        pushButton_11->setMaximumSize(QSize(50, 50));
        pushButton_11->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: white;\n"
"    font-weight: bold;"));

        gridLayout->addWidget(pushButton_11, 1, 4, 1, 1);

        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(50, 50));
        pushButton_5->setMaximumSize(QSize(50, 50));
        pushButton_5->setStyleSheet(QString::fromUtf8("background-color: rgb(28, 113, 216);\n"
"color: white;\n"
"font-weight: bold;"));

        gridLayout->addWidget(pushButton_5, 0, 4, 1, 1);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(50);
        sizePolicy.setVerticalStretch(50);
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setMinimumSize(QSize(50, 50));
        pushButton_2->setMaximumSize(QSize(50, 50));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(154, 153, 150);\n"
"color: white;\n"
"font-weight: bold;"));

        gridLayout->addWidget(pushButton_2, 0, 1, 1, 1);

        pushButton_24 = new QPushButton(centralwidget);
        pushButton_24->setObjectName(QString::fromUtf8("pushButton_24"));
        pushButton_24->setMinimumSize(QSize(100, 50));
        pushButton_24->setMaximumSize(QSize(100, 50));
        pushButton_24->setStyleSheet(QString::fromUtf8("background-color: rgb(28, 113, 216);\n"
"color: white;\n"
"font-weight: bold;"));

        gridLayout->addWidget(pushButton_24, 3, 5, 1, 1);

        pushButton_21 = new QPushButton(centralwidget);
        pushButton_21->setObjectName(QString::fromUtf8("pushButton_21"));
        pushButton_21->setMinimumSize(QSize(50, 50));
        pushButton_21->setMaximumSize(QSize(50, 50));
        pushButton_21->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: white;\n"
"    font-weight: bold;"));

        gridLayout->addWidget(pushButton_21, 3, 2, 1, 1);

        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setMinimumSize(QSize(50, 50));
        pushButton_7->setMaximumSize(QSize(50, 50));
        pushButton_7->setStyleSheet(QString::fromUtf8("background-color: rgb(154, 153, 150);\n"
"color: white;\n"
"font-weight: bold;"));

        gridLayout->addWidget(pushButton_7, 1, 0, 1, 1);

        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(50, 50));
        pushButton_4->setMaximumSize(QSize(50, 50));
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color: rgb(28, 113, 216);\n"
"color: white;\n"
"font-weight: bold;"));

        gridLayout->addWidget(pushButton_4, 0, 3, 1, 1);

        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(100, 50));
        pushButton_6->setMaximumSize(QSize(100, 50));
        pushButton_6->setStyleSheet(QString::fromUtf8("background-color: rgb(28, 113, 216);\n"
"color: white;\n"
"font-weight: bold;"));

        gridLayout->addWidget(pushButton_6, 0, 5, 1, 1);

        pushButton_25 = new QPushButton(centralwidget);
        pushButton_25->setObjectName(QString::fromUtf8("pushButton_25"));
        pushButton_25->setMinimumSize(QSize(50, 50));
        pushButton_25->setMaximumSize(QSize(50, 50));
        pushButton_25->setStyleSheet(QString::fromUtf8("background-color: rgb(154, 153, 150);\n"
"color: white;\n"
"font-weight: bold;"));

        gridLayout->addWidget(pushButton_25, 4, 0, 1, 1);

        pushButton_26 = new QPushButton(centralwidget);
        pushButton_26->setObjectName(QString::fromUtf8("pushButton_26"));
        pushButton_26->setMinimumSize(QSize(50, 50));
        pushButton_26->setMaximumSize(QSize(50, 50));
        pushButton_26->setStyleSheet(QString::fromUtf8("background-color: rgb(154, 153, 150);\n"
"color: white;\n"
"font-weight: bold;"));

        gridLayout->addWidget(pushButton_26, 4, 1, 1, 1);

        pushButton_27 = new QPushButton(centralwidget);
        pushButton_27->setObjectName(QString::fromUtf8("pushButton_27"));
        pushButton_27->setMinimumSize(QSize(50, 50));
        pushButton_27->setMaximumSize(QSize(50, 50));
        pushButton_27->setStyleSheet(QString::fromUtf8("background-color: rgb(28, 113, 216);\n"
"color: white;\n"
"font-weight: bold;"));

        gridLayout->addWidget(pushButton_27, 4, 2, 1, 1);

        pushButton_28 = new QPushButton(centralwidget);
        pushButton_28->setObjectName(QString::fromUtf8("pushButton_28"));
        pushButton_28->setMinimumSize(QSize(50, 50));
        pushButton_28->setMaximumSize(QSize(50, 50));
        pushButton_28->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: white;\n"
"    font-weight: bold;"));

        gridLayout->addWidget(pushButton_28, 4, 3, 1, 1);

        pushButton_29 = new QPushButton(centralwidget);
        pushButton_29->setObjectName(QString::fromUtf8("pushButton_29"));
        pushButton_29->setMinimumSize(QSize(50, 50));
        pushButton_29->setMaximumSize(QSize(50, 50));
        pushButton_29->setStyleSheet(QString::fromUtf8("background-color: rgb(28, 113, 216);\n"
"color: white;\n"
"font-weight: bold;"));

        gridLayout->addWidget(pushButton_29, 4, 4, 1, 1);

        pushButton_30 = new QPushButton(centralwidget);
        pushButton_30->setObjectName(QString::fromUtf8("pushButton_30"));
        pushButton_30->setMinimumSize(QSize(100, 50));
        pushButton_30->setStyleSheet(QString::fromUtf8("background-color: orange; color: white; font-weight: bold;"));

        gridLayout->addWidget(pushButton_30, 4, 5, 1, 1);


        gridLayout_2->addLayout(gridLayout, 2, 0, 1, 1);

        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::HLine);
        frame->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(frame, 3, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_31 = new QPushButton(centralwidget);
        pushButton_31->setObjectName(QString::fromUtf8("pushButton_31"));
        pushButton_31->setStyleSheet(QString::fromUtf8("background-color:rgb(26, 95, 180);\n"
"color: white;\n"
"font-weight: bold;"));

        horizontalLayout->addWidget(pushButton_31);

        pushButton_32 = new QPushButton(centralwidget);
        pushButton_32->setObjectName(QString::fromUtf8("pushButton_32"));
        pushButton_32->setStyleSheet(QString::fromUtf8("background-color:rgb(26, 95, 180);\n"
"color: white;\n"
"font-weight: bold;"));

        horizontalLayout->addWidget(pushButton_32);

        pushButton_33 = new QPushButton(centralwidget);
        pushButton_33->setObjectName(QString::fromUtf8("pushButton_33"));
        pushButton_33->setStyleSheet(QString::fromUtf8("background-color:rgb(26, 95, 180);\n"
"color: white;\n"
"font-weight: bold;"));

        horizontalLayout->addWidget(pushButton_33);


        gridLayout_2->addLayout(horizontalLayout, 4, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 564, 22));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Smart Calc", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Set 'X'", nullptr));
#if QT_CONFIG(accessibility)
        pushButton_8->setAccessibleName(QCoreApplication::translate("MainWindow", "c", nullptr));
#endif // QT_CONFIG(accessibility)
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "cos", nullptr));
#if QT_CONFIG(accessibility)
        pushButton_1->setAccessibleName(QCoreApplication::translate("MainWindow", "l", nullptr));
#endif // QT_CONFIG(accessibility)
        pushButton_1->setText(QCoreApplication::translate("MainWindow", "ln", nullptr));
#if QT_CONFIG(accessibility)
        pushButton_14->setAccessibleName(QCoreApplication::translate("MainWindow", "s", nullptr));
#endif // QT_CONFIG(accessibility)
        pushButton_14->setText(QCoreApplication::translate("MainWindow", "sin", nullptr));
#if QT_CONFIG(accessibility)
        pushButton_19->setAccessibleName(QCoreApplication::translate("MainWindow", "v", nullptr));
#endif // QT_CONFIG(accessibility)
        pushButton_19->setText(QCoreApplication::translate("MainWindow", "atan", nullptr));
#if QT_CONFIG(accessibility)
        pushButton_20->setAccessibleName(QCoreApplication::translate("MainWindow", "t", nullptr));
#endif // QT_CONFIG(accessibility)
        pushButton_20->setText(QCoreApplication::translate("MainWindow", "tan", nullptr));
#if QT_CONFIG(accessibility)
        pushButton_16->setAccessibleName(QCoreApplication::translate("MainWindow", "5", nullptr));
#endif // QT_CONFIG(accessibility)
        pushButton_16->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
#if QT_CONFIG(accessibility)
        pushButton_10->setAccessibleName(QCoreApplication::translate("MainWindow", "2", nullptr));
#endif // QT_CONFIG(accessibility)
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
#if QT_CONFIG(accessibility)
        pushButton_23->setAccessibleName(QCoreApplication::translate("MainWindow", "9", nullptr));
#endif // QT_CONFIG(accessibility)
        pushButton_23->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
#if QT_CONFIG(accessibility)
        pushButton_9->setAccessibleName(QCoreApplication::translate("MainWindow", "1", nullptr));
#endif // QT_CONFIG(accessibility)
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
#if QT_CONFIG(accessibility)
        pushButton_17->setAccessibleName(QCoreApplication::translate("MainWindow", "6", nullptr));
#endif // QT_CONFIG(accessibility)
        pushButton_17->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
#if QT_CONFIG(accessibility)
        pushButton_15->setAccessibleName(QCoreApplication::translate("MainWindow", "4", nullptr));
#endif // QT_CONFIG(accessibility)
        pushButton_15->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
#if QT_CONFIG(accessibility)
        pushButton_13->setAccessibleName(QCoreApplication::translate("MainWindow", "i", nullptr));
#endif // QT_CONFIG(accessibility)
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "asin", nullptr));
#if QT_CONFIG(accessibility)
        pushButton_12->setAccessibleName(QCoreApplication::translate("MainWindow", "-", nullptr));
#endif // QT_CONFIG(accessibility)
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
#if QT_CONFIG(accessibility)
        pushButton_18->setAccessibleName(QCoreApplication::translate("MainWindow", "*", nullptr));
#endif // QT_CONFIG(accessibility)
        pushButton_18->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
#if QT_CONFIG(accessibility)
        pushButton_22->setAccessibleName(QCoreApplication::translate("MainWindow", "8", nullptr));
#endif // QT_CONFIG(accessibility)
        pushButton_22->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
#if QT_CONFIG(accessibility)
        pushButton_11->setAccessibleName(QCoreApplication::translate("MainWindow", "3", nullptr));
#endif // QT_CONFIG(accessibility)
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
#if QT_CONFIG(accessibility)
        pushButton_5->setAccessibleName(QCoreApplication::translate("MainWindow", "(", nullptr));
#endif // QT_CONFIG(accessibility)
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
#if QT_CONFIG(accessibility)
        pushButton_2->setAccessibleName(QCoreApplication::translate("MainWindow", "o", nullptr));
#endif // QT_CONFIG(accessibility)
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "log", nullptr));
#if QT_CONFIG(accessibility)
        pushButton_24->setAccessibleName(QCoreApplication::translate("MainWindow", "/", nullptr));
#endif // QT_CONFIG(accessibility)
        pushButton_24->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
#if QT_CONFIG(accessibility)
        pushButton_21->setAccessibleName(QCoreApplication::translate("MainWindow", "7", nullptr));
#endif // QT_CONFIG(accessibility)
        pushButton_21->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
#if QT_CONFIG(accessibility)
        pushButton_7->setAccessibleName(QCoreApplication::translate("MainWindow", "a", nullptr));
#endif // QT_CONFIG(accessibility)
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "acos", nullptr));
#if QT_CONFIG(accessibility)
        pushButton_4->setAccessibleName(QCoreApplication::translate("MainWindow", "q", nullptr));
#endif // QT_CONFIG(accessibility)
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "sqrt", nullptr));
#if QT_CONFIG(accessibility)
        pushButton_6->setAccessibleName(QCoreApplication::translate("MainWindow", "+", nullptr));
#endif // QT_CONFIG(accessibility)
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
#if QT_CONFIG(accessibility)
        pushButton_25->setAccessibleName(QCoreApplication::translate("MainWindow", "^", nullptr));
#endif // QT_CONFIG(accessibility)
        pushButton_25->setText(QCoreApplication::translate("MainWindow", "x^y", nullptr));
#if QT_CONFIG(accessibility)
        pushButton_26->setAccessibleName(QCoreApplication::translate("MainWindow", "m", nullptr));
#endif // QT_CONFIG(accessibility)
        pushButton_26->setText(QCoreApplication::translate("MainWindow", "mod", nullptr));
#if QT_CONFIG(accessibility)
        pushButton_27->setAccessibleName(QCoreApplication::translate("MainWindow", ".", nullptr));
#endif // QT_CONFIG(accessibility)
        pushButton_27->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
#if QT_CONFIG(accessibility)
        pushButton_28->setAccessibleName(QCoreApplication::translate("MainWindow", "0", nullptr));
#endif // QT_CONFIG(accessibility)
        pushButton_28->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
#if QT_CONFIG(accessibility)
        pushButton_29->setAccessibleName(QCoreApplication::translate("MainWindow", ")", nullptr));
#endif // QT_CONFIG(accessibility)
        pushButton_29->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
#if QT_CONFIG(accessibility)
        pushButton_30->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        pushButton_30->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        pushButton_31->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214 \320\272\321\200\320\265\320\264\320\270\321\202", nullptr));
        pushButton_32->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\321\205\320\276\320\264\320\275\320\276\321\201\321\202\321\214 \320\262\320\272\320\273\320\260\320\264\320\260", nullptr));
        pushButton_33->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
