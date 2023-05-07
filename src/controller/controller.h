#ifndef S21CALC_CONTROLLER_H
#define S21CALC_CONTROLLER_H
#include "../model/model.h"

namespace s21 {
class controller {
 private:
  model* model_;

 public:
  controller(model* m) : model_(m){};
  void someMethod(){};
};
};  // namespace s21

#endif  // S21CALC_CONTROLLER_H