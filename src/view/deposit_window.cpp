#include "deposit_window.h"
#include "ui_deposit_window.h"
#include <QValidator>

Deposit::Deposit(s21::Controller *ctrl, QWidget *parent)
    : QDialog(parent), ui(new Ui::deposit), ctrl_(ctrl) {
  ui->setupUi(this);
  ui->groupBox_deposits->setVisible(0);
  ui->groupBox_withdraws->setVisible(0);
  QDate date = QDate::currentDate();
  ui->dateEdit_start->setDate(date);
  ui->checkBox_capitalize->setChecked(1);
  deposits_.push_back({date, ui->lineEdit_amount->text().toDouble()});
  withdraws_.push_back({date, 0.0});
  for (QLineEdit *lineEdit : findChildren<QLineEdit *>()) {
    lineEdit->setValidator(new QDoubleValidator);
  }
  ui->lineEdit_term->setValidator(new QIntValidator(1, 1200, this));
}

Deposit::~Deposit() { delete ui; }

void Deposit::on_pushButton_addDeposit_clicked() {
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

void Deposit::on_pushButton_cashBack_clicked() {
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

void Deposit::on_pushButton_deposit3_clicked() {
  ui->groupBox_additionalDeposit3->setVisible(0);
  ui->pushButton_addDeposit->setEnabled(1);
  deposits_.pop_back();
}

void Deposit::on_pushButton_deposit2_clicked() {
  if (ui->groupBox_additionalDeposit3->isVisible()) {
    on_pushButton_deposit3_clicked();
  } else {
    ui->groupBox_additionalDeposit2->setVisible(0);
    deposits_.pop_back();
  }
}

void Deposit::on_pushButton_deposit1_clicked() {
  if (ui->groupBox_additionalDeposit3->isVisible()) {
    on_pushButton_deposit3_clicked();
  } else if (ui->groupBox_additionalDeposit2->isVisible()) {
    on_pushButton_deposit2_clicked();
  } else {
    ui->groupBox_deposits->setVisible(0);
    deposits_.pop_back();
  }
}

void Deposit::on_pushButton_calculate_clicked() {
  std::vector<double> result{};
  std::cout << ui->lineEdit_term->text().toUInt() << std::endl;
  try {
    result = ctrl_->processDepositData(
        deposits_, withdraws_, ui->lineEdit_tax->text().toDouble(),
        ui->lineEdit_rate->text().toDouble(),
        ui->lineEdit_term->text().toUInt(),
        ui->comboBox_withdrawInterval->currentIndex(),
        ui->checkBox_capitalize->isChecked());
    ui->label_9->setText(QString::number((result[0]), 'f', 2));
    ui->label_11->setText(QString::number((result[2]), 'f', 2));
    ui->label_7->setText(QString::number((result[1]), 'f', 2));
  } catch (...) {
    ui->label_9->setText("Error");
  }
}

void Deposit::on_pushButton_cashback3_clicked() {
  ui->groupBox_withdraw3->setVisible(0);
  ui->pushButton_cashBack->setEnabled(1);
  withdraws_.pop_back();
}

void Deposit::on_pushButton_cashback2_clicked() {
  if (ui->groupBox_withdraw3->isVisible()) {
    on_pushButton_cashback3_clicked();
  } else {
    ui->groupBox_withdraw2->setVisible(0);
    withdraws_.pop_back();
  }
}

void Deposit::on_dateEdit_deposit1_userDateChanged(const QDate &date) {
  deposits_[1].first = date;
}

void Deposit::on_dateEdit_deposit2_userDateChanged(const QDate &date) {
  deposits_[2].first = date;
}

void Deposit::on_dateEdit_deposit3_userDateChanged(const QDate &date) {
  deposits_[3].first = date;
}

void Deposit::on_dateEdit_cashback1_userDateChanged(const QDate &date) {
  withdraws_[1].first = date;
}

void Deposit::on_dateEdit_cashback2_userDateChanged(const QDate &date) {
  withdraws_[2].first = date;
}

void Deposit::on_dateEdit_cashback3_userDateChanged(const QDate &date) {
  withdraws_[3].first = date;
}

double Deposit::profit(double amount, int days, double rate) {
  double res = amount * days * rate;
  return res;
}

void Deposit::on_lineEdit_amount_textChanged(const QString &arg1) {
  deposits_[0].second = arg1.toDouble();
}

void Deposit::on_lineEdit_deposit1_textChanged(const QString &arg1) {
  deposits_[1].second = arg1.toDouble();
}

void Deposit::on_lineEdit_deposit2_textChanged(const QString &arg1) {
  deposits_[2].second = arg1.toDouble();
}

void Deposit::on_lineEdit_deposit3_textChanged(const QString &arg1) {
  deposits_[3].second = arg1.toDouble();
}

void Deposit::on_lineEdit_cashback1_textChanged(const QString &arg1) {
  withdraws_[1].second = arg1.toDouble();
}

void Deposit::on_lineEdit_cashback2_textChanged(const QString &arg1) {
  withdraws_[2].second = arg1.toDouble();
}

void Deposit::on_lineEdit_cashback3_textChanged(const QString &arg1) {
  withdraws_[3].second = arg1.toDouble();
}

void Deposit::on_pushButton_cashback1_clicked() {
  if (ui->groupBox_withdraw3->isVisible()) {
    on_pushButton_cashback3_clicked();
  } else if (ui->groupBox_withdraw2->isVisible()) {
    on_pushButton_cashback2_clicked();
  } else {
    ui->groupBox_withdraws->setVisible(0);
    withdraws_.pop_back();
  }
}
