#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <QDate>
#include <algorithm>

namespace s21 {
class Transaction {
protected:
  QDate date_;
  double amount_;
  bool capital_;

public:
  Transaction(QDate date, double amount, bool capital = false)
      : date_(date), amount_(amount), capital_(capital) {}
  QDate getDate() { return date_; }
  double getAmount() { return amount_; }
  bool getCapital() { return capital_; }
  virtual void processTransaction(double &balance, double rate, int days) = 0;
};

class Deposit : public Transaction {
public:
  Deposit(QDate date, double amount, bool capital)
      : Transaction(date, amount, capital) {}

  void processTransaction(double &balance, double rate, int days) override {
    if (this->capital_) {
      double profit = balance * rate * days;
      balance += profit;
    } else {
      balance += this->amount_;
      double profit = balance * rate * days;
      balance += profit;
    }
  }
};

class Withdraw : public Transaction {
public:
  Withdraw(QDate date, double amount) : Transaction(date, amount) {}
  void processTransaction(double &balance, double rate, int days) override {
    balance -= this->amount_;
    double profit = balance * rate * days;
    balance += profit;
  }
};
};     // namespace s21
#endif // TRANSACTION_H
