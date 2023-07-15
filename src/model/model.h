#ifndef MODEL_H
#define MODEL_H
#include <vector>

#include "base_calculator.h"
#include "credit_calculator.h"
#include "deposit_calculator.h"
#include "transaction.h"

namespace s21 {
class Model : public Calculator {
 public:
  std::vector<double> ProcessCredit(double amount, double interestRate,
                                    int term, bool diff_type) {
    credit_.SetCreditData(term, amount, interestRate, diff_type);
    return credit_.ProcessCredit();
  }

  std::vector<double> ProcessDeposit(std::vector<std::pair<QDate, double>> depo,
                                     std::vector<std::pair<QDate, double>> cash,
                                     double tax, double rate, int term,
                                     int payment_int, bool capitalize) {
    deposit_.SetDepositData(depo, cash, tax, rate, term, payment_int,
                            capitalize);
    return deposit_.ProcessDeposit();
  }

 private:
  s21::CreditCalculator credit_{};
  s21::DepositCalculator deposit_{};
};
};      // namespace s21
#endif  // MODEL_H
