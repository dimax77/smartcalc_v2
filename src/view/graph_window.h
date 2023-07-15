#ifndef GRAPH_WINDOW_H
#define GRAPH_WINDOW_H

#include <QDialog>

#include "../controller/controller.h"

namespace Ui {
class graph;
}

class Graph : public QDialog {
  Q_OBJECT

 public:
  explicit Graph(s21::Controller *ctrl, QWidget *parent = nullptr);
  ~Graph();
  double xBegin, xEnd, yBegin, yEnd, h, X;
  int N;

  QVector<double> x, y;
  void setup(const QString &func, QString raw_func);

 private slots:
  void on_pushButton_plot_clicked();

 private:
  Ui::graph *ui;
  s21::Controller *ctrl_;
  double x_{};
  QString raw_expr_{};
};

#endif  // GRAPH_WINDOW_H
