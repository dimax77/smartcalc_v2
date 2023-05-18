#ifndef GRAPH_H
#define GRAPH_H

#include <QMainWindow>

class graph : public QMainWindow {
  Q_OBJECT
public:
  explicit graph(QWidget *parent = nullptr);

signals:

private:
  double xBegin, xEnd, yBegin, yEnd, h, X;
  int N;

  QVector<double> x, y;
  void setup(const QString &func);
};

#endif // GRAPH_H
