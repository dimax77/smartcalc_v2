#ifndef MODEL_H
#define MODEL_H
#include "base_calculator.h"
#include "credit_calculator.h"
#include "deposit_calculator.h"
#include <vector>

namespace s21 {
class model : public Calculator {

public:
  std::vector<double> processCredit(double amount, double interestRate,
                                    int term, bool diff_type) {
    credit_.set_credit(term, amount, interestRate, diff_type);
    return credit_.processCredit();
  }

  std::vector<double> processDeposit() {
    std::vector<double> result{};
    return result;
  }

private:
  s21::credit_calculator credit_;
  s21::deposit_calculator deposit_;
};
};     // namespace s21
#endif // MODEL_H
