#ifndef DEPOSIT_H
#define DEPOSIT_H

#include "QDateEdit"
#include "QHBoxLayout"
#include "QLineEdit"
#include <QDialog>

namespace Ui {
class deposit;
}

class deposit : public QDialog {
  Q_OBJECT

public:
  explicit deposit(QWidget *parent = nullptr);
  ~deposit();

private slots:

  void on_pushButton_clicked();

  void on_pushButton_2_clicked();

  void on_pushButton_6_clicked();

  void on_pushButton_5_clicked();

  void on_pushButton_4_clicked();

  void on_pushButton_3_clicked();

  void on_checkBox_stateChanged();

  void on_pushButton_9_clicked();

  void on_pushButton_8_clicked();

  void on_pushButton_7_clicked();

private:
  Ui::deposit *ui;
  double profit(double amount, int days, double rate);
};

#endif // DEPOSIT_H
