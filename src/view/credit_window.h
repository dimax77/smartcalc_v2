#ifndef CREDIT_WINDOW_H
#define CREDIT_WINDOW_H

#include "../controller/controller.h"
#include <QDialog>
#include <QKeyEvent>
#include <vector>

namespace Ui {
class credit;
}

class credit : public QDialog {
  Q_OBJECT

public:
  explicit credit(QWidget *parent = nullptr);
  ~credit();

private slots:
  void keyPressEvent(QKeyEvent *event);
  void on_pushButton_clicked();
  void enable_pushButton();

  void on_lineEdit_amount_textEdited();
  void on_lineEdit_interestRate_textEdited();
  void on_lineEdit_term_textEdited();

private:
  Ui::credit *ui;
  s21::controller *ctrl_;
};

#endif // CREDIT_WINDOW_H
