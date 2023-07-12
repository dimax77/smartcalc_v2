/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
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
    QWidget *central_widget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *push_button_set_x;
    QLineEdit *line_edit_x;
    QLineEdit *line_edit_expression;
    QFrame *frame_2;
    QGridLayout *gridLayout;
    QPushButton *push_button_8;
    QPushButton *push_button_1;
    QPushButton *push_button_14;
    QPushButton *push_button_19;
    QPushButton *push_button_20;
    QPushButton *push_button_16;
    QPushButton *push_button_10;
    QPushButton *push_button_23;
    QPushButton *push_button_9;
    QPushButton *push_button_17;
    QPushButton *push_button_3;
    QPushButton *push_button_15;
    QPushButton *push_button_13;
    QPushButton *push_button_12;
    QPushButton *push_button_18;
    QPushButton *push_button_22;
    QPushButton *push_button_11;
    QPushButton *push_button_5;
    QPushButton *push_button_2;
    QPushButton *push_button_24;
    QPushButton *push_button_21;
    QPushButton *push_button_7;
    QPushButton *push_button_4;
    QPushButton *push_button_6;
    QPushButton *push_button_25;
    QPushButton *push_button_26;
    QPushButton *push_button_27;
    QPushButton *push_button_28;
    QPushButton *push_button_29;
    QPushButton *push_button_30;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QPushButton *push_button_credit;
    QPushButton *push_button_deposit;
    QPushButton *push_button_graph;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(564, 456);
        central_widget = new QWidget(MainWindow);
        central_widget->setObjectName(QString::fromUtf8("central_widget"));
        gridLayout_3 = new QGridLayout(central_widget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        push_button_set_x = new QPushButton(central_widget);
        push_button_set_x->setObjectName(QString::fromUtf8("push_button_set_x"));
        QFont font;
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        push_button_set_x->setFont(font);

        horizontalLayout_3->addWidget(push_button_set_x);

        line_edit_x = new QLineEdit(central_widget);
        line_edit_x->setObjectName(QString::fromUtf8("line_edit_x"));
        line_edit_x->setEnabled(false);
        line_edit_x->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_3->addWidget(line_edit_x);

        line_edit_expression = new QLineEdit(central_widget);
        line_edit_expression->setObjectName(QString::fromUtf8("line_edit_expression"));
        line_edit_expression->setEnabled(false);
        line_edit_expression->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color: rgb(0, 0, 0);\n"
"    font-weight: bold;"));

        horizontalLayout_3->addWidget(line_edit_expression);

        horizontalLayout_3->setStretch(1, 4);
        horizontalLayout_3->setStretch(2, 12);

        gridLayout_2->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        frame_2 = new QFrame(central_widget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::HLine);
        frame_2->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(frame_2, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        push_button_8 = new QPushButton(central_widget);
        push_button_8->setObjectName(QString::fromUtf8("push_button_8"));
        push_button_8->setMinimumSize(QSize(50, 50));
        push_button_8->setMaximumSize(QSize(50, 50));
        push_button_8->setStyleSheet(QString::fromUtf8("background-color: rgb(154, 153, 150);\n"
"color: white;\n"
"font-weight: bold;"));

        gridLayout->addWidget(push_button_8, 1, 1, 1, 1);

        push_button_1 = new QPushButton(central_widget);
        push_button_1->setObjectName(QString::fromUtf8("push_button_1"));
        push_button_1->setMinimumSize(QSize(50, 50));
        push_button_1->setMaximumSize(QSize(50, 50));
        push_button_1->setStyleSheet(QString::fromUtf8("background-color: rgb(154, 153, 150);\n"
"color: white;\n"
"font-weight: bold;"));

        gridLayout->addWidget(push_button_1, 0, 0, 1, 1);

        push_button_14 = new QPushButton(central_widget);
        push_button_14->setObjectName(QString::fromUtf8("push_button_14"));
        push_button_14->setMinimumSize(QSize(50, 50));
        push_button_14->setMaximumSize(QSize(50, 50));
        push_button_14->setStyleSheet(QString::fromUtf8("background-color: rgb(154, 153, 150);\n"
"color: white;\n"
"font-weight: bold;"));

        gridLayout->addWidget(push_button_14, 2, 1, 1, 1);

        push_button_19 = new QPushButton(central_widget);
        push_button_19->setObjectName(QString::fromUtf8("push_button_19"));
        push_button_19->setMinimumSize(QSize(50, 49));
        push_button_19->setMaximumSize(QSize(50, 50));
        push_button_19->setStyleSheet(QString::fromUtf8("background-color: rgb(154, 153, 150);\n"
"color: white;\n"
"font-weight: bold;"));

        gridLayout->addWidget(push_button_19, 3, 0, 1, 1);

        push_button_20 = new QPushButton(central_widget);
        push_button_20->setObjectName(QString::fromUtf8("push_button_20"));
        push_button_20->setMinimumSize(QSize(50, 50));
        push_button_20->setMaximumSize(QSize(50, 50));
        push_button_20->setStyleSheet(QString::fromUtf8("background-color: rgb(154, 153, 150);\n"
"color: white;\n"
"font-weight: bold;"));

        gridLayout->addWidget(push_button_20, 3, 1, 1, 1);

        push_button_16 = new QPushButton(central_widget);
        push_button_16->setObjectName(QString::fromUtf8("push_button_16"));
        push_button_16->setMinimumSize(QSize(50, 50));
        push_button_16->setMaximumSize(QSize(50, 50));
        push_button_16->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: white;\n"
"    font-weight: bold;"));

        gridLayout->addWidget(push_button_16, 2, 3, 1, 1);

        push_button_10 = new QPushButton(central_widget);
        push_button_10->setObjectName(QString::fromUtf8("push_button_10"));
        push_button_10->setMinimumSize(QSize(50, 50));
        push_button_10->setMaximumSize(QSize(50, 50));
        push_button_10->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: white;\n"
