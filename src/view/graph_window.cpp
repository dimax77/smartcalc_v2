#include "graph_window.h"
#include "ui_graph_window.h"

#include "QDebug"

graph::graph(QWidget *parent) : QDialog(parent), ui(new Ui::graph) {
  ui->setupUi(this);
}

graph::~graph() { delete ui; }

void graph::on_pushButton_clicked() {
  h = 0.1;
  xBegin = ui->lineEdit_xmin->text().toDouble();
  xEnd = ui->lineEdit_xmax->text().toDouble() + h;
  yBegin = ui->lineEdit_ymin->text().toDouble();
  yEnd = ui->lineEdit_ymax->text().toDouble();
  ui->widget->xAxis->setRange(xBegin, xEnd);
  ui->widget->yAxis->setRange(yBegin, yEnd);
  QByteArray my_eval = ui->lineEdit_func->text().toLocal8Bit();
  const char *text = my_eval.data();
  qDebug() << text;
  //  char pol[255];
  //  for (int i = 0; i < 255; i++)
  //    pol[i] = ' ';
  //  expressiontopolish(text, pol);
  //  if (1) {
  //    int flag = 0;
  //    for (X = xBegin; X <= xEnd; X += h) {
  //      x.push_back(X);
  //      double X_tmp = eval(pol, X);
  //      if (X_tmp == INFINITY || X_tmp != X_tmp) {
  //        ui->label_8->setText("Error");
  //        flag = 1;
  //        break;
  //      }
  //      y.push_back(X_tmp);
  //    }
  //    if (!flag) {
  //      ui->widget->addGraph();
  //      ui->widget->graph(0)->addData(x, y);
  //      ui->widget->replot();
  //    }
  //  } else {
  //    ui->label_8->setText("Error");
  //  }
}

void graph::setup(const QString &func) {
  ui->lineEdit_func->setText(func);
  ui->lineEdit_xmin->setText("-10");
  ui->lineEdit_xmax->setText("10");
  ui->lineEdit_ymin->setText("-10");
  ui->lineEdit_ymax->setText("10");
}
