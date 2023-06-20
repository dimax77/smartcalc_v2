#ifndef DEPOSIT_WINDOW_H
#define DEPOSIT_WINDOW_H

#include "../controller/controller.h"
#include "QDateEdit"
#include "QHBoxLayout"
#include "QLineEdit"
#include <QDialog>
#include <vector>

namespace Ui {
class deposit;
}

class deposit : public QDialog {
  Q_OBJECT

public:
  explicit deposit(QWidget *parent = nullptr);
  ~deposit();

private slots:

  void on_pushButton_addDeposit_clicked();

  void on_pushButton_cashBack_clicked();

  void on_pushButton_deposit3_clicked();

  void on_pushButton_deposit2_clicked();

  void on_pushButton_deposit1_clicked();

  void on_pushButton_calculate_clicked();

  void on_checkBox_capitalize_stateChanged();

  void on_pushButton_cashback3_clicked();

  void on_pushButton_cashback2_clicked();

  void on_dateEdit_deposit1_userDateChanged(const QDate &date);

  void on_dateEdit_deposit2_userDateChanged(const QDate &date);

  void on_dateEdit_deposit3_userDateChanged(const QDate &date);

  void on_dateEdit_cashback1_userDateChanged(const QDate &date);

  void on_dateEdit_cashback2_userDateChanged(const QDate &date);

  void on_dateEdit_cashback3_userDateChanged(const QDate &date);

  void on_lineEdit_amount_textChanged(const QString &arg1);

  void on_lineEdit_deposit1_textChanged(const QString &arg1);

  void on_lineEdit_deposit2_textChanged(const QString &arg1);

  void on_lineEdit_deposit3_textChanged(const QString &arg1);

  void on_lineEdit_cashback1_textChanged(const QString &arg1);

  void on_lineEdit_cashback2_textChanged(const QString &arg1);

  void on_lineEdit_cashback3_textChanged(const QString &arg1);

  void on_pushButton_cashback1_clicked();

private:
  Ui::deposit *ui;
  s21::controller *ctrl_;
  std::vector<std::pair<QDate, double>> deposits_{};
  std::vector<std::pair<QDate, double>> withdraws_{};

  double profit(double amount, int days, double rate);
};

#endif // DEPOSIT_WINDOW_H
