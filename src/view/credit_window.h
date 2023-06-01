#ifndef CREDIT_WINDOW_H
#define CREDIT_WINDOW_H

#include "../controller/controller.h"
#include <QDialog>
#include <QKeyEvent>

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

  void on_lineEdit_textEdited();

  void on_lineEdit_2_textEdited();

  void on_lineEdit_3_textEdited();

private:
  Ui::credit *ui;
  s21::controller *ctrl_;
};

#endif // CREDIT_WINDOW_H
