
#include <iostream>
#include <stack>
#include <string>

bool isMathExpressionValid(const std::string& expression) {
  std::stack<std::string> stack;

  for (size_t i = 0; i < expression.size(); ++i) {
    const char c = expression[i];

    switch (c) {
      case '(':
        stack.push("(");
        break;
      case ')':
        if (stack.empty() || stack.top() != "(") {
          return false;
        }
        stack.pop();
        break;
      case '+':
      case '-':
      case '*':
      case '/':
      case '^':
        stack.push(std::string(1, c));
        break;
      case 's':
      case 'c':
      case 't':
      case 'l':
        if (expression.substr(i, 3) == "sin" ||
            expression.substr(i, 3) == "cos" ||
            expression.substr(i, 2) == "tg" ||
            expression.substr(i, 2) == "ct" ||
            expression.substr(i, 2) == "ln") {
          stack.push(expression.substr(i, 3));
          i += 2;
        } else if (expression.substr(i, 2) == "lg" ||
                   expression.substr(i, 2) == "og") {
          stack.push(expression.substr(i, 2));
          i += 1;
        } else {
          return false;
        }
        break;
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
      case '.':
        while (i < expression.size() && std::isdigit(expression[i])) {
          ++i;
        }
        if (i < expression.size() && expression[i] == '.') {
          ++i;
          while (i < expression.size() && std::isdigit(expression[i])) {
            ++i;
          }
        }
        --i;
        try {
          std::stod(expression.substr(i));
          stack.push("number");
        } catch (...) {
          return false;
        }
        break;
      case ' ':
        break;
      default:
        return false;
    }
  }

  return stack.size() == 1 && stack.top() == "number";
}

