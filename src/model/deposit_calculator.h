#ifndef DEPOSIT_CALCULATOR_H
#define DEPOSIT_CALCULATOR_H
#include <QDate>
#include <QtMath>
#include <vector>

#include "transaction.h"

namespace s21 {
class DepositCalculator {
public:
  void setDepositData(std::vector<std::pair<QDate, double>> depo,
                      std::vector<std::pair<QDate, double>> cash, double tax,
                      double rate, int term, int payment_int, bool capitalize) {
    transaction_.clear();
    balance_ = 0.0;
    startDate_ = depo[0].first;
    endDate_ = startDate_.addMonths(term);
    deposit_ = depo[0].second;

    while (!depo.empty()) {
      Transaction *deposit = new Deposit(depo.back().first, depo.back().second);
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
    tax_ = tax;
    rate_ = rate;
  }

  std::vector<double> processDeposit() {
    try {
      std::vector<double> data{};
      double totalWithdraw{}, totalDeposit{};
      auto currentDate = startDate_;
      int duration{};
      for (auto tr = transaction_.begin(); tr != transaction_.end(); ++tr) {
        auto nextTr = std::next(tr);
        if (nextTr != transaction_.end()) {
          duration = currentDate.daysTo((*nextTr)->getDate());
          currentDate = (*nextTr)->getDate();
        } else {
          duration = currentDate.daysTo(endDate_);
        };
        if (auto withdrawTr = dynamic_cast<Withdraw *>(*tr)) {
          totalWithdraw += withdrawTr->getAmount();
        } else if (auto depositTr = dynamic_cast<Deposit *>(*tr)) {
          totalDeposit += depositTr->getAmount();
        }

        (*tr)->processTransaction(balance_, rate_, duration);
      }

      data.push_back(balance_);
      data.push_back(balance_ + totalWithdraw - totalDeposit);
      data.push_back((balance_ + totalWithdraw - totalDeposit) * tax_ / 100);
      return data;
    } catch (...) {
      throw std::runtime_error("Wrong input data.");
    }
  }

private:
  double tax_{}, rate_{}, balance_{}, deposit_{};
  QDate startDate_{}, endDate_{};
  std::vector<Transaction *> transaction_{};
};
}; // namespace s21

#endif // DEPOSIT_CALCULATOR_H
