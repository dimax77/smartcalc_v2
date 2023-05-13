#include "credit.h"
#include "QDebug"
#include "QtMath"
#include "ui_credit.h"

credit::credit(QWidget *parent) : QDialog(parent), ui(new Ui::credit) {
  ui->setupUi(this);
  ui->groupBox->setVisible(0);
  ui->lineEdit->setValidator(new QDoubleValidator);
  ui->lineEdit_2->setValidator(new QIntValidator);
  ui->lineEdit_3->setValidator(new QDoubleValidator);
}

credit::~credit() { delete ui; }
void credit::enable_pushButton() {
  ui->pushButton->setEnabled(ui->lineEdit_3->hasAcceptableInput() &&
                             ui->lineEdit_2->hasAcceptableInput() &&
                             ui->lineEdit->hasAcceptableInput());
}
void credit::on_pushButton_clicked() {
  double ostatok = ui->lineEdit->text().toDouble();
  double summa = 0;
  if (ui->radioButton->isChecked()) {
    double int_rate = (ui->lineEdit_3->text().toDouble()) / 12 / 100;
    qDebug() << int_rate;
    double loan_amount = ui->lineEdit->text().toDouble();
    qDebug() << loan_amount;
    double srok = 0.0;
    if (ui->comboBox->currentIndex() == 1) {
      srok = ui->lineEdit_2->text().toDouble();
    } else if (ui->comboBox->currentIndex() == 0) {
      srok = ui->lineEdit_2->text().toDouble() * 12;
    }
    qDebug() << QString::number(srok);
    double a_monthly_amount =
        loan_amount * (int_rate / (1 - qPow((int_rate + 1), (-1) * (srok))));
    qDebug() << a_monthly_amount;
    ui->label_8->setText(QString::number(a_monthly_amount));
    ui->label_10->setText((QString::number(a_monthly_amount * srok)));
    ui->label_9->setText(
        QString::number(a_monthly_amount * srok - loan_amount));
    ui->groupBox->setVisible(1);
  } else if (ui->radioButton_2->isChecked()) {
    double int_rate = (ui->lineEdit_3->text().toDouble()) / 12 / 100;
    //        double loan_amount = ui->lineEdit->text().toDouble();
    double srok;
    double current_payment;
    if (ui->comboBox->currentIndex() == 1) {
      srok = ui->lineEdit_2->text().toDouble();
    } else {
      srok = ui->lineEdit_2->text().toDouble() * 12;
    }
    double main_part = ui->lineEdit->text().toDouble() / srok;
    for (int i = 0; i < srok; i++) {
      current_payment = main_part + ostatok * int_rate;
      ostatok -= main_part;
      summa += current_payment;
      if (i == 0)
        ui->label_8->setText(QString::number(current_payment));
      if (i == srok - 1)
        ui->label_8->setText(ui->label_8->text() + ".." +
                             (QString::number(current_payment)));
    }
    ui->label_10->setText(QString::number(summa));
    ui->label_9->setText(
        QString::number(summa - ui->lineEdit->text().toDouble()));
    ui->groupBox->setVisible(1);
  }
}

void credit::on_lineEdit_textEdited() { enable_pushButton(); }

void credit::on_lineEdit_2_textEdited() { enable_pushButton(); }

void credit::on_lineEdit_3_textEdited() { enable_pushButton(); }
