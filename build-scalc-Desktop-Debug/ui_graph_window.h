/********************************************************************************
** Form generated from reading UI file 'graph_window.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPH_WINDOW_H
#define UI_GRAPH_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include "libs/qcustomplot/qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_graph
{
public:
    QVBoxLayout *verticalLayout;
    QCustomPlot *widget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_xmin;
    QLineEdit *lineEdit_func;
    QLabel *label_6;
    QLineEdit *lineEdit_xmax;
    QLineEdit *lineEdit_ymin;
    QPushButton *pushButton_plot;
    QLabel *label_2;
    QLabel *label_5;
    QLineEdit *lineEdit_ymax;
    QLabel *label_7;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label;
    QLabel *label_8;

    void setupUi(QDialog *graph)
    {
        if (graph->objectName().isEmpty())
            graph->setObjectName(QString::fromUtf8("graph"));
        graph->resize(538, 318);
        verticalLayout = new QVBoxLayout(graph);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QCustomPlot(graph);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 190));
        widget->setMaximumSize(QSize(16777215, 190));

        verticalLayout->addWidget(widget);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit_xmin = new QLineEdit(graph);
        lineEdit_xmin->setObjectName(QString::fromUtf8("lineEdit_xmin"));

        gridLayout->addWidget(lineEdit_xmin, 2, 0, 1, 1);

        lineEdit_func = new QLineEdit(graph);
        lineEdit_func->setObjectName(QString::fromUtf8("lineEdit_func"));
        lineEdit_func->setEnabled(false);

        gridLayout->addWidget(lineEdit_func, 1, 4, 1, 1);

        label_6 = new QLabel(graph);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 1, 3, 1, 1);

        lineEdit_xmax = new QLineEdit(graph);
        lineEdit_xmax->setObjectName(QString::fromUtf8("lineEdit_xmax"));

        gridLayout->addWidget(lineEdit_xmax, 2, 1, 1, 1);

        lineEdit_ymin = new QLineEdit(graph);
        lineEdit_ymin->setObjectName(QString::fromUtf8("lineEdit_ymin"));

        gridLayout->addWidget(lineEdit_ymin, 2, 2, 1, 1);

        pushButton_plot = new QPushButton(graph);
        pushButton_plot->setObjectName(QString::fromUtf8("pushButton_plot"));

        gridLayout->addWidget(pushButton_plot, 2, 4, 1, 1);

        label_2 = new QLabel(graph);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_5 = new QLabel(graph);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 1, 2, 1, 1);

        lineEdit_ymax = new QLineEdit(graph);
        lineEdit_ymax->setObjectName(QString::fromUtf8("lineEdit_ymax"));

        gridLayout->addWidget(lineEdit_ymax, 2, 3, 1, 1);

        label_7 = new QLabel(graph);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 0, 4, 1, 1);

        label_3 = new QLabel(graph);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 1, 1, 1);

        label_4 = new QLabel(graph);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 2, 1, 2);

        label = new QLabel(graph);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 2);


        verticalLayout->addLayout(gridLayout);

        label_8 = new QLabel(graph);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout->addWidget(label_8);


        retranslateUi(graph);

        QMetaObject::connectSlotsByName(graph);
    } // setupUi

    void retranslateUi(QDialog *graph)
    {
        graph->setWindowTitle(QCoreApplication::translate("graph", "\320\223\321\200\320\260\321\204\320\270\320\272", nullptr));
        label_6->setText(QCoreApplication::translate("graph", "y, max", nullptr));
        pushButton_plot->setText(QCoreApplication::translate("graph", "\320\237\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214", nullptr));
        label_2->setText(QCoreApplication::translate("graph", "x, min", nullptr));
        label_5->setText(QCoreApplication::translate("graph", "y, min", nullptr));
        label_7->setText(QCoreApplication::translate("graph", "\320\244\321\203\320\275\320\272\321\206\320\270\321\217:", nullptr));
        label_3->setText(QCoreApplication::translate("graph", "x, max", nullptr));
        label_4->setText(QCoreApplication::translate("graph", "\320\236\320\261\320\273\320\260\321\201\321\202\321\214 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\271:", nullptr));
        label->setText(QCoreApplication::translate("graph", "\320\236\320\261\320\273\320\260\321\201\321\202\321\214 \320\276\320\277\321\200\320\265\320\264\320\265\320\273\320\265\320\275\320\270\321\217:", nullptr));
        label_8->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class graph: public Ui_graph {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPH_WINDOW_H
