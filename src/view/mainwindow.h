#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../controller/controller.h"
#include "credit_window.h"
#include "deposit_window.h"
#include "graph_window.h"
#include <QKeyEvent>
#include <QMainWindow>
#if QT_VERSION>= QT_VERSION_CHECK(6, 2, 3)
#include <QRegularExpression>
#endif

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
  void handleButtonClicked();
  void eval(QString raw_expression);
  void on_pushButton_31_clicked();
  void on_pushButton_32_clicked();
  void on_pushButton_33_clicked();
  void on_lineEdit_textChanged(const QString &text);
  void on_lineEdit_2_textChanged(const QString &text);

  void on_pushButton_clicked();

private:
  void keyPressEvent(QKeyEvent *event);
  static const QRegularExpression x_variable_;
  Ui::MainWindow *ui;
  s21::controller *ctrl_;
  QString raw_input_expression_{};
  double x_{};
};
#endif // MAINWINDOW_H
