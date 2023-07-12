#include "graph_window.h"
#include "ui_graph_window.h"

Graph::Graph(s21::Controller *ctrl, QWidget *parent)
    : QDialog(parent), ui(new Ui::graph), ctrl_(ctrl) {
  ui->setupUi(this);
  for (QLineEdit *lineEdit : findChildren<QLineEdit *>()) {
    lineEdit->setValidator(new QIntValidator(-1000000, 1000000, this));
  }
  //  ui->lineEdit_term->setValidator(new QIntValidator(1, 1200, this));
}

Graph::~Graph() { delete ui; }

void Graph::setup(const QString &func, QString raw_func) {
  ui->lineEdit_func->setText(func);
  ui->lineEdit_xmin->setText("-10");
  ui->lineEdit_xmax->setText("10");
  ui->lineEdit_ymin->setText("-10");
  ui->lineEdit_ymax->setText("10");
  raw_expr_ = raw_func;
}

void Graph::on_pushButton_plot_clicked() {
  h = 0.1;
  xBegin = ui->lineEdit_xmin->text().toDouble();
  xEnd = ui->lineEdit_xmax->text().toDouble() + h;
  yBegin = ui->lineEdit_ymin->text().toDouble();
  yEnd = ui->lineEdit_ymax->text().toDouble();
  ui->widget->xAxis->setRange(xBegin, xEnd);
  ui->widget->yAxis->setRange(yBegin, yEnd);
  if (!raw_expr_.isEmpty()) {
    try {
      ctrl_->processRawString(raw_expr_.toStdString());
      for (X = xBegin; X <= xEnd; X += h) {
        x.push_back(X);
        double X_tmp = ctrl_->get_res(X);
        y.push_back(X_tmp);
      }
      ui->widget->addGraph();
      ui->widget->graph(0)->addData(x, y);
      ui->widget->replot();
    } catch (...) {
      ui->label_8->setText("Error");
    }
  }
}
