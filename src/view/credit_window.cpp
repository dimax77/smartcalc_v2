#include "credit_window.h"
#include "QDebug"
#include "QtMath"
#include "ui_credit_window.h"

credit::credit(QWidget *parent) : QDialog(parent), ui(new Ui::credit) {
  ui->setupUi(this);
  ui->groupBox->setVisible(0);
  ui->lineEdit_amount->setValidator(new QDoubleValidator);
  ui->lineEdit_term->setValidator(new QIntValidator);
  ui->lineEdit_interestRate->setValidator(new QDoubleValidator);
}

credit::~credit() { delete ui; }

void credit::enable_pushButton() {
  ui->pushButton->setEnabled(ui->lineEdit_term->hasAcceptableInput() &&
                             ui->lineEdit_interestRate->hasAcceptableInput() &&
                             ui->lineEdit_amount->hasAcceptableInput());
}

void credit::keyPressEvent(QKeyEvent *event) {
  if (event->key() == Qt::Key_Q && event->modifiers() == Qt::ControlModifier) {
    close();
  }
}

void credit::on_pushButton_clicked() {
  double interestRate = ui->lineEdit_interestRate->text().toDouble();
  double amount = ui->lineEdit_amount->text().toDouble();
  double term = 0.0;
  if (ui->comboBox->currentIndex() == 1) {
    term = ui->lineEdit_term->text().toDouble();
  } else if (ui->comboBox->currentIndex() == 0) {
    term = ui->lineEdit_term->text().toDouble() * 12;
  }
  bool diff_type = ui->radioButton_diff->isChecked();
  try {
    auto result_data =
        ctrl_->processCreditData(amount, interestRate, term, diff_type);
    if (diff_type) {
      ui->label_monthlyPayment->setText(QString::number(result_data[0]));
      ui->label_monthlyPayment->setText(ui->label_monthlyPayment->text() +
                                        ".." +
                                        (QString::number(result_data[1])));
      ui->label_total->setText(QString::number(result_data[2]));
      ui->label_accruedInterest->setText(QString::number(result_data[3]));
      ui->groupBox->setVisible(1);
    } else {
      ui->label_monthlyPayment->setText(QString::number(result_data[0]));
      ui->label_accruedInterest->setText((QString::number(result_data[2])));
      ui->label_total->setText(QString::number(result_data[1]));
      ui->groupBox->setVisible(1);
    }
  } catch (...) {
    ui->label_monthlyPayment->setText("");
    ui->label_accruedInterest->setText("");
    ui->label_total->setText("Error");
    ui->groupBox->setVisible(1);
  }
}

void credit::on_lineEdit_amount_textEdited() { enable_pushButton(); }

void credit::on_lineEdit_interestRate_textEdited() { enable_pushButton(); }

void credit::on_lineEdit_term_textEdited() { enable_pushButton(); }
