#include "deposit_window.h"
#include "QDebug"
#include "ui_deposit_window.h"

deposit::deposit(QWidget *parent) : QDialog(parent), ui(new Ui::deposit) {
  ui->setupUi(this);
  ui->groupBox->setVisible(0);
  ui->groupBox_2->setVisible(0);
  QDate date = QDate::currentDate();
  ui->dateEdit->setDate(date);
  ui->checkBox->setChecked(1);
}

deposit::~deposit() { delete ui; }

void deposit::on_pushButton_clicked() //  Обработка нажатия "Пополнение"
{
  if (!ui->groupBox->isVisible()) {
    ui->groupBox->setVisible(1);
    QDate date = (QDate::currentDate()).addMonths(1);
    ui->dateEdit_2->setDate(date);
    ui->groupBox_4->setVisible(0);
    ui->groupBox_5->setVisible(0);
  } else if (!ui->groupBox_4->isVisible()) {
    ui->groupBox_4->setVisible(1);
    QDate date = (QDate::currentDate()).addMonths(2);
    ui->dateEdit_3->setDate(date);
    if (ui->groupBox_5->isVisible())
      ui->pushButton->setEnabled(0);
  } else if (!ui->groupBox_5->isVisible()) {
    ui->groupBox_5->setVisible(1);
    QDate date = (QDate::currentDate()).addMonths(3);
    ui->dateEdit_4->setDate(date);
    ui->pushButton->setEnabled(0);
  }
}

void deposit::on_pushButton_2_clicked() //  Обработка "Снятие"
{
  if (!ui->groupBox_2->isVisible()) {
    ui->groupBox_2->setVisible(1);
    QDate date = (QDate::currentDate()).addMonths(1);
    ui->dateEdit_5->setDate(date);
    ui->groupBox_8->setVisible(0);
    ui->groupBox_9->setVisible(0);
  } else if (!ui->groupBox_8->isVisible()) {
    ui->groupBox_8->setVisible(1);
    QDate date = (QDate::currentDate()).addMonths(2);
    ui->dateEdit_6->setDate(date);
    if (ui->groupBox_9->isVisible())
      ui->pushButton_2->setEnabled(0);
  } else if (!ui->groupBox_9->isVisible()) {
    ui->groupBox_9->setVisible(1);
    QDate date = (QDate::currentDate()).addMonths(3);
    ui->dateEdit_7->setDate(date);
    ui->pushButton_2->setEnabled(0);
    ui->pushButton_2->setEnabled(0);
  }
}

void deposit::on_pushButton_6_clicked() {
  ui->groupBox_5->setVisible(0);
  ui->pushButton->setEnabled(1);
}

void deposit::on_pushButton_5_clicked() {
  ui->groupBox_4->setVisible(0);
  ui->pushButton->setEnabled(1);
}

void deposit::on_pushButton_4_clicked() {
  if (ui->groupBox_5->isVisible()) {
    ui->groupBox_5->setVisible(0);
    ui->pushButton->setEnabled(1);
  } else if (ui->groupBox_4->isVisible()) {
    ui->groupBox_4->setVisible(0);
  } else {
    ui->groupBox->setVisible(0);
  }
}

void deposit::on_pushButton_3_clicked() //  Обработка кнопки "Рассчитать"
{
  if (ui->checkBox->isChecked()) {
    double party_per_day =
        ui->lineEdit_4->text().toDouble() / 365 / 100; //  Доля в день

    QDate finish =
        (ui->dateEdit->date()).addMonths(ui->lineEdit_2->text().toInt());
    int dlit = (ui->dateEdit->date()).daysTo(finish);

    double sum_profit =
        profit(ui->lineEdit->text().toDouble(), dlit, party_per_day);
    ui->label_7->setText(QString::number(sum_profit));

    double nalog = ui->lineEdit_3->text().toDouble() / 100 * sum_profit;
    ui->label_11->setText(QString::number(nalog));

    ui->label_9->setText(ui->lineEdit->text());
  } else {
    double sum_profit = 0.0;
    double party_per_day = ui->lineEdit_4->text().toDouble() / 365 / 100;
    if (ui->groupBox_3->isVisible()) {
      QDate end = ui->dateEdit_2->date();
      sum_profit = profit(ui->lineEdit->text().toDouble(),
                          (ui->dateEdit->date()).daysTo(end), party_per_day);
    }
  }
}

void deposit::on_checkBox_stateChanged() {
  if (ui->checkBox->isChecked()) {
    ui->pushButton->setEnabled(0);
    ui->pushButton_2->setEnabled(0);
    ui->groupBox->setVisible(0);
    ui->groupBox_2->setVisible(0);
  }
  if (!ui->checkBox->isChecked()) {
    ui->pushButton->setEnabled(1);
    ui->pushButton_2->setEnabled(1);
  }
}

void deposit::on_pushButton_9_clicked() {
  ui->groupBox_9->setVisible(0);
  ui->pushButton_2->setEnabled(1);
}

void deposit::on_pushButton_8_clicked() {
  ui->groupBox_8->setVisible(0);
  ui->pushButton_2->setEnabled(1);
}

void deposit::on_pushButton_7_clicked() {
  if (ui->groupBox_8->isVisible()) {
    ui->groupBox_8->setVisible(0);
    ui->pushButton_2->setEnabled(1);
  } else if (ui->groupBox_9->isVisible()) {
    ui->groupBox_9->setVisible(0);
    ui->pushButton_2->setEnabled(1);
  } else {
    ui->groupBox_2->setVisible(0);
  }
}

double deposit::profit(double amount, int days, double rate) {
  double res = amount * days * rate;
  return res;
}
