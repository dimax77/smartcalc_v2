#ifndef GRAPH_WINDOW_H
#define GRAPH_WINDOW_H

#include <QDialog>

namespace Ui {
class graph;
}

class graph : public QDialog {
  Q_OBJECT

public:
  explicit graph(QWidget *parent = nullptr);
  ~graph();
  double xBegin, xEnd, yBegin, yEnd, h, X;
  int N;

  QVector<double> x, y;
  void setup(const QString &func);

private slots:
  void on_pushButton_clicked();

private:
  Ui::graph *ui;
};

#endif // GRAPH_WINDOW_H
