/********************************************************************************
** Form generated from reading UI file 'deposit_window.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPOSIT_WINDOW_H
#define UI_DEPOSIT_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_deposit
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label;
    QLineEdit *lineEdit_amount;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_2;
    QLineEdit *lineEdit_term;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_3;
    QLineEdit *lineEdit_tax;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_4;
    QLineEdit *lineEdit_rate;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_6;
    QDateEdit *dateEdit_start;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_5;
    QComboBox *comboBox_withdrawInterval;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer;
    QCheckBox *checkBox_capitalize;
    QHBoxLayout *horizontalLayout_13;
    QPushButton *pushButton_addDeposit;
    QPushButton *pushButton_cashBack;
    QPushButton *pushButton_calculate;
    QGroupBox *groupBox_deposits;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_additionalDeposit3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QDateEdit *dateEdit_deposit3;
    QLineEdit *lineEdit_deposit3;
    QPushButton *pushButton_deposit3;
    QGroupBox *groupBox_additionalDeposit1;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QDateEdit *dateEdit_deposit1;
    QLineEdit *lineEdit_deposit1;
    QPushButton *pushButton_deposit1;
    QGroupBox *groupBox_additionalDeposit2;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QDateEdit *dateEdit_deposit2;
    QLineEdit *lineEdit_deposit2;
    QPushButton *pushButton_deposit2;
    QGroupBox *groupBox_withdraws;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_withdraw1;
    QWidget *layoutWidget3;
    QGridLayout *gridLayout_2;
    QDateEdit *dateEdit_cashback1;
    QLineEdit *lineEdit_cashback1;
    QPushButton *pushButton_cashback1;
    QGroupBox *groupBox_withdraw2;
    QWidget *layoutWidget_2;
    QGridLayout *gridLayout_3;
    QDateEdit *dateEdit_cashback2;
    QLineEdit *lineEdit_cashback2;
    QPushButton *pushButton_cashback2;
    QGroupBox *groupBox_withdraw3;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_16;
    QDateEdit *dateEdit_cashback3;
    QLineEdit *lineEdit_cashback3;
    QPushButton *pushButton_cashback3;
    QGroupBox *groupBox_result;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_10;
    QLabel *label_8;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
    QLabel *label_11;
    QLabel *label_9;

    void setupUi(QDialog *deposit)
    {
        if (deposit->objectName().isEmpty())
            deposit->setObjectName(QString::fromUtf8("deposit"));
        deposit->resize(386, 715);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(deposit->sizePolicy().hasHeightForWidth());
        deposit->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(deposit);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label = new QLabel(deposit);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_7->addWidget(label);

        lineEdit_amount = new QLineEdit(deposit);
        lineEdit_amount->setObjectName(QString::fromUtf8("lineEdit_amount"));

        horizontalLayout_7->addWidget(lineEdit_amount);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_2 = new QLabel(deposit);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_8->addWidget(label_2);

        lineEdit_term = new QLineEdit(deposit);
        lineEdit_term->setObjectName(QString::fromUtf8("lineEdit_term"));

        horizontalLayout_8->addWidget(lineEdit_term);

        comboBox = new QComboBox(deposit);
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_8->addWidget(comboBox);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_3 = new QLabel(deposit);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_9->addWidget(label_3);

        lineEdit_tax = new QLineEdit(deposit);
        lineEdit_tax->setObjectName(QString::fromUtf8("lineEdit_tax"));

        horizontalLayout_9->addWidget(lineEdit_tax);


        verticalLayout_3->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_4 = new QLabel(deposit);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_10->addWidget(label_4);

        lineEdit_rate = new QLineEdit(deposit);
        lineEdit_rate->setObjectName(QString::fromUtf8("lineEdit_rate"));

        horizontalLayout_10->addWidget(lineEdit_rate);


        verticalLayout_3->addLayout(horizontalLayout_10);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_6 = new QLabel(deposit);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_14->addWidget(label_6);

        dateEdit_start = new QDateEdit(deposit);
        dateEdit_start->setObjectName(QString::fromUtf8("dateEdit_start"));
        dateEdit_start->setCalendarPopup(true);

        horizontalLayout_14->addWidget(dateEdit_start);


        verticalLayout_3->addLayout(horizontalLayout_14);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_5 = new QLabel(deposit);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_11->addWidget(label_5);

        comboBox_withdrawInterval = new QComboBox(deposit);
        comboBox_withdrawInterval->addItem(QString());
        comboBox_withdrawInterval->addItem(QString());
        comboBox_withdrawInterval->setObjectName(QString::fromUtf8("comboBox_withdrawInterval"));

        horizontalLayout_11->addWidget(comboBox_withdrawInterval);


        verticalLayout_3->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer);

        checkBox_capitalize = new QCheckBox(deposit);
        checkBox_capitalize->setObjectName(QString::fromUtf8("checkBox_capitalize"));
        checkBox_capitalize->setChecked(false);

        horizontalLayout_12->addWidget(checkBox_capitalize);


        verticalLayout_3->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        pushButton_addDeposit = new QPushButton(deposit);
        pushButton_addDeposit->setObjectName(QString::fromUtf8("pushButton_addDeposit"));

        horizontalLayout_13->addWidget(pushButton_addDeposit);

        pushButton_cashBack = new QPushButton(deposit);
        pushButton_cashBack->setObjectName(QString::fromUtf8("pushButton_cashBack"));

        horizontalLayout_13->addWidget(pushButton_cashBack);

        pushButton_calculate = new QPushButton(deposit);
        pushButton_calculate->setObjectName(QString::fromUtf8("pushButton_calculate"));

        horizontalLayout_13->addWidget(pushButton_calculate);


        verticalLayout_3->addLayout(horizontalLayout_13);

        groupBox_deposits = new QGroupBox(deposit);
        groupBox_deposits->setObjectName(QString::fromUtf8("groupBox_deposits"));
        gridLayout = new QGridLayout(groupBox_deposits);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_additionalDeposit3 = new QGroupBox(groupBox_deposits);
        groupBox_additionalDeposit3->setObjectName(QString::fromUtf8("groupBox_additionalDeposit3"));
        layoutWidget = new QWidget(groupBox_additionalDeposit3);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 315, 28));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        dateEdit_deposit3 = new QDateEdit(layoutWidget);
        dateEdit_deposit3->setObjectName(QString::fromUtf8("dateEdit_deposit3"));
        dateEdit_deposit3->setCalendarPopup(true);

        horizontalLayout_3->addWidget(dateEdit_deposit3);

        lineEdit_deposit3 = new QLineEdit(layoutWidget);
        lineEdit_deposit3->setObjectName(QString::fromUtf8("lineEdit_deposit3"));

        horizontalLayout_3->addWidget(lineEdit_deposit3);

        pushButton_deposit3 = new QPushButton(layoutWidget);
        pushButton_deposit3->setObjectName(QString::fromUtf8("pushButton_deposit3"));

        horizontalLayout_3->addWidget(pushButton_deposit3);


        gridLayout->addWidget(groupBox_additionalDeposit3, 2, 0, 1, 1);

        groupBox_additionalDeposit1 = new QGroupBox(groupBox_deposits);
        groupBox_additionalDeposit1->setObjectName(QString::fromUtf8("groupBox_additionalDeposit1"));
        layoutWidget1 = new QWidget(groupBox_additionalDeposit1);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 10, 315, 28));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        dateEdit_deposit1 = new QDateEdit(layoutWidget1);
        dateEdit_deposit1->setObjectName(QString::fromUtf8("dateEdit_deposit1"));
        dateEdit_deposit1->setCalendarPopup(true);

        horizontalLayout->addWidget(dateEdit_deposit1);

        lineEdit_deposit1 = new QLineEdit(layoutWidget1);
        lineEdit_deposit1->setObjectName(QString::fromUtf8("lineEdit_deposit1"));

        horizontalLayout->addWidget(lineEdit_deposit1);

        pushButton_deposit1 = new QPushButton(layoutWidget1);
        pushButton_deposit1->setObjectName(QString::fromUtf8("pushButton_deposit1"));

        horizontalLayout->addWidget(pushButton_deposit1);


        gridLayout->addWidget(groupBox_additionalDeposit1, 0, 0, 1, 1);

        groupBox_additionalDeposit2 = new QGroupBox(groupBox_deposits);
        groupBox_additionalDeposit2->setObjectName(QString::fromUtf8("groupBox_additionalDeposit2"));
        layoutWidget2 = new QWidget(groupBox_additionalDeposit2);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 10, 315, 28));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        dateEdit_deposit2 = new QDateEdit(layoutWidget2);
        dateEdit_deposit2->setObjectName(QString::fromUtf8("dateEdit_deposit2"));
        dateEdit_deposit2->setCalendarPopup(true);

        horizontalLayout_2->addWidget(dateEdit_deposit2);

        lineEdit_deposit2 = new QLineEdit(layoutWidget2);
        lineEdit_deposit2->setObjectName(QString::fromUtf8("lineEdit_deposit2"));

        horizontalLayout_2->addWidget(lineEdit_deposit2);

        pushButton_deposit2 = new QPushButton(layoutWidget2);
        pushButton_deposit2->setObjectName(QString::fromUtf8("pushButton_deposit2"));

        horizontalLayout_2->addWidget(pushButton_deposit2);


        gridLayout->addWidget(groupBox_additionalDeposit2, 1, 0, 1, 1);


        verticalLayout_3->addWidget(groupBox_deposits);

        groupBox_withdraws = new QGroupBox(deposit);
        groupBox_withdraws->setObjectName(QString::fromUtf8("groupBox_withdraws"));
        verticalLayout_2 = new QVBoxLayout(groupBox_withdraws);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox_withdraw1 = new QGroupBox(groupBox_withdraws);
        groupBox_withdraw1->setObjectName(QString::fromUtf8("groupBox_withdraw1"));
        layoutWidget3 = new QWidget(groupBox_withdraw1);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 0, 315, 28));
        gridLayout_2 = new QGridLayout(layoutWidget3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        dateEdit_cashback1 = new QDateEdit(layoutWidget3);
        dateEdit_cashback1->setObjectName(QString::fromUtf8("dateEdit_cashback1"));
        dateEdit_cashback1->setAcceptDrops(false);
        dateEdit_cashback1->setCalendarPopup(true);

        gridLayout_2->addWidget(dateEdit_cashback1, 0, 0, 1, 1);

        lineEdit_cashback1 = new QLineEdit(layoutWidget3);
        lineEdit_cashback1->setObjectName(QString::fromUtf8("lineEdit_cashback1"));

        gridLayout_2->addWidget(lineEdit_cashback1, 0, 1, 1, 1);

        pushButton_cashback1 = new QPushButton(layoutWidget3);
        pushButton_cashback1->setObjectName(QString::fromUtf8("pushButton_cashback1"));

        gridLayout_2->addWidget(pushButton_cashback1, 0, 2, 1, 1);


        verticalLayout_2->addWidget(groupBox_withdraw1);

        groupBox_withdraw2 = new QGroupBox(groupBox_withdraws);
        groupBox_withdraw2->setObjectName(QString::fromUtf8("groupBox_withdraw2"));
        layoutWidget_2 = new QWidget(groupBox_withdraw2);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 10, 315, 28));
        gridLayout_3 = new QGridLayout(layoutWidget_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        dateEdit_cashback2 = new QDateEdit(layoutWidget_2);
        dateEdit_cashback2->setObjectName(QString::fromUtf8("dateEdit_cashback2"));
        dateEdit_cashback2->setAcceptDrops(false);
        dateEdit_cashback2->setCalendarPopup(true);

        gridLayout_3->addWidget(dateEdit_cashback2, 0, 0, 1, 1);

        lineEdit_cashback2 = new QLineEdit(layoutWidget_2);
        lineEdit_cashback2->setObjectName(QString::fromUtf8("lineEdit_cashback2"));

        gridLayout_3->addWidget(lineEdit_cashback2, 0, 1, 1, 1);

        pushButton_cashback2 = new QPushButton(layoutWidget_2);
        pushButton_cashback2->setObjectName(QString::fromUtf8("pushButton_cashback2"));

        gridLayout_3->addWidget(pushButton_cashback2, 0, 2, 1, 1);


        verticalLayout_2->addWidget(groupBox_withdraw2);

        groupBox_withdraw3 = new QGroupBox(groupBox_withdraws);
        groupBox_withdraw3->setObjectName(QString::fromUtf8("groupBox_withdraw3"));
        layoutWidget_3 = new QWidget(groupBox_withdraw3);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(10, 0, 315, 28));
        horizontalLayout_16 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        horizontalLayout_16->setContentsMargins(0, 0, 0, 0);
        dateEdit_cashback3 = new QDateEdit(layoutWidget_3);
        dateEdit_cashback3->setObjectName(QString::fromUtf8("dateEdit_cashback3"));
        dateEdit_cashback3->setAcceptDrops(false);
        dateEdit_cashback3->setCalendarPopup(true);

        horizontalLayout_16->addWidget(dateEdit_cashback3);

        lineEdit_cashback3 = new QLineEdit(layoutWidget_3);
        lineEdit_cashback3->setObjectName(QString::fromUtf8("lineEdit_cashback3"));

        horizontalLayout_16->addWidget(lineEdit_cashback3);

        pushButton_cashback3 = new QPushButton(layoutWidget_3);
        pushButton_cashback3->setObjectName(QString::fromUtf8("pushButton_cashback3"));

        horizontalLayout_16->addWidget(pushButton_cashback3);


        verticalLayout_2->addWidget(groupBox_withdraw3);


        verticalLayout_3->addWidget(groupBox_withdraws);

        groupBox_result = new QGroupBox(deposit);
        groupBox_result->setObjectName(QString::fromUtf8("groupBox_result"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_result->sizePolicy().hasHeightForWidth());
        groupBox_result->setSizePolicy(sizePolicy1);
        verticalLayout = new QVBoxLayout(groupBox_result);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_10 = new QLabel(groupBox_result);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_4->addWidget(label_10);

        label_8 = new QLabel(groupBox_result);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_4->addWidget(label_8);

        label_12 = new QLabel(groupBox_result);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_4->addWidget(label_12);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_7 = new QLabel(groupBox_result);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_5->addWidget(label_7);

        label_11 = new QLabel(groupBox_result);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_5->addWidget(label_11);

        label_9 = new QLabel(groupBox_result);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_5->addWidget(label_9);


        verticalLayout->addLayout(horizontalLayout_5);


        verticalLayout_3->addWidget(groupBox_result);


        retranslateUi(deposit);

        comboBox->setCurrentIndex(0);
        comboBox_withdrawInterval->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(deposit);
    } // setupUi

    void retranslateUi(QDialog *deposit)
    {
        deposit->setWindowTitle(QCoreApplication::translate("deposit", "\320\224\320\265\320\277\320\276\320\267\320\270\321\202\320\275\321\213\320\271 \320\272\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200", nullptr));
        label->setText(QCoreApplication::translate("deposit", "\320\241\321\203\320\274\320\274\320\260 \320\262\320\272\320\273\320\260\320\264\320\260, \321\200\321\203\320\261", nullptr));
        lineEdit_amount->setText(QCoreApplication::translate("deposit", "1000000", nullptr));
        label_2->setText(QCoreApplication::translate("deposit", "\320\241\321\200\320\276\320\272 \321\200\320\260\320\267\320\274\320\265\321\211\320\265\320\275\320\270\321\217", nullptr));
        lineEdit_term->setText(QCoreApplication::translate("deposit", "12", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("deposit", "\320\274\320\265\321\201.", nullptr));

        label_3->setText(QCoreApplication::translate("deposit", "\320\235\320\260\320\273\320\276\320\263\320\276\320\262\320\260\321\217 \321\201\321\202\320\260\320\262\320\272\320\260, %", nullptr));
        lineEdit_tax->setText(QCoreApplication::translate("deposit", "0", nullptr));
        label_4->setText(QCoreApplication::translate("deposit", "\320\237\321\200\320\276\321\206\320\265\320\275\321\202\320\275\320\260\321\217 \321\201\321\202\320\260\320\262\320\272\320\260, %", nullptr));
        lineEdit_rate->setText(QCoreApplication::translate("deposit", "7", nullptr));
        label_6->setText(QCoreApplication::translate("deposit", "\320\224\320\260\321\202\320\260 \320\275\320\260\321\207\320\260\320\273\320\260", nullptr));
        label_5->setText(QCoreApplication::translate("deposit", "\320\237\320\265\321\200\320\270\320\276\320\264\320\270\321\207\320\275\320\276\321\201\321\202\321\214 \320\262\321\213\320\277\320\273\320\260\321\202", nullptr));
        comboBox_withdrawInterval->setItemText(0, QCoreApplication::translate("deposit", "\320\222 \320\272\320\276\320\275\321\206\320\265 \321\201\321\200\320\276\320\272\320\260", nullptr));
        comboBox_withdrawInterval->setItemText(1, QCoreApplication::translate("deposit", "\320\240\320\260\320\267 \320\262 \320\274\320\265\321\201\321\217\321\206", nullptr));

        checkBox_capitalize->setText(QCoreApplication::translate("deposit", "\320\232\320\260\320\277\320\270\321\202\320\260\320\273\320\270\320\267\320\260\321\206\320\270\321\217 \320\277\321\200\320\276\321\206\320\265\320\275\321\202\320\276\320\262", nullptr));
        pushButton_addDeposit->setText(QCoreApplication::translate("deposit", "+ \320\237\320\276\320\277\320\276\320\273\320\275\320\265\320\275\320\270\320\265", nullptr));
        pushButton_cashBack->setText(QCoreApplication::translate("deposit", "+ \320\241\320\275\321\217\321\202\320\270\320\265", nullptr));
        pushButton_calculate->setText(QCoreApplication::translate("deposit", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        groupBox_deposits->setTitle(QCoreApplication::translate("deposit", "\320\237\320\276\320\277\320\276\320\273\320\275\320\265\320\275\320\270\321\217", nullptr));
        groupBox_additionalDeposit3->setTitle(QString());
        lineEdit_deposit3->setText(QCoreApplication::translate("deposit", "50000", nullptr));
        pushButton_deposit3->setText(QCoreApplication::translate("deposit", "X", nullptr));
        groupBox_additionalDeposit1->setTitle(QString());
        lineEdit_deposit1->setText(QCoreApplication::translate("deposit", "50000", nullptr));
        pushButton_deposit1->setText(QCoreApplication::translate("deposit", "X", nullptr));
        groupBox_additionalDeposit2->setTitle(QString());
        lineEdit_deposit2->setText(QCoreApplication::translate("deposit", "50000", nullptr));
        pushButton_deposit2->setText(QCoreApplication::translate("deposit", "X", nullptr));
        groupBox_withdraws->setTitle(QCoreApplication::translate("deposit", "\320\241\320\275\321\217\321\202\320\270\321\217", nullptr));
        groupBox_withdraw1->setTitle(QString());
        lineEdit_cashback1->setText(QCoreApplication::translate("deposit", "50000", nullptr));
        pushButton_cashback1->setText(QCoreApplication::translate("deposit", "X", nullptr));
        groupBox_withdraw2->setTitle(QString());
        lineEdit_cashback2->setText(QCoreApplication::translate("deposit", "50000", nullptr));
        pushButton_cashback2->setText(QCoreApplication::translate("deposit", "X", nullptr));
        groupBox_withdraw3->setTitle(QString());
        lineEdit_cashback3->setText(QCoreApplication::translate("deposit", "50000", nullptr));
        pushButton_cashback3->setText(QCoreApplication::translate("deposit", "X", nullptr));
        groupBox_result->setTitle(QCoreApplication::translate("deposit", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202", nullptr));
        label_10->setText(QCoreApplication::translate("deposit", "\320\237\321\200\320\276\321\206\320\265\320\275\321\202\321\213", nullptr));
        label_8->setText(QCoreApplication::translate("deposit", "\320\235\320\260\320\273\320\276\320\263", nullptr));
        label_12->setText(QCoreApplication::translate("deposit", "\320\241\321\203\320\274\320\274\320\260 \320\275\320\260 \320\262\320\272\320\273\320\260\320\264\320\265", nullptr));
        label_7->setText(QString());
        label_11->setText(QString());
        label_9->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class deposit: public Ui_deposit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPOSIT_WINDOW_H
