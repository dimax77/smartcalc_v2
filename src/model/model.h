#ifndef MODEL_H
#define MODEL_H
#include "base_calculator.h"
#include "credit_calculator.h"

namespace s21 {
class model : public Calculator {
  s21::credit_calculator credit_;

public:
  void set_credit_data(int duration, double amount, double rate,
                       double diff_type) {
    credit_.set_credit_data(duration, amount, rate, diff_type);
  };

private:
};
};     // namespace s21
#endif // MODEL_H
