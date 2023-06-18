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

  //  void on_pushButton_withdrawDelete2_clicked();

  void on_pushButton_cashback2_clicked();

  void on_dateEdit_2_userDateChanged(const QDate &date);

  void on_dateEdit_3_userDateChanged(const QDate &date);

  void on_dateEdit_4_userDateChanged(const QDate &date);

  void on_dateEdit_5_userDateChanged(const QDate &date);

  void on_dateEdit_6_userDateChanged(const QDate &date);

  void on_dateEdit_7_userDateChanged(const QDate &date);

  void on_pushButton_withdrawDelete2_clicked();

  void on_lineEdit_amount_textChanged(const QString &arg1);

  void on_lineEdit_5_textChanged(const QString &arg1);

  void on_lineEdit_6_textChanged(const QString &arg1);

  void on_lineEdit_7_textChanged(const QString &arg1);

  void on_lineEdit_8_textChanged(const QString &arg1);

  void on_lineEdit_9_textChanged(const QString &arg1);

  void on_lineEdit_10_textChanged(const QString &arg1);

private:
  Ui::deposit *ui;
  s21::controller *ctrl_;
  std::vector<std::pair<QDate, double>> deposits_;
  std::vector<std::pair<QDate, double>> withdraws_;

  double profit(double amount, int days, double rate);
};

#endif // DEPOSIT_WINDOW_H
