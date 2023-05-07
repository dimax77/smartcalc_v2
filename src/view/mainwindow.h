#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QKeyEvent>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:
  void on_button_clicked();


private:
  void keyPressEvent(QKeyEvent *event);
  void on_res();

  int brace_opened = 0;
  Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
