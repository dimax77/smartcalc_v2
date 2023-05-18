#ifndef POSTFIX_H
#define POSTFIX_H
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <string>

namespace s21 {
class postfix {
public:
  inline bool is_num(char c) { return c >= '0' && c <= '9'; }
  void set_input_string(const std::string &raw) { in_ = raw; }
  std::string get_res_string() { return out_; }
  double get_res() { return res_; }
  bool to_postfix() {
    out_ = "";
    bool err = false;

      int n = in_.length();
      out_.resize(n * 2, ' ');
      bool no_num = true;
      int j = 0, i = 0;
      for (; i < n; i++, j++) {
        char c = in_[i];
        if (is_num(c) || c == 'x') {
          out_[j] = c;
          no_num = false;
        } else if (c == '.' || c == ',') {
          if (!is_num(out_[j - 1]))
            out_[j++] = '0';
          out_[j] = c;
        } else {
          if (c == '^') {
            if (!stack_.empty()) {
              while (stack_.top() == 'u') {
                out_[j++] = stack_.top();
                stack_.pop();
                if (stack_.empty())
                  break;
              }
            }
            stack_.push(c);
          } else if (strchr("-+*/(", c) != NULL) {
            switch (c) {
            case '(':
              no_num = true;
              stack_.push(c);
              break;
            case '/':
            case '*':
              no_num = true;
              if (!stack_.empty()) {
                while (stack_.top() == '*' || stack_.top() == '/' ||
                       stack_.top() == 's' || stack_.top() == 'c' ||
                       stack_.top() == 't' || stack_.top() == 'q' ||
                       stack_.top() == 'l' || stack_.top() == 'o' ||
                       stack_.top() == 'm' || stack_.top() == 'a' ||
                       stack_.top() == '^' || stack_.top() == 'u') {
                  out_[j++] = stack_.top();
                  stack_.pop();
                  if (stack_.empty())
                    break;
                }
              }
              stack_.push(c);
              break;
            case '+':
            case '-':
              if (no_num) {
                if (c == '-')
                  stack_.push('u');
              } else {
                no_num = true;
                if (!stack_.empty()) {
                  while (stack_.top() == '+' || stack_.top() == '*' ||
                         stack_.top() == '/' || stack_.top() == '-' ||
                         stack_.top() == 's' || stack_.top() == 'c' ||
                         stack_.top() == 't' || stack_.top() == 'q' ||
                         stack_.top() == 'l' || stack_.top() == 'o' ||
                         stack_.top() == 'm' || stack_.top() == 'a' ||
                         stack_.top() == '^' || stack_.top() == 'u') {
                    out_[j++] = stack_.top();
                    stack_.pop();
                    if (stack_.empty())
                      break;
                  }
                }
                stack_.push(c);
              }
              break;
            }
          } else if (strchr("acmlst", c) != NULL) {
            switch (c) {
            case 'a':
              if (in_[i + 1] == 'c' && in_[i + 2] == 'o' && in_[i + 3] == 's') {
                stack_.push('a');
                i += 3;
              } else if (in_[i + 1] == 's' && in_[i + 2] == 'i' &&
                         in_[i + 3] == 'n') {
                stack_.push('i');
                i += 3;
              } else if (in_[i + 1] == 't' && in_[i + 2] == 'a' &&
                         in_[i + 3] == 'n') {
                stack_.push('v');
                i += 3;
              } else {
                err = 1;
                break;
              }
              break;
            case 'c':
              if (in_[i + 1] == 'o' && in_[i + 2] == 's') {
                stack_.push(c);
                i = i + 2;
              } else {
                err = 1;
                break;
              }
              break;
            case 'm':
              if (in_[i + 1] == 'o' && in_[i + 2] == 'd') {
                if (no_num) {
                  err = true;
                  break;
                }
                stack_.push('m');
                i += 2;
              } else {
                err = true;
                break;
              }
              break;
            case 'l':
              if (in_[i + 1] == 'n') {
                stack_.push(c);
                i = i + 1;
              } else if (in_[i + 1] == 'o' && in_[i + 2] == 'g') {
                stack_.push('o');
                i += 2;
              } else {
                err = true;
                break;
              }
              break;
            case 's':
              if (in_[i + 1] == 'q' && in_[i + 2] == 'r' && in_[i + 3] == 't') {
                c = 'q';
                stack_.push(c);
                i = i + 3;
              } else if (in_[i + 1] == 'i' && in_[i + 2] == 'n') {
                stack_.push(c);
                i = i + 2;
              } else {
                err = true;
                break;
              }
              break;
            case 't':
              if (in_[i + 1] == 'a' && in_[i + 2] == 'n') {
                stack_.push(c);
                i = i + 2;
              } else {
                err = true;
                break;
              }
              break;
            }
          } else if (c == ')') {
            while (!stack_.empty() && stack_.top() != '(') {
              out_[j] = stack_.top();
              stack_.pop();
              j++;
            }
            if (stack_.empty()) {
              err = true;
            } else {
              stack_.pop();
            }
          } else {
            err = true;
            break;
          }
        }
      }
      while (!stack_.empty()) {
        char rest = stack_.top();
        stack_.pop();
        if (rest == '(')
          err = true;
        out_[j++] = rest;
      }
      if (err) {
        out_ = "error";
      }
      in_ = "";
   
    return err;
  }
  double eval(double x) {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    double n1{}, n2{}, res{};
    int count = out_.length();
    for (int i = 0; i < count; ++i) {
      if (is_num(out_[i])) {
        char num[count];
        int j = 0;
        while (is_num(out_[i])) {
          num[j++] = out_[i++];
          if (out_[i] == '.') {
            num[j++] = ',';
            ++i;
          } else if (out_[i] == ',') {
            num[j++] = ',';
            ++i;
          }
        }
        i = i - 1;
        const double n = std::stod(num);
        stack_double.push(n);
      } else if (out_[i] == 'x') {
        stack_double.push(x);
      } else if (strchr("-+*/mp", out_[i]) != NULL) {
        n2 = stack_double.top();
        stack_double.pop();
        n1 = stack_double.top();
        stack_double.pop();
        switch (out_[i]) {
        case '+':
          res = n1 + n2;
          break;
        case '-':
          res = n1 - n2;
          break;
        case '*':
          res = n1 * n2;
          break;
        case '/':
          res = n1 / n2;
          break;
        case 'm':
          res = (int)n1 % (int)n2;
          break;
        case 'p':
          res = pow(n1, n2);
          break;
        }
        stack_double.push(res);
      } else if (strchr("aciloqstuv", out_[i]) != NULL) {
        n1 = stack_double.top();
        stack_double.pop();
        switch (out_[i]) {
        case 'a':
          res = acos(n1);
          break;
        case 'c':
          res = cos(n1);
          break;
        case 's':
          res = sin(n1);
          break;
        case 't':
          res = tan(n1);
          break;
        case 'i':
          res = asin(n1);
          break;
        case 'q':
          res = sqrt(n1);
          break;
        case 'o':
          res = log10f(n1);
          break;
        case 'l':
          res = log(n1);
          break;
        case 'v':
          res = atan(n1);
          break;
        case 'u':
          res = n1 * (-1);
          break;
        }
        stack_double.push(res);
      }
    }
    res = stack_double.top();
    stack_double.pop();
    
    res_ = res;
    return res;
  }
  void clear() { // Отбрасываю пробелы для тестов сравнения строк
    int count = out_.length();
    std::string tmp;
    for (int i = 0; i < count; i++) {
      if (out_[i] == ' ')
        continue;
      tmp += out_[i];
    }
    out_ = tmp;
  }

private:
  std::string in_{};
  std::string out_{};
  std::stack<char> stack_;
  std::stack<double> stack_double;
  double res_;
};
};     // namespace s21
#endif // POSTFIX_H
