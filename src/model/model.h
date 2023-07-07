#ifndef MODEL_H
#define MODEL_H
#include <vector>

#include "base_calculator.h"
#include "credit_calculator.h"
#include "deposit_calculator.h"
#include "transaction.h"

namespace s21 {
class model : public Calculator {
 public:
  std::vector<double> processCredit(double amount, double interestRate,
                                    int term, bool diff_type) {
    credit_.set_credit(term, amount, interestRate, diff_type);
    return credit_.processCredit();
  }

  std::vector<double> processDeposit(std::vector<std::pair<QDate, double>> depo,
                                     std::vector<std::pair<QDate, double>> cash,
                                     double tax, double rate, int term,
                                     int payment_int, bool capitalize) {
    deposit_.setDepositData(depo, cash, tax, rate, term, payment_int,
                            capitalize);
    return deposit_.processDeposit();
  }

 private:
  s21::credit_calculator credit_{};
  s21::deposit_calculator deposit_{};
};
};      // namespace s21
#endif  // MODEL_H
