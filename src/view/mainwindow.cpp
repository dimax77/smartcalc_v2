#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(s21::controller *ctrl, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), ctrl_(ctrl) {
  ui->setupUi(this);
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
    qApp->quit(); // закрыть приложение в  Ubuntu по <Ctrl-Q>
  }
}

void MainWindow::on_button_clicked() {
  QPushButton *mybutton = (QPushButton *)sender();
  QString text = mybutton->text();
  qDebug() << text;
  if (text == "x^y") {
    ui->lineEdit_2->setText(ui->lineEdit_2->text() += "^");
  } else if (text == "()") {
    if (!brace_opened) {
      ui->lineEdit_2->setText(ui->lineEdit_2->text() += "(");
      brace_opened = 1;
    } else {
      ui->lineEdit_2->setText(ui->lineEdit_2->text() += ")");
      brace_opened = 0;
    }
  } else if (text == "C") {
    ui->lineEdit_2->clear();
  } else if (text == "+/-") {
    ui->lineEdit_2->setText(ui->lineEdit_2->text() += "(-");
    brace_opened = 1;
  } else if (text == "=") {
    on_res();
  } else {
    ui->lineEdit_2->setText(ui->lineEdit_2->text() += text);
  }
}

void MainWindow::on_res() {
  if (ui->lineEdit_2->text() != "") {
    ctrl_->translate(ui->lineEdit_2->text().toStdString());
    double result = ctrl_->get_res(0.0);
    ui->lineEdit_2->setText(QString::number(result));
  }
}
