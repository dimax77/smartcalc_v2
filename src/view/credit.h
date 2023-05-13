#ifndef CREDIT_H
#define CREDIT_H

#include <QDialog>

namespace Ui {
class credit;
}

class credit : public QDialog {
  Q_OBJECT

public:
  explicit credit(QWidget *parent = nullptr);
  ~credit();

private slots:
  void on_pushButton_clicked();
  void enable_pushButton();

  void on_lineEdit_textEdited();

  void on_lineEdit_2_textEdited();

  void on_lineEdit_3_textEdited();

private:
  Ui::credit *ui;
};

#endif // CREDIT_H
