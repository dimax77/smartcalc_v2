#include "view/mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  s21::model m;
  s21::controller ctrl(&m);
  MainWindow w(&ctrl);
  w.show();
  return a.exec();
}
