#ifndef GRAPH_WINDOW_H
#define GRAPH_WINDOW_H

#include "../controller/controller.h"
#include <QDialog>

namespace Ui {
class graph;
}

class graph : public QDialog {
  Q_OBJECT

public:
  explicit graph(s21::controller *ctrl, QWidget *parent = nullptr);
  ~graph();
  double xBegin, xEnd, yBegin, yEnd, h, X;
  int N;

  QVector<double> x, y;
  void setup(const QString &func, QString raw_func);

private slots:
  void on_pushButton_plot_clicked();

private:
  Ui::graph *ui;
  s21::controller *ctrl_;
  double x_{};
  QString raw_expr_{};
};

#endif // GRAPH_WINDOW_H
