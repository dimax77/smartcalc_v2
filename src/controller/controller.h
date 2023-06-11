#ifndef S21CALC_CONTROLLER_H
#define S21CALC_CONTROLLER_H
#include "../model/model.h"
#include <vector>

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
    model_->translate();
    model_->postfix_string();
    return true;
  }
  //  void set_credit_data(double amount, double rate, double duration,
  //                       bool diff_type, std::vector<double> *result_data_) {
  //    model_->set_credit_data(duration, amount, rate, diff_type,
  //    result_data_);
  //  }
  std::vector<double> processCreditData(double amount, double interestRate,
                                        int term, bool diff_type) {
    return model_->processCredit(amount, interestRate, term, diff_type);
  }
};
}; // namespace s21

#endif // S21CALC_CONTROLLER_H
