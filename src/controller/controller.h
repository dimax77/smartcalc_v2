#ifndef S21CALC_CONTROLLER_H
#define S21CALC_CONTROLLER_H
#include "../model/model.h"

namespace s21 {
class controller {
private:
  model *model_;

public:
  controller(model *m) : model_(m){};
  void set(const std::string &in) { model_->set_input_string(in); };
  double get_res(double x) { return model_->eval(x); }
  bool translate(const std::string in) {
    model_->set_input_string(in);
    return !model_->to_postfix();
    ;
  }
};
}; // namespace s21

#endif // S21CALC_CONTROLLER_H
