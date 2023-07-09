#ifndef CREDIT_CALCULATOR_H
#define CREDIT_CALCULATOR_H
#include <vector>

#include "QtMath"

namespace s21 {
class CreditCalculator {
public:
  void set_credit(int srok, double summa, double stavka, bool diff_type) {
    if (srok < 1 || summa <= 0)
      throw "Error";
    srok_ = srok;
    summa_credita_ = summa;
    stavka_ = stavka;
    diff_type_ = diff_type;
  }
  std::vector<double> processCredit() {
    std::vector<double> result_data;
    double int_rate = stavka_ / 12 / 100;
    if (diff_type_) {
      double main_part = summa_credita_ / srok_;
      double current_payment{}, ostatok = summa_credita_, summa{};
      for (int i = 0; i < srok_; i++) {
        current_payment = (main_part + ostatok * int_rate);
        ostatok -= main_part;
        summa += current_payment;
        if (i == 0)
          result_data.push_back(current_payment);
        if (i == srok_ - 1)
          result_data.push_back(current_payment);
      }
      result_data.push_back(summa);
      result_data.push_back(summa - summa_credita_);
    } else {
      double a_monthly_amount =
          summa_credita_ *
          (int_rate / (1 - qPow((int_rate + 1), (-1) * (srok_))));
      result_data.push_back(a_monthly_amount);
      result_data.push_back(a_monthly_amount * srok_);
      result_data.push_back(a_monthly_amount * srok_ - summa_credita_);
    }
    return result_data;
  }

private:
  int srok_{};
  double summa_credita_{};
  double stavka_{};
  bool diff_type_{};
};
}; // namespace s21

#endif // CREDIT_CALCULATOR_H
