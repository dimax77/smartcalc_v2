#include "mainwindow.h"

#include "QValidator"
#include "ui_mainwindow.h"

MainWindow::MainWindow(s21::Controller *ctrl, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), ctrl_(ctrl) {
  ui->setupUi(this);
  ui->line_edit_x->setValidator(new QDoubleValidator);
  for (int i = 1; i < 31; i++) {
    QString button_name = QString("push_button_") + QString::number(i);
    QPushButton *button = findChild<QPushButton *>(button_name);
    if (button) {
      connect(button, &QPushButton::clicked, this,
              [this]() { HandleButtonClicked(); });
    }
  }
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::keyPressEvent(QKeyEvent *event) {
  if (event->key() == Qt::Key_Q && event->modifiers() == Qt::ControlModifier) {
    qApp->quit();
  }
}

void MainWindow::HandleButtonClicked() {
  if (was_error_) {
    Reset();
  }
  QPushButton *mybutton = qobject_cast<QPushButton *>(sender());
  QString text = mybutton->text();
  if (!text.isEmpty()) {
    if (text == "C") {
      Reset();
    } else if (text == "=") {
      Eval();
    } else {
      if (text == "x^y") {
        ui->line_edit_expression->setText(ui->line_edit_expression->text() +=
                                          "^");
      } else if (text == "sqrt") {
        ui->line_edit_expression->setText(ui->line_edit_expression->text() +=
                                          "√");
      } else {
        ui->line_edit_expression->setText(ui->line_edit_expression->text() +=
                                          text);
      }
      raw_input_expression_ += mybutton->accessibleName();
    }
  }
}

void MainWindow::Reset() {
  ui->line_edit_x->clear();
  ui->line_edit_expression->clear();
  raw_input_expression_.clear();
  was_error_ = false;
}

void MainWindow::Eval() {
  try {
    ctrl_->ProcessRawString(raw_input_expression_.toStdString());
    double result = ctrl_->get_res(x_);
    ui->line_edit_expression->setText(QString::number(result));
    raw_input_expression_ = QString::number(result);
  } catch (std::exception &e) {
    was_error_ = true;
    ui->line_edit_expression->setText("Error: " + QString(e.what()));
  }
}

void MainWindow::on_push_button_credit_clicked() {
  Credit credit(ctrl_);
  credit.exec();
}

void MainWindow::on_push_button_deposit_clicked() {
  Deposit deposit(ctrl_);
  deposit.exec();
}

void MainWindow::on_push_button_graph_clicked() {
  Graph graph(ctrl_);
  graph.setup(ui->line_edit_expression->text(), raw_input_expression_);
  graph.exec();
}

void MainWindow::on_push_button_set_x_clicked() {
  ui->line_edit_expression->setText(ui->line_edit_expression->text() += 'x');
  raw_input_expression_ += 'x';
}

const QRegularExpression MainWindow::x_variable_("^.*x.*$");
void MainWindow::on_line_edit_expression_textChanged(const QString &text) {
  QRegularExpressionMatch match = x_variable_.match(text);
  if (match.hasMatch()) {
    ui->line_edit_x->setEnabled(true);
  } else {
    ui->line_edit_x->setEnabled(false);
  }
}

void MainWindow::on_line_edit_x_textChanged(const QString &text) {
  x_ = text.toDouble();
}
