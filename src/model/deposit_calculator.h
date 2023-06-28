#ifndef DEPOSIT_CALCULATOR_H
#define DEPOSIT_CALCULATOR_H
#include "transaction.h"
#include <QDate>
#include <QtMath>
#include <iostream>
#include <vector>

namespace s21 {
class deposit_calculator {
public:
  void setDepositData(std::vector<std::pair<QDate, double>> depo,
                      std::vector<std::pair<QDate, double>> cash, double tax,
                      double rate, int term, int payment_int, bool capitalize) {
    transaction_.clear();
    startDate_ = depo[0].first;
    endDate_ = startDate_.addMonths((term));

    deposit_ = depo[0].second;
    balance_ = deposit_;
    while (!depo.empty()) {
      Transaction *deposit =
          new Deposit(depo.back().first, depo.back().second, false);
      transaction_.push_back(deposit);
      depo.pop_back();
    };
    while (!cash.empty()) {
      Transaction *withdraw =
          new Withdraw(cash.back().first, cash.back().second);
      transaction_.push_back(withdraw);
      cash.pop_back();
    };
    if (capitalize) {
      if (payment_int) {
        auto tempDate = startDate_.addMonths(1);
        while (tempDate != endDate_) {
          transaction_.push_back(new Deposit(tempDate, 0.0, true));
          tempDate = tempDate.addMonths(1);
        }
      }
    }
    std::sort(transaction_.begin(), transaction_.end(),
              [](Transaction *t1, Transaction *t2) {
                return t1->getDate() < t2->getDate();
              });
    transaction_.erase(transaction_.begin() + 1);
    for (auto tr = transaction_.begin(); tr != transaction_.end(); tr++) {
      std::cout << ((*tr)->getDate()).toString().toStdString() << "   "
                << (*tr)->getAmount() << std::endl;
    }
    tax_ = tax;
    rate_ = rate;
    term_ = term;
    payment_interval_ = payment_int;
  }

  std::vector<double> processDeposit() {
    std::vector<double> data;
    auto currentDate = startDate_;
    int duration{};
    for (auto tr = transaction_.begin(); tr != transaction_.end(); ++tr) {
      auto nextTr = std::next(tr);
      if (nextTr != transaction_.end()) {
        duration = currentDate.daysTo((*nextTr)->getDate());
        std::cout << "entered 'not end' transaction's proccessing" << std::endl;
        currentDate = (*nextTr)->getDate();
      } else {
        duration = currentDate.daysTo(endDate_);
        std::cout << "Duration: " << duration << std::endl;
      };
      (*tr)->processTransaction(balance_, rate_, duration);
    }
    data.push_back(balance_);
    data.push_back(balance_ - deposit_);
    data.push_back((balance_ - deposit_) * tax_ / 100);
    return data;
  }

  double profit(double amount, int days) {
    return amount * rate_ / 100 / 365 * days;
  }

private:
  double tax_{}, rate_{}, balance_{}, deposit_{};
  int term_{};
  int payment_interval_{};
  QDate startDate_{}, endDate_{};
  std::vector<Transaction *> transaction_{};
};
}; // namespace s21

#endif // DEPOSIT_CALCULATOR_H
