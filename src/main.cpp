#include "view/mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[]) {
  QLocale locale(QLocale::English);
  QLocale::setDefault(locale);
  QApplication a(argc, argv);
  s21::Model m;
  s21::Controller ctrl(&m);
  MainWindow w(&ctrl);
  w.show();
  return a.exec();
}
