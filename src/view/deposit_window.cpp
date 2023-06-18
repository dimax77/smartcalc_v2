#include "deposit_window.h"
#include "QDebug"
#include "ui_deposit_window.h"
#include <iostream>

deposit::deposit(QWidget *parent) : QDialog(parent), ui(new Ui::deposit) {
  ui->setupUi(this);
  ui->groupBox_deposits->setVisible(0);
  ui->groupBox_withdraws->setVisible(0);
  QDate date = QDate::currentDate();
  ui->dateEdit_start->setDate(date);
  ui->checkBox_capitalize->setChecked(1);
  deposits_.push_back({date, ui->lineEdit_amount->text().toDouble()});
  withdraws_.push_back({date, 0.0});
}

deposit::~deposit() { delete ui; }

void deposit::on_pushButton_addDeposit_clicked() {
  if (!ui->groupBox_deposits->isVisible()) {
    ui->groupBox_deposits->setVisible(1);
    QDate date = (QDate::currentDate()).addMonths(1);
    ui->dateEdit_deposit1->setDate(date);
    deposits_.push_back({date, ui->lineEdit_deposit1->text().toDouble()});
    ui->groupBox_additionalDeposit2->setVisible(0);
    ui->groupBox_additionalDeposit3->setVisible(0);
  } else if (!ui->groupBox_additionalDeposit2->isVisible()) {
    ui->groupBox_additionalDeposit2->setVisible(1);
    QDate date = (QDate::currentDate()).addMonths(2);
    ui->dateEdit_deposit2->setDate(date);
    deposits_.push_back({date, ui->lineEdit_deposit2->text().toDouble()});
  } else if (!ui->groupBox_additionalDeposit3->isVisible()) {
    ui->groupBox_additionalDeposit3->setVisible(1);
    QDate date = (QDate::currentDate()).addMonths(3);
    ui->dateEdit_deposit3->setDate(date);
    deposits_.push_back({date, ui->lineEdit_deposit3->text().toDouble()});
    ui->pushButton_addDeposit->setEnabled(0);
  }
}

void deposit::on_pushButton_cashBack_clicked() {
  if (!ui->groupBox_withdraws->isVisible()) {
    ui->groupBox_withdraws->setVisible(1);
    QDate date = (QDate::currentDate()).addMonths(1);
    ui->dateEdit_cashback1->setDate(date);
    withdraws_.push_back({date, ui->lineEdit_cashback1->text().toDouble()});
    ui->groupBox_withdraw2->setVisible(0);
    ui->groupBox_withdraw3->setVisible(0);
  } else if (!ui->groupBox_withdraw2->isVisible()) {
    ui->groupBox_withdraw2->setVisible(1);
    QDate date = (QDate::currentDate()).addMonths(2);
    ui->dateEdit_cashback2->setDate(date);
    withdraws_.push_back({date, ui->lineEdit_cashback2->text().toDouble()});
  } else if (!ui->groupBox_withdraw3->isVisible()) {
    ui->groupBox_withdraw3->setVisible(1);
    QDate date = (QDate::currentDate()).addMonths(3);
    ui->dateEdit_cashback3->setDate(date);
    withdraws_.push_back({date, ui->lineEdit_cashback3->text().toDouble()});
    ui->pushButton_cashBack->setEnabled(0);
  }
}

void deposit::on_pushButton_deposit3_clicked() {
  ui->groupBox_additionalDeposit3->setVisible(0);
  ui->pushButton_addDeposit->setEnabled(1);
  deposits_.pop_back();
}

void deposit::on_pushButton_deposit2_clicked() {

  if (ui->groupBox_additionalDeposit3->isVisible()) {
    on_pushButton_deposit3_clicked();
  } else {
    ui->groupBox_additionalDeposit2->setVisible(0);
    deposits_.pop_back();
  }
}

