#include "deposit_window.h"
#include "QDebug"
#include "ui_deposit_window.h"

deposit::deposit(QWidget *parent) : QDialog(parent), ui(new Ui::deposit) {
  ui->setupUi(this);
  ui->groupBox_deposits->setVisible(0);
  ui->groupBox_withdraws->setVisible(0);
  QDate date = QDate::currentDate();
  ui->dateEdit_start->setDate(date);
  ui->checkBox_capitalize->setChecked(1);
}

deposit::~deposit() { delete ui; }

void deposit::on_pushButton_clicked() //  Обработка нажатия "Пополнение"
{
  if (!ui->groupBox_deposits->isVisible()) {
    ui->groupBox_deposits->setVisible(1);
    QDate date = (QDate::currentDate()).addMonths(1);
    ui->dateEdit_2->setDate(date);
    ui->groupBox_additionalDeposit2->setVisible(0);
    ui->groupBox_additionalDeposit3->setVisible(0);
  } else if (!ui->groupBox_additionalDeposit2->isVisible()) {
    ui->groupBox_additionalDeposit2->setVisible(1);
    QDate date = (QDate::currentDate()).addMonths(2);
    ui->dateEdit_3->setDate(date);
    if (ui->groupBox_additionalDeposit3->isVisible())
      ui->pushButton_addDeposit->setEnabled(0);
  } else if (!ui->groupBox_additionalDeposit3->isVisible()) {
    ui->groupBox_additionalDeposit3->setVisible(1);
    QDate date = (QDate::currentDate()).addMonths(3);
    ui->dateEdit_4->setDate(date);
    ui->pushButton_addDeposit->setEnabled(0);
  }
}

void deposit::on_pushButton_2_clicked() //  Обработка "Снятие"
{
  if (!ui->groupBox_withdraws->isVisible()) {
    ui->groupBox_withdraws->setVisible(1);
    QDate date = (QDate::currentDate()).addMonths(1);
    ui->dateEdit_5->setDate(date);
    ui->groupBox_withdraw2->setVisible(0);
    ui->groupBox_withdraw3->setVisible(0);
  } else if (!ui->groupBox_withdraw2->isVisible()) {
    ui->groupBox_withdraw2->setVisible(1);
    QDate date = (QDate::currentDate()).addMonths(2);
    ui->dateEdit_6->setDate(date);
    if (ui->groupBox_withdraw3->isVisible())
      ui->pushButton_cashBack->setEnabled(0);
  } else if (!ui->groupBox_withdraw3->isVisible()) {
    ui->groupBox_withdraw3->setVisible(1);
    QDate date = (QDate::currentDate()).addMonths(3);
    ui->dateEdit_7->setDate(date);
    ui->pushButton_cashBack->setEnabled(0);
    ui->pushButton_cashBack->setEnabled(0);
  }
}

void deposit::on_pushButton_6_clicked() {
  ui->groupBox_additionalDeposit3->setVisible(0);
  ui->pushButton_addDeposit->setEnabled(1);
}

void deposit::on_pushButton_5_clicked() {
  ui->groupBox_additionalDeposit2->setVisible(0);
  ui->pushButton_addDeposit->setEnabled(1);
}

void deposit::on_pushButton_4_clicked() {
  if (ui->groupBox_additionalDeposit3->isVisible()) {
    ui->groupBox_additionalDeposit3->setVisible(0);
    ui->pushButton_addDeposit->setEnabled(1);
  } else if (ui->groupBox_additionalDeposit2->isVisible()) {
    ui->groupBox_additionalDeposit2->setVisible(0);
  } else {
    ui->groupBox_deposits->setVisible(0);
  }
}

void deposit::on_pushButton_3_clicked() //  Обработка кнопки "Рассчитать"
{
  if (ui->checkBox_capitalize->isChecked()) {
    double party_per_day =
        ui->lineEdit_rate->text().toDouble() / 365 / 100; //  Доля в день

    QDate finish = (ui->dateEdit_start->date())
                       .addMonths(ui->lineEdit_term->text().toInt());
    int dlit = (ui->dateEdit_start->date()).daysTo(finish);

    double sum_profit =
        profit(ui->lineEdit_amount->text().toDouble(), dlit, party_per_day);
    ui->label_7->setText(QString::number(sum_profit));

    double nalog = ui->lineEdit_tax->text().toDouble() / 100 * sum_profit;
    ui->label_11->setText(QString::number(nalog));

    ui->label_9->setText(ui->lineEdit_amount->text());
  } else {
    double sum_profit = 0.0;
    double party_per_day = ui->lineEdit_rate->text().toDouble() / 365 / 100;
    if (ui->groupBox_additionalDeposit1->isVisible()) {
      QDate end = ui->dateEdit_2->date();
      sum_profit =
          profit(ui->lineEdit_amount->text().toDouble(),
                 (ui->dateEdit_start->date()).daysTo(end), party_per_day);
    }
  }
}

void deposit::on_checkBox_stateChanged() {
  if (ui->checkBox_capitalize->isChecked()) {
    ui->pushButton_addDeposit->setEnabled(0);
    ui->pushButton_cashBack->setEnabled(0);
    ui->groupBox_deposits->setVisible(0);
    ui->groupBox_withdraws->setVisible(0);
  }
  if (!ui->checkBox_capitalize->isChecked()) {
    ui->pushButton_addDeposit->setEnabled(1);
    ui->pushButton_cashBack->setEnabled(1);
  }
}

void deposit::on_pushButton_9_clicked() {
  ui->groupBox_withdraw3->setVisible(0);
  ui->pushButton_cashBack->setEnabled(1);
}

void deposit::on_pushButton_8_clicked() {
  ui->groupBox_withdraw2->setVisible(0);
  ui->pushButton_cashBack->setEnabled(1);
}

void deposit::on_pushButton_7_clicked() {
  if (ui->groupBox_withdraw2->isVisible()) {
    ui->groupBox_withdraw2->setVisible(0);
    ui->pushButton_cashBack->setEnabled(1);
  } else if (ui->groupBox_withdraw3->isVisible()) {
    ui->groupBox_withdraw3->setVisible(0);
    ui->pushButton_cashBack->setEnabled(1);
  } else {
    ui->groupBox_withdraws->setVisible(0);
  }
}

double deposit::profit(double amount, int days, double rate) {
  double res = amount * days * rate;
  return res;
}