"    font-weight: bold;"));

        gridLayout->addWidget(push_button_10, 1, 3, 1, 1);

        push_button_23 = new QPushButton(central_widget);
        push_button_23->setObjectName(QString::fromUtf8("push_button_23"));
        push_button_23->setMinimumSize(QSize(50, 50));
        push_button_23->setMaximumSize(QSize(50, 50));
        push_button_23->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: white;\n"
"    font-weight: bold;"));

        gridLayout->addWidget(push_button_23, 3, 4, 1, 1);

        push_button_9 = new QPushButton(central_widget);
        push_button_9->setObjectName(QString::fromUtf8("push_button_9"));
        push_button_9->setMinimumSize(QSize(50, 50));
        push_button_9->setMaximumSize(QSize(50, 50));
        push_button_9->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: white;\n"
"    font-weight: bold;"));

        gridLayout->addWidget(push_button_9, 1, 2, 1, 1);

        push_button_17 = new QPushButton(central_widget);
        push_button_17->setObjectName(QString::fromUtf8("push_button_17"));
        push_button_17->setMinimumSize(QSize(50, 50));
        push_button_17->setMaximumSize(QSize(50, 50));
        push_button_17->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: white;\n"
"    font-weight: bold;"));

        gridLayout->addWidget(push_button_17, 2, 4, 1, 1);

        push_button_3 = new QPushButton(central_widget);
        push_button_3->setObjectName(QString::fromUtf8("push_button_3"));
        push_button_3->setMinimumSize(QSize(50, 50));
        push_button_3->setMaximumSize(QSize(50, 50));
        push_button_3->setStyleSheet(QString::fromUtf8("background-color: red; color: white; font-weight: bold;"));

        gridLayout->addWidget(push_button_3, 0, 2, 1, 1);

        push_button_15 = new QPushButton(central_widget);
        push_button_15->setObjectName(QString::fromUtf8("push_button_15"));
        push_button_15->setMinimumSize(QSize(50, 50));
        push_button_15->setMaximumSize(QSize(50, 50));
        push_button_15->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: white;\n"
