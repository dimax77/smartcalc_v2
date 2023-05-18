#ifndef _PARSER_H_
#define _PARSER_H_

#include <list>
#include <stack>
#include <string>

namespace s21 {
class ConvertToPostfix {
  std::string in_{};
  std::list<std::string> output_tokens_{};
  std::string accessible_tokens_after_digit_ = "-+*/)m^";
  std::string postfix_string_;
  std::stack<char> operators_;

  inline bool is_num(char c) {
    return (c >= '0' && c <= '9') || c == '.' || c == 'x';
  }
  inline bool is_func(char c) { return strchr("-+*/^cstaivlomq", c); }
   void move_operator_to_output_tokens_() {
    // output_tokens_.push_back(std::string(1, operators_.top()));
    std::cout<< "Pushed - " << operators_.top() << std::endl;
    operators_.pop();
  }

  int precedence(char op) {
    if (op == '+' || op == '-') {
      return 1;
    } else if (op == '*' || op == '/' || op == 'm') {
      return 2;
    } else if (op == '^') {
      return 3;
    } else if (op == 'c' || op == 's' || op == 't' || op == 'a' || op == 'i' ||
               op == 'v' || op == 'q') {
      return 4;
    } else {
      return 0;
    }
  }

 public:
  void set_input_string(std::string raw) { in_ = raw; }
  void translate() {
    std::size_t size = in_.length(), idx = 0, temp_idx{};
    bool status = true, no_num = true;
    std::stack<char> operators{};
    operators.push('S');
    std::cout << size << std::endl;
    while (idx < size) {
      char c = in_[idx];
      if (is_num(c)) {  // Number
        std::cout << idx << std::endl;
        double n = std::stod(in_.substr(idx), &temp_idx);
        output_tokens_.push_back(std::to_string(n));
        no_num = false;
        idx += (temp_idx - 1);
        // if (!strchr(accessible_tokens_after_digit_, in_[idx])) {
        //   throw("Malformed expression.");
        // }
      } else if (is_func(c)) {  // Operator
        if (c == '-' && no_num) {
          operators.push('u');
        } else {
          while (precedence(c) <= precedence(operators.top())) {
            move_operator_to_output_tokens_();
          }
          operators.push(c);
          std::cout << c << std::endl;
          no_num = true;
        }
      } else if (c == '(') {  // Open brace
        if (is_num(in_[idx - 1])) throw "Error";
        operators.push(c);
      } else if (c == ')') {  // Close brace
        while (operators.top() != '(') {
          move_operator_to_output_tokens_();
        }
        operators.pop();  // drop the '('
      }
      idx += 1;
    }
    while (operators.top() != 'S') {
                  std::cout << operators.top() << std::endl;

        move_operator_to_output_tokens_();
    }
    // operators.pop();
  }
  std::string postfix_string() {
    std::cout << "Start" << std::endl;
    while (!output_tokens_.empty()) {
      postfix_string_ += output_tokens_.front();
      output_tokens_.pop_front();
    }
    std::cout << "End" << std::endl;

    return postfix_string_;
  }
};
}  // namespace s21

#endif  // _PARSER_H_
