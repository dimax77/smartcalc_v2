#ifndef STACK_H
#define STACK_H

namespace s21 {
class stack {
  struct node {
    double val_{};
    node* pred_{};
  };

 public:
  void push(double cop) {
    node* tmp = new node;
    tmp->val_ = cop;
    tmp->pred_ = this->head_;
    this->head_ = tmp;
  }
  double pop() {
    double val;
    node* temp = this->head_;
    val = temp->val_;
    this->head_ = temp->pred_;
    delete temp;
    return val;
  }
  int gettop() const {
    int res = 0;
    if (head_) {
      res = head_->val_;
    } else {
      throw("Stack is empty");
    }
    return res;
  }

 private:
  node* head_{};
};
};  // namespace s21

#endif  // STACK_H