#ifndef CREDIT_H
#define CREDIT_H

namespace s21 {
class credit_calculator {
  int srok_{};
  double summa_credita_{};
  double stavka_{};
  bool diff_type_{};

public:
  void set_credit_data(int srok, double summa, double stavka, bool diff_type) {
    srok_ = srok;
    summa_credita_ = summa;
    stavka_ = stavka;
    diff_type_ = diff_type;
  }
  void proccess_data() {}
};
}; // namespace s21

#endif // CREDIT_H