"    font-weight: bold;"));

        gridLayout->addWidget(push_button_15, 2, 2, 1, 1);

        push_button_13 = new QPushButton(central_widget);
        push_button_13->setObjectName(QString::fromUtf8("push_button_13"));
        push_button_13->setMinimumSize(QSize(50, 50));
        push_button_13->setMaximumSize(QSize(50, 50));
        push_button_13->setStyleSheet(QString::fromUtf8("background-color: rgb(154, 153, 150);\n"
"color: white;\n"
"font-weight: bold;"));

        gridLayout->addWidget(push_button_13, 2, 0, 1, 1);

        push_button_12 = new QPushButton(central_widget);
        push_button_12->setObjectName(QString::fromUtf8("push_button_12"));
        push_button_12->setMinimumSize(QSize(100, 50));
        push_button_12->setMaximumSize(QSize(100, 50));
        push_button_12->setStyleSheet(QString::fromUtf8("background-color: rgb(28, 113, 216);\n"
"color: white;\n"
"font-weight: bold;"));

        gridLayout->addWidget(push_button_12, 1, 5, 1, 1);

        push_button_18 = new QPushButton(central_widget);
        push_button_18->setObjectName(QString::fromUtf8("push_button_18"));
        push_button_18->setMinimumSize(QSize(100, 50));
        push_button_18->setMaximumSize(QSize(100, 50));
        push_button_18->setStyleSheet(QString::fromUtf8("background-color: rgb(28, 113, 216);\n"
"color: white;\n"
"font-weight: bold;"));

        gridLayout->addWidget(push_button_18, 2, 5, 1, 1);

        push_button_22 = new QPushButton(central_widget);
        push_button_22->setObjectName(QString::fromUtf8("push_button_22"));
        push_button_22->setMinimumSize(QSize(50, 50));
        push_button_22->setMaximumSize(QSize(50, 50));
        push_button_22->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: white;\n"
"    font-weight: bold;"));

        gridLayout->addWidget(push_button_22, 3, 3, 1, 1);

        push_button_11 = new QPushButton(central_widget);
        push_button_11->setObjectName(QString::fromUtf8("push_button_11"));
        push_button_11->setMinimumSize(QSize(50, 50));
        push_button_11->setMaximumSize(QSize(50, 50));
        push_button_11->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: white;\n"
"    font-weight: bold;"));

        gridLayout->addWidget(push_button_11, 1, 4, 1, 1);

        push_button_5 = new QPushButton(central_widget);
        push_button_5->setObjectName(QString::fromUtf8("push_button_5"));
        push_button_5->setMinimumSize(QSize(50, 50));
        push_button_5->setMaximumSize(QSize(50, 50));
        push_button_5->setStyleSheet(QString::fromUtf8("background-color: rgb(28, 113, 216);\n"
"color: white;\n"
"font-weight: bold;"));

        gridLayout->addWidget(push_button_5, 0, 4, 1, 1);

        push_button_2 = new QPushButton(central_widget);
        push_button_2->setObjectName(QString::fromUtf8("push_button_2"));
        push_button_2->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(50);
        sizePolicy.setVerticalStretch(50);
        sizePolicy.setHeightForWidth(push_button_2->sizePolicy().hasHeightForWidth());
        push_button_2->setSizePolicy(sizePolicy);
        push_button_2->setMinimumSize(QSize(50, 50));
        push_button_2->setMaximumSize(QSize(50, 50));
        push_button_2->setStyleSheet(QString::fromUtf8("background-color: rgb(154, 153, 150);\n"
"color: white;\n"
"font-weight: bold;"));

        gridLayout->addWidget(push_button_2, 0, 1, 1, 1);

        push_button_24 = new QPushButton(central_widget);
        push_button_24->setObjectName(QString::fromUtf8("push_button_24"));
        push_button_24->setMinimumSize(QSize(100, 50));
        push_button_24->setMaximumSize(QSize(100, 50));
        push_button_24->setStyleSheet(QString::fromUtf8("background-color: rgb(28, 113, 216);\n"
"color: white;\n"
"font-weight: bold;"));

        gridLayout->addWidget(push_button_24, 3, 5, 1, 1);

        push_button_21 = new QPushButton(central_widget);
        push_button_21->setObjectName(QString::fromUtf8("push_button_21"));
        push_button_21->setMinimumSize(QSize(50, 50));
        push_button_21->setMaximumSize(QSize(50, 50));
        push_button_21->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: white;\n"
