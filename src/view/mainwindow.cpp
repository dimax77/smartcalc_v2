#include "mainwindow.h"
#include "QValidator"
#include "ui_mainwindow.h"

MainWindow::MainWindow(s21::controller *ctrl, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), ctrl_(ctrl) {
  ui->setupUi(this);
  ui->lineEdit->setValidator(new QDoubleValidator);
  for (int i = 1; i < 31; i++) {
    QString button_name = QString("pushButton_") + QString::number(i);
    QPushButton *button = findChild<QPushButton *>(button_name);
    if (button) {
      connect(button, SIGNAL(clicked()), this, SLOT(on_button_clicked()),
              Qt::UniqueConnection);
    }
  }
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::keyPressEvent(QKeyEvent *event) {
  if (event->key() == Qt::Key_Q && event->modifiers() == Qt::ControlModifier) {
    qApp->quit();
  }
}

void MainWindow::on_button_clicked() {
  QPushButton *mybutton = (QPushButton *)sender();
  QString text = mybutton->text();
  if (!text.isEmpty()) {
    if (text == "C") {
      ui->lineEdit->clear();
      ui->lineEdit_2->clear();
      raw_input_expression_.clear();
    } else if (text == "=") {
      eval(raw_input_expression_);
    } else {
      if (text == "x^y") {
        ui->lineEdit_2->setText(ui->lineEdit_2->text() += "^");

      } else if (text == "sqrt") {
        ui->lineEdit_2->setText(ui->lineEdit_2->text() += "√");

      } else {
        ui->lineEdit_2->setText(ui->lineEdit_2->text() += text);
      }
      raw_input_expression_ += mybutton->accessibleName();
    }
  }
}

void MainWindow::eval(QString text) {
  try {
    ctrl_->translate(text.toStdString());
    double result = ctrl_->get_res(x_);
    ui->lineEdit_2->setText(QString::number(result));
  } catch (...) {
    ui->lineEdit_2->setText("Error");
  }
}

void MainWindow::on_pushButton_31_clicked() {
  credit credit(ctrl_);
  credit.exec();
}

void MainWindow::on_pushButton_32_clicked() {
  deposit deposit(ctrl_);
  deposit.exec();
}

void MainWindow::on_pushButton_33_clicked() {
  graph graph(ctrl_);
  graph.setup(ui->lineEdit_2->text(), raw_input_expression_);
  graph.exec();
}

void MainWindow::on_pushButton_clicked() {
  ui->lineEdit_2->setText(ui->lineEdit_2->text() += 'x');
  raw_input_expression_ += 'x';
}

void MainWindow::on_lineEdit_2_textChanged(const QString &text) {
  QRegExp x("^.*x.*$");
  if (x.indexIn(text) != -1) {
    ui->lineEdit->setEnabled(true);
  } else {
    ui->lineEdit->setEnabled(false);
  }
}

void MainWindow::on_lineEdit_textChanged(const QString &text) {
  x_ = text.toDouble();
}
