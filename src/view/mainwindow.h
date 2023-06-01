#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../controller/controller.h"
#include "QDebug"
#include "credit_window.h"
//#include "deposit.h"
#include "graph_window.h"
#include <QKeyEvent>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(s21::controller *ctrl, QWidget *parent = nullptr);
  ~MainWindow();

private slots:
  void on_button_clicked();
  void eval(QString raw_expression);
  void on_pushButton_31_clicked();
  void on_pushButton_32_clicked();
  void on_pushButton_33_clicked();
  void on_lineEdit_textChanged(const QString &text);
  void on_lineEdit_2_textChanged(const QString &text);

  void on_pushButton_clicked();

private:
  void keyPressEvent(QKeyEvent *event);

  Ui::MainWindow *ui;
  s21::controller *ctrl_;
  QString raw_input_expression_{};
  double x_{};
};
#endif // MAINWINDOW_H
