#ifndef S21CALC_CONTROLLER_H
#define S21CALC_CONTROLLER_H
#include "../model/model.h"
#include <vector>

namespace s21 {
class Controller {

public:
  Controller(Model *m) : model_(m){};
  void set(const std::string &in) { model_->set_input_string(in); };
  double get_res(double x) { return model_->eval(x); }
  bool processRawString(const std::string in) {
    model_->set_input_string(in);
    model_->translate();
    model_->postfix_string();
    return true;
  }

  std::vector<double> processCreditData(double amount, double interestRate,
                                        int term, bool diff_type) {
    return model_->processCredit(amount, interestRate, term, diff_type);
  }

  std::vector<double>
  processDepositData(std::vector<std::pair<QDate, double>> deposit,
                     std::vector<std::pair<QDate, double>> cashback, double tax,
                     double rate, int term, int payment_interval,
                     bool capitalize) {
    return model_->processDeposit(deposit, cashback, tax, rate, term,
                                  payment_interval, capitalize);
  }

private:
  Model *model_;
};
}; // namespace s21

#endif // S21CALC_CONTROLLER_H
