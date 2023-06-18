#ifndef DEPOSIT_CALCULATOR_H
#define DEPOSIT_CALCULATOR_H
#include <QtMath>
#include <vector>

namespace s21 {
class deposit_calculator {
public:
  std::vector<double> processsDeposit(double rate) {
    rate_ = rate;
    std::vector<double> data;
    return data;
  }

  double profit(double amount, int days) {
    return amount * rate_ / 100 / 365 * days;
  }

private:
  double rate_{};
};
}; // namespace s21

#endif // DEPOSIT_CALCULATOR_H
