#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <QDate>
#include <algorithm>

namespace s21 {
class Transaction {
 public:
  Transaction(QDate date, double amount, bool capital = false)
      : date_(date), amount_(amount), capital_(capital) {}
  virtual ~Transaction() = default;
  QDate get_date() { return date_; }
  double get_amount() { return amount_; }
  bool get_capital() { return capital_; }
  virtual void ProcessTransaction(double &balance, double rate, int days) = 0;

 protected:
  QDate date_;
  double amount_;
  bool capital_;
};

class Deposit : public Transaction {
 public:
  Deposit(QDate date, double amount, bool capital = false)
      : Transaction(date, amount, capital) {}
  void ProcessTransaction(double &balance, double rate, int days) override {
    if (this->capital_) {
      balance += balance * rate * days / 100 / 365;
    } else {
      balance += amount_;
      balance += balance * rate * days / 100 / 365;
    }
  }
};

class Withdraw : public Transaction {
 public:
  Withdraw(QDate date, double amount) : Transaction(date, amount) {}
  void ProcessTransaction(double &balance, double rate, int days) override {
    balance -= this->amount_;
    balance += balance * rate * days / 100 / 365;
  }
};
};      // namespace s21
#endif  // TRANSACTION_H
