#ifndef CREDIT_CALCULATOR_H
#define CREDIT_CALCULATOR_H
#include <vector>

#include "QtMath"

namespace s21 {
class CreditCalculator {
 public:
  void SetCreditData(int term, double amount, double interest, bool diff_type) {
    if (term < 1 || amount <= 0) throw "Error";
    term_ = term;
    amount_ = amount;
    interest_ = interest;
    diff_type_ = diff_type;
  }
  std::vector<double> ProcessCredit() {
    std::vector<double> result_data;
    double int_rate = interest_ / 12 / 100;
    if (diff_type_) {
      double main_part = amount_ / term_;
      double current_payment{}, ostatok = amount_, amount{};
      for (int i = 0; i < term_; i++) {
        current_payment = (main_part + ostatok * int_rate);
        ostatok -= main_part;
        amount += current_payment;
        if (i == 0) result_data.push_back(current_payment);
        if (i == term_ - 1) result_data.push_back(current_payment);
      }
      result_data.push_back(amount);
      result_data.push_back(amount - amount_);
    } else {
      double a_monthly_amount =
          amount_ * (int_rate / (1 - qPow((int_rate + 1), (-1) * (term_))));
      result_data.push_back(a_monthly_amount);
      result_data.push_back(a_monthly_amount * term_);
      result_data.push_back(a_monthly_amount * term_ - amount_);
    }
    return result_data;
  }

 private:
  int term_{};
  double amount_{};
  double interest_{};
  bool diff_type_{};
};
};  // namespace s21

#endif  // CREDIT_CALCULATOR_H
