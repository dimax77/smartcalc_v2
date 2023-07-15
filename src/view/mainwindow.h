#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QKeyEvent>
#include <QMainWindow>
#include <QRegularExpression>

#include "../controller/controller.h"
#include "credit_window.h"
#include "deposit_window.h"
#include "graph_window.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(s21::Controller *ctrl, QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void HandleButtonClicked();
  void Eval();
  void on_push_button_credit_clicked();
  void on_push_button_deposit_clicked();
  void on_push_button_graph_clicked();
  void on_line_edit_x_textChanged(const QString &text);
  void on_line_edit_expression_textChanged(const QString &text);

  void on_push_button_set_x_clicked();
  void Reset();

 private:
  void keyPressEvent(QKeyEvent *event);
  static const QRegularExpression x_variable_;

  Ui::MainWindow *ui;
  s21::Controller *ctrl_;
  QString raw_input_expression_{};
  double x_{};
  bool was_error_{};
};
#endif  // MAINWINDOW_H
