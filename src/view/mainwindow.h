#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../controller/controller.h"
#include "QDebug"
#include "credit.h"
//#include "deposit.h"
//#include "graph.h"
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
  void on_res();
  void on_pushButton_31_clicked();
  void on_pushButton_32_clicked();
  void on_pushButton_33_clicked();

private:
  void keyPressEvent(QKeyEvent *event);

  int brace_opened = 0;
  Ui::MainWindow *ui;
  s21::controller *ctrl_;
};
#endif // MAINWINDOW_H