"    font-weight: bold;"));

        gridLayout->addWidget(push_button_21, 3, 2, 1, 1);

        push_button_7 = new QPushButton(central_widget);
        push_button_7->setObjectName(QString::fromUtf8("push_button_7"));
        push_button_7->setMinimumSize(QSize(50, 50));
        push_button_7->setMaximumSize(QSize(50, 50));
        push_button_7->setStyleSheet(QString::fromUtf8("background-color: rgb(154, 153, 150);\n"
"color: white;\n"
"font-weight: bold;"));

        gridLayout->addWidget(push_button_7, 1, 0, 1, 1);

        push_button_4 = new QPushButton(central_widget);
        push_button_4->setObjectName(QString::fromUtf8("push_button_4"));
        push_button_4->setMinimumSize(QSize(50, 50));
        push_button_4->setMaximumSize(QSize(50, 50));
        push_button_4->setStyleSheet(QString::fromUtf8("background-color: rgb(28, 113, 216);\n"
"color: white;\n"
"font-weight: bold;"));

        gridLayout->addWidget(push_button_4, 0, 3, 1, 1);

        push_button_6 = new QPushButton(central_widget);
        push_button_6->setObjectName(QString::fromUtf8("push_button_6"));
        push_button_6->setMinimumSize(QSize(100, 50));
        push_button_6->setMaximumSize(QSize(100, 50));
        push_button_6->setStyleSheet(QString::fromUtf8("background-color: rgb(28, 113, 216);\n"
"color: white;\n"
"font-weight: bold;"));

        gridLayout->addWidget(push_button_6, 0, 5, 1, 1);

        push_button_25 = new QPushButton(central_widget);
        push_button_25->setObjectName(QString::fromUtf8("push_button_25"));
        push_button_25->setMinimumSize(QSize(50, 50));
        push_button_25->setMaximumSize(QSize(50, 50));
        push_button_25->setStyleSheet(QString::fromUtf8("background-color: rgb(154, 153, 150);\n"
"color: white;\n"
"font-weight: bold;"));

        gridLayout->addWidget(push_button_25, 4, 0, 1, 1);

        push_button_26 = new QPushButton(central_widget);
        push_button_26->setObjectName(QString::fromUtf8("push_button_26"));
        push_button_26->setMinimumSize(QSize(50, 50));
        push_button_26->setMaximumSize(QSize(50, 50));
        push_button_26->setStyleSheet(QString::fromUtf8("background-color: rgb(154, 153, 150);\n"
"color: white;\n"
"font-weight: bold;"));

        gridLayout->addWidget(push_button_26, 4, 1, 1, 1);

        push_button_27 = new QPushButton(central_widget);
        push_button_27->setObjectName(QString::fromUtf8("push_button_27"));
        push_button_27->setMinimumSize(QSize(50, 50));
        push_button_27->setMaximumSize(QSize(50, 50));
        push_button_27->setStyleSheet(QString::fromUtf8("background-color: rgb(28, 113, 216);\n"
"color: white;\n"
"font-weight: bold;"));

        gridLayout->addWidget(push_button_27, 4, 2, 1, 1);

        push_button_28 = new QPushButton(central_widget);
        push_button_28->setObjectName(QString::fromUtf8("push_button_28"));
        push_button_28->setMinimumSize(QSize(50, 50));
        push_button_28->setMaximumSize(QSize(50, 50));
        push_button_28->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: white;\n"