void deposit::on_pushButton_deposit1_clicked() {
  if (ui->groupBox_additionalDeposit3->isVisible()) {
    on_pushButton_deposit3_clicked();
  } else if (ui->groupBox_additionalDeposit2->isVisible()) {
    on_pushButton_deposit2_clicked();
  } else {
    ui->groupBox_deposits->setVisible(0);
    deposits_.pop_back();
  }
}

void deposit::on_pushButton_calculate_clicked() {

  if (ui->checkBox_capitalize->isChecked()) {
    double party_per_day = ui->lineEdit_rate->text().toDouble() / 365 / 100;
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
      QDate end = ui->dateEdit_deposit1->date();
      sum_profit =
          profit(ui->lineEdit_amount->text().toDouble(),
                 (ui->dateEdit_start->date()).daysTo(end), party_per_day);
    }
  }
  std::vector<double> result{};
  //  try {
  //    result = ctrl_->processDepositeData(
  //        deposits_, withdraws_, ui->lineEdit_tax->text().toDouble(),
  //        ui->lineEdit_rate->text().toDouble(),
  //        ui->lineEdit_term->text().toUInt(),
  //        ui->comboBox_withdrawInterval->currentIndex());
  //  } catch (...) {
  //    ui->label_9->setText("Error");
  //  }
}

void deposit::on_checkBox_capitalize_stateChanged() {
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

void deposit::on_pushButton_cashback3_clicked() {
  ui->groupBox_withdraw3->setVisible(0);
  ui->pushButton_cashBack->setEnabled(1);
  withdraws_.pop_back();
}

void deposit::on_pushButton_cashback2_clicked() {
  if (ui->groupBox_withdraw3->isVisible()) {
    on_pushButton_cashback3_clicked();
  } else if (ui->groupBox_withdraw2->isVisible()) {
    on_pushButton_withdrawDelete2_clicked();
  } else {
    ui->groupBox_withdraws->setVisible(0);
    withdraws_.pop_back();
  }
}

void deposit::on_dateEdit_2_userDateChanged(const QDate &date) {
  deposits_[1].first = date;
  std::cout << "Date changed" << std::endl;
}

void deposit::on_dateEdit_3_userDateChanged(const QDate &date) {
  deposits_[2].first = date;
}

void deposit::on_dateEdit_4_userDateChanged(const QDate &date) {
  deposits_[3].first = date;
}

void deposit::on_dateEdit_5_userDateChanged(const QDate &date) {
  withdraws_[1].first = date;
}

void deposit::on_dateEdit_6_userDateChanged(const QDate &date) {
  withdraws_[2].first = date;
}

void deposit::on_dateEdit_7_userDateChanged(const QDate &date) {
  withdraws_[3].first = date;
}

double deposit::profit(double amount, int days, double rate) {
  double res = amount * days * rate;
  return res;
}

void deposit::on_pushButton_withdrawDelete2_clicked() {
  if (ui->groupBox_withdraw3->isVisible()) {
    on_pushButton_cashback3_clicked();
  } else {
    ui->groupBox_withdraw2->setVisible(0);
    withdraws_.pop_back();
  }
}

void deposit::on_lineEdit_amount_textChanged(const QString &arg1) {
  deposits_[0].second = arg1.toDouble();
  std::cout << "amount changed" << std::endl;
}

void deposit::on_lineEdit_5_textChanged(const QString &arg1) {
  deposits_[1].second = arg1.toDouble();
}

void deposit::on_lineEdit_6_textChanged(const QString &arg1) {
  deposits_[2].second = arg1.toDouble();
}

void deposit::on_lineEdit_7_textChanged(const QString &arg1) {
  deposits_[3].second = arg1.toDouble();
}

void deposit::on_lineEdit_8_textChanged(const QString &arg1) {
  withdraws_[1].second = arg1.toDouble();
}

void deposit::on_lineEdit_9_textChanged(const QString &arg1) {
  withdraws_[2].second = arg1.toDouble();
}

void deposit::on_lineEdit_10_textChanged(const QString &arg1) {
  withdraws_[3].second = arg1.toDouble();
}
