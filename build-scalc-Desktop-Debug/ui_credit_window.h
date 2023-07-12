/********************************************************************************
** Form generated from reading UI file 'credit_window.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREDIT_WINDOW_H
#define UI_CREDIT_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_credit
{
public:
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_term;
    QComboBox *comboBox;
    QLabel *label_4;
    QLineEdit *lineEdit_interestRate;
    QLabel *label_5;
    QRadioButton *radioButton_annuit;
    QSpacerItem *horizontalSpacer;
    QRadioButton *radioButton_diff;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLabel *label_monthlyPayment;
    QLabel *label_6;
    QLabel *label_accruedInterest;
    QLabel *label_7;
    QLabel *label_total;
    QLineEdit *lineEdit_amount;
    QPushButton *pushButton;

    void setupUi(QDialog *credit)
    {
        if (credit->objectName().isEmpty())
            credit->setObjectName(QString::fromUtf8("credit"));
        credit->resize(415, 310);
        gridLayout = new QGridLayout(credit);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(credit);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_3 = new QLabel(credit);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        lineEdit_term = new QLineEdit(credit);
        lineEdit_term->setObjectName(QString::fromUtf8("lineEdit_term"));

        gridLayout->addWidget(lineEdit_term, 1, 1, 1, 1);

        comboBox = new QComboBox(credit);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 1, 2, 1, 1);

        label_4 = new QLabel(credit);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        lineEdit_interestRate = new QLineEdit(credit);
        lineEdit_interestRate->setObjectName(QString::fromUtf8("lineEdit_interestRate"));

        gridLayout->addWidget(lineEdit_interestRate, 2, 1, 1, 1);

        label_5 = new QLabel(credit);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        radioButton_annuit = new QRadioButton(credit);
        radioButton_annuit->setObjectName(QString::fromUtf8("radioButton_annuit"));
        radioButton_annuit->setChecked(true);

        gridLayout->addWidget(radioButton_annuit, 3, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(179, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 0, 1, 1);

        radioButton_diff = new QRadioButton(credit);
        radioButton_diff->setObjectName(QString::fromUtf8("radioButton_diff"));

        gridLayout->addWidget(radioButton_diff, 4, 1, 1, 2);

        groupBox = new QGroupBox(credit);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setEnabled(true);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_monthlyPayment = new QLabel(groupBox);
        label_monthlyPayment->setObjectName(QString::fromUtf8("label_monthlyPayment"));

        gridLayout_2->addWidget(label_monthlyPayment, 0, 1, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 1, 0, 1, 1);

        label_accruedInterest = new QLabel(groupBox);
        label_accruedInterest->setObjectName(QString::fromUtf8("label_accruedInterest"));

        gridLayout_2->addWidget(label_accruedInterest, 1, 1, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 2, 0, 1, 1);

        label_total = new QLabel(groupBox);
        label_total->setObjectName(QString::fromUtf8("label_total"));

        gridLayout_2->addWidget(label_total, 2, 1, 1, 1);


        gridLayout->addWidget(groupBox, 6, 0, 1, 3);

        lineEdit_amount = new QLineEdit(credit);
        lineEdit_amount->setObjectName(QString::fromUtf8("lineEdit_amount"));

        gridLayout->addWidget(lineEdit_amount, 0, 1, 1, 2);

        pushButton = new QPushButton(credit);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setEnabled(false);

        gridLayout->addWidget(pushButton, 5, 0, 1, 3);


        retranslateUi(credit);

        comboBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(credit);
    } // setupUi

    void retranslateUi(QDialog *credit)
    {
        credit->setWindowTitle(QCoreApplication::translate("credit", "\320\232\321\200\320\265\320\264\320\270\321\202\320\275\321\213\320\271 \320\272\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200", nullptr));
        label_2->setText(QCoreApplication::translate("credit", "\320\241\321\203\320\274\320\274\320\260 \320\272\321\200\320\265\320\264\320\270\321\202\320\260, \321\200\321\203\320\261.", nullptr));
        label_3->setText(QCoreApplication::translate("credit", "\320\241\321\200\320\276\320\272 \320\272\321\200\320\265\320\264\320\270\321\202\320\260", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("credit", "\320\263\320\276\320\264", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("credit", "\320\274\320\265\321\201.", nullptr));

        label_4->setText(QCoreApplication::translate("credit", "\320\237\321\200\320\276\321\206\320\265\320\275\321\202\320\275\320\260\321\217 \321\201\321\202\320\260\320\262\320\272\320\260, %", nullptr));
        label_5->setText(QCoreApplication::translate("credit", "\320\242\320\270\320\277 \320\265\320\266\320\265\320\274\320\265\321\201\321\217\321\207\320\275\321\213\321\205 \320\277\320\273\320\260\321\202\320\265\320\266\320\265\320\271", nullptr));
        radioButton_annuit->setText(QCoreApplication::translate("credit", "\320\220\320\275\320\275\321\203\320\270\321\202\320\265\321\202\320\275\321\213\320\265", nullptr));
        radioButton_diff->setText(QCoreApplication::translate("credit", "\320\224\320\270\321\204\321\204\320\265\321\200\320\265\320\275\321\206\320\270\321\200\320\276\320\262\320\260\320\275\320\275\321\213\320\265", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("credit", "\320\225\320\266\320\265\320\274\320\265\321\201\321\217\321\207\320\275\321\213\320\271 \320\277\320\273\320\260\321\202\320\265\320\266", nullptr));
        label_monthlyPayment->setText(QCoreApplication::translate("credit", "TextLabel", nullptr));
        label_6->setText(QCoreApplication::translate("credit", "\320\235\320\260\321\207\320\270\321\201\320\273\320\265\320\275\320\275\321\213\320\265 \320\277\321\200\320\276\321\206\320\265\320\275\321\202\321\213", nullptr));
        label_accruedInterest->setText(QCoreApplication::translate("credit", "TextLabel", nullptr));
        label_7->setText(QCoreApplication::translate("credit", "\320\224\320\276\320\273\320\263 + \320\237\321\200\320\276\321\206\320\265\320\275\321\202\321\213", nullptr));
        label_total->setText(QCoreApplication::translate("credit", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("credit", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class credit: public Ui_credit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREDIT_WINDOW_H
