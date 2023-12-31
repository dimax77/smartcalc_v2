#ifndef S21CALC_CONTROLLER_H
#define S21CALC_CONTROLLER_H
#include <vector>

#include "../model/model.h"

namespace s21 {
class Controller {
 public:
  Controller(Model *m) : model_(m){};
  void set_raw_string(const std::string &raw_string) {
    model_->set_input_string(raw_string);
  };
  double get_res(double x) { return model_->Eval(x); }
  bool ProcessRawString(const std::string raw_string) {
    model_->set_input_string(raw_string);
    model_->Translate();
    model_->PostfixString();
    return true;
  }

  std::vector<double> ProcessCreditData(double amount, double interestRate,
                                        int term, bool diff_type) {
    return model_->ProcessCredit(amount, interestRate, term, diff_type);
  }

  std::vector<double> ProcessDepositData(
      std::vector<std::pair<QDate, double>> deposit,
      std::vector<std::pair<QDate, double>> cashback, double tax, double rate,
      int term, int payment_interval, bool capitalize) {
    return model_->ProcessDeposit(deposit, cashback, tax, rate, term,
                                  payment_interval, capitalize);
  }

 private:
  Model *model_;
};
};  // namespace s21

#endif  // S21CALC_CONTROLLER_H