"    font-weight: bold;"));

        gridLayout->addWidget(push_button_28, 4, 3, 1, 1);

        push_button_29 = new QPushButton(central_widget);
        push_button_29->setObjectName(QString::fromUtf8("push_button_29"));
        push_button_29->setMinimumSize(QSize(50, 50));
        push_button_29->setMaximumSize(QSize(50, 50));
        push_button_29->setStyleSheet(QString::fromUtf8("background-color: rgb(28, 113, 216);\n"
"color: white;\n"
"font-weight: bold;"));

        gridLayout->addWidget(push_button_29, 4, 4, 1, 1);

        push_button_30 = new QPushButton(central_widget);
        push_button_30->setObjectName(QString::fromUtf8("push_button_30"));
        push_button_30->setMinimumSize(QSize(100, 50));
        push_button_30->setStyleSheet(QString::fromUtf8("background-color: orange; color: white; font-weight: bold;"));

        gridLayout->addWidget(push_button_30, 4, 5, 1, 1);


        gridLayout_2->addLayout(gridLayout, 2, 0, 1, 1);

        frame = new QFrame(central_widget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::HLine);
        frame->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(frame, 3, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        push_button_credit = new QPushButton(central_widget);
        push_button_credit->setObjectName(QString::fromUtf8("push_button_credit"));
        push_button_credit->setStyleSheet(QString::fromUtf8("background-color:rgb(26, 95, 180);\n"
"color: white;\n"
"font-weight: bold;"));

        horizontalLayout->addWidget(push_button_credit);

        push_button_deposit = new QPushButton(central_widget);
        push_button_deposit->setObjectName(QString::fromUtf8("push_button_deposit"));
        push_button_deposit->setStyleSheet(QString::fromUtf8("background-color:rgb(26, 95, 180);\n"
"color: white;\n"
"font-weight: bold;"));

        horizontalLayout->addWidget(push_button_deposit);

        push_button_graph = new QPushButton(central_widget);
        push_button_graph->setObjectName(QString::fromUtf8("push_button_graph"));
        push_button_graph->setStyleSheet(QString::fromUtf8("background-color:rgb(26, 95, 180);\n"
"color: white;\n"
"font-weight: bold;"));

        horizontalLayout->addWidget(push_button_graph);


        gridLayout_2->addLayout(horizontalLayout, 4, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);

        MainWindow->setCentralWidget(central_widget);
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
        push_button_set_x->setText(QCoreApplication::translate("MainWindow", "Set 'X'", nullptr));
#if QT_CONFIG(accessibility)
        push_button_8->setAccessibleName(QCoreApplication::translate("MainWindow", "c", nullptr));
#endif // QT_CONFIG(accessibility)
        push_button_8->setText(QCoreApplication::translate("MainWindow", "cos", nullptr));
#if QT_CONFIG(accessibility)
        push_button_1->setAccessibleName(QCoreApplication::translate("MainWindow", "l", nullptr));
#endif // QT_CONFIG(accessibility)
        push_button_1->setText(QCoreApplication::translate("MainWindow", "ln", nullptr));
#if QT_CONFIG(accessibility)
        push_button_14->setAccessibleName(QCoreApplication::translate("MainWindow", "s", nullptr));
#endif // QT_CONFIG(accessibility)
        push_button_14->setText(QCoreApplication::translate("MainWindow", "sin", nullptr));
#if QT_CONFIG(accessibility)
        push_button_19->setAccessibleName(QCoreApplication::translate("MainWindow", "v", nullptr));
#endif // QT_CONFIG(accessibility)
        push_button_19->setText(QCoreApplication::translate("MainWindow", "atan", nullptr));
#if QT_CONFIG(accessibility)
        push_button_20->setAccessibleName(QCoreApplication::translate("MainWindow", "t", nullptr));
#endif // QT_CONFIG(accessibility)
        push_button_20->setText(QCoreApplication::translate("MainWindow", "tan", nullptr));
#if QT_CONFIG(accessibility)
        push_button_16->setAccessibleName(QCoreApplication::translate("MainWindow", "5", nullptr));
#endif // QT_CONFIG(accessibility)
        push_button_16->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
#if QT_CONFIG(accessibility)
        push_button_10->setAccessibleName(QCoreApplication::translate("MainWindow", "2", nullptr));
#endif // QT_CONFIG(accessibility)
        push_button_10->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
#if QT_CONFIG(accessibility)
        push_button_23->setAccessibleName(QCoreApplication::translate("MainWindow", "9", nullptr));
#endif // QT_CONFIG(accessibility)
        push_button_23->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
#if QT_CONFIG(accessibility)
        push_button_9->setAccessibleName(QCoreApplication::translate("MainWindow", "1", nullptr));
#endif // QT_CONFIG(accessibility)
        push_button_9->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
#if QT_CONFIG(accessibility)
        push_button_17->setAccessibleName(QCoreApplication::translate("MainWindow", "6", nullptr));
#endif // QT_CONFIG(accessibility)
        push_button_17->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        push_button_3->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
#if QT_CONFIG(accessibility)
        push_button_15->setAccessibleName(QCoreApplication::translate("MainWindow", "4", nullptr));
#endif // QT_CONFIG(accessibility)
        push_button_15->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
#if QT_CONFIG(accessibility)
        push_button_13->setAccessibleName(QCoreApplication::translate("MainWindow", "i", nullptr));
#endif // QT_CONFIG(accessibility)
        push_button_13->setText(QCoreApplication::translate("MainWindow", "asin", nullptr));
#if QT_CONFIG(accessibility)
        push_button_12->setAccessibleName(QCoreApplication::translate("MainWindow", "-", nullptr));
#endif // QT_CONFIG(accessibility)
        push_button_12->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
#if QT_CONFIG(accessibility)
        push_button_18->setAccessibleName(QCoreApplication::translate("MainWindow", "*", nullptr));
#endif // QT_CONFIG(accessibility)
        push_button_18->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
#if QT_CONFIG(accessibility)
        push_button_22->setAccessibleName(QCoreApplication::translate("MainWindow", "8", nullptr));
#endif // QT_CONFIG(accessibility)
        push_button_22->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
#if QT_CONFIG(accessibility)
        push_button_11->setAccessibleName(QCoreApplication::translate("MainWindow", "3", nullptr));
#endif // QT_CONFIG(accessibility)
        push_button_11->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
#if QT_CONFIG(accessibility)
        push_button_5->setAccessibleName(QCoreApplication::translate("MainWindow", "(", nullptr));
#endif // QT_CONFIG(accessibility)
        push_button_5->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
#if QT_CONFIG(accessibility)
        push_button_2->setAccessibleName(QCoreApplication::translate("MainWindow", "o", nullptr));
#endif // QT_CONFIG(accessibility)
        push_button_2->setText(QCoreApplication::translate("MainWindow", "log", nullptr));
#if QT_CONFIG(accessibility)
        push_button_24->setAccessibleName(QCoreApplication::translate("MainWindow", "/", nullptr));
#endif // QT_CONFIG(accessibility)
        push_button_24->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
#if QT_CONFIG(accessibility)
        push_button_21->setAccessibleName(QCoreApplication::translate("MainWindow", "7", nullptr));
#endif // QT_CONFIG(accessibility)
        push_button_21->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
#if QT_CONFIG(accessibility)
        push_button_7->setAccessibleName(QCoreApplication::translate("MainWindow", "a", nullptr));
#endif // QT_CONFIG(accessibility)
        push_button_7->setText(QCoreApplication::translate("MainWindow", "acos", nullptr));
#if QT_CONFIG(accessibility)
        push_button_4->setAccessibleName(QCoreApplication::translate("MainWindow", "q", nullptr));
#endif // QT_CONFIG(accessibility)
        push_button_4->setText(QCoreApplication::translate("MainWindow", "sqrt", nullptr));
#if QT_CONFIG(accessibility)
        push_button_6->setAccessibleName(QCoreApplication::translate("MainWindow", "+", nullptr));
#endif // QT_CONFIG(accessibility)
        push_button_6->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
#if QT_CONFIG(accessibility)
        push_button_25->setAccessibleName(QCoreApplication::translate("MainWindow", "^", nullptr));
#endif // QT_CONFIG(accessibility)
        push_button_25->setText(QCoreApplication::translate("MainWindow", "x^y", nullptr));
#if QT_CONFIG(accessibility)
        push_button_26->setAccessibleName(QCoreApplication::translate("MainWindow", "m", nullptr));
#endif // QT_CONFIG(accessibility)
        push_button_26->setText(QCoreApplication::translate("MainWindow", "mod", nullptr));
#if QT_CONFIG(accessibility)
        push_button_27->setAccessibleName(QCoreApplication::translate("MainWindow", ".", nullptr));
#endif // QT_CONFIG(accessibility)
        push_button_27->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
#if QT_CONFIG(accessibility)
        push_button_28->setAccessibleName(QCoreApplication::translate("MainWindow", "0", nullptr));
#endif // QT_CONFIG(accessibility)
        push_button_28->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
#if QT_CONFIG(accessibility)
        push_button_29->setAccessibleName(QCoreApplication::translate("MainWindow", ")", nullptr));
#endif // QT_CONFIG(accessibility)
        push_button_29->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
#if QT_CONFIG(accessibility)
        push_button_30->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        push_button_30->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        push_button_credit->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214 \320\272\321\200\320\265\320\264\320\270\321\202", nullptr));
        push_button_deposit->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\321\205\320\276\320\264\320\275\320\276\321\201\321\202\321\214 \320\262\320\272\320\273\320\260\320\264\320\260", nullptr));
        push_button_graph->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
