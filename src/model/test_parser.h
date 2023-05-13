#include <cmath>
#include <iostream>
#include <list>
#include <stack>
#include <string>

// функция для определения приоритета оператора
int precedence(char op) {
  if (op == '+' || op == '-') {
    return 1;
  } else if (op == '*' || op == '/') {
    return 2;
  } else if (op == '^') {
    return 3;
  } else {
    return -1;
  }
}

// функция для проверки, является ли символ оператором
bool isOperator(char c) {
  return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// функция для проверки, является ли символ числом
bool isNumber(char c) { return (c >= '0' && c <= '9') || c == '.'; }

// функция для проверки, является ли символ буквой
bool isLetter(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// функция для определения приоритета функции
int functionPriority(std::string func) {
  if (func == "sin" || func == "cos" || func == "tg" || func == "ctg" ||
      func == "ln") {
    return 4;
  } else if (func == "log") {
    return 5;
  } else {
    return -1;
  }
}

// функция для перевода числа в строковом формате в double
double stringToDouble(std::string str) { return std::stod(str); }

// функция для перевода double в строковый формат
std::string doubleToString(double num) { return std::to_string(num); }

// функция для вычисления унарного минуса
double unaryMinus(double num) { return -num; }

// функция для вычисления унарного плюса
double unaryPlus(double num) { return num; }

// функция для вычисления операции с двумя операндами
double doOperation(double num1, double num2, char op) {
  if (op == '+') {
    return num1 + num2;
  } else if (op == '-') {
    return num1 - num2;
  } else if (op == '*') {
    return num1 * num2;
  } else if (op == '/') {
    return num1 / num2;
  } else if (op == '^') {
    return pow(num1, num2);
  } else {
    return 0;
  }
}

// функция для вычисления функции
// функция для вычисления функции
double doFunction(std::string func, double arg) {
  if (func == "sin") {
    return sin(arg);
  } else if (func == "cos") {
    return cos(arg);
  } else if (func == "tg") {
    return tan(arg);
  } else if (func == "ctg") {
    return 1.0 / tan(arg);
  } else if (func == "ln") {
    return log(arg);
  } else if (func == "log") {
    return log10(arg);
  } else {
    return 0;
  }
}

// основная функция парсинга выражения
double parseExpression(std::string expression) {
  std::stack<double> values;      // стек значений
  std::stack<char> operators;     // стек операторов
  std::list<std::string> tokens;  // список токенов

  // разбиваем выражение на токены
  std::string token = "";
  for (int i = 0; i < expression.length(); i++) {
    if (isNumber(expression[i]) || isLetter(expression[i])) {
      token += expression[i];
    } else if (isOperator(expression[i])) {
      if (!token.empty()) {
        tokens.push_back(token);
        token = "";
      }
      tokens.push_back(std::string(1, expression[i]));
    } else if (expression[i] == '(' || expression[i] == ')') {
      if (!token.empty()) {
        tokens.push_back(token);
        token = "";
      }
      tokens.push_back(std::string(1, expression[i]));
    }
  }
  if (!token.empty()) {
    tokens.push_back(token);
  }

  for (auto token : tokens) {
    // если токен - число, то добавляем его в стек значений
    if (isNumber(token[0])) {
      values.push(stringToDouble(token));
    }
    // если токен - буква, то проверяем, является ли он функцией, и добавляем в
    // стек операторов
    else if (isLetter(token[0])) {
      if (token == "pi") {
        values.push(M_PI);
      } else if (functionPriority(token) > 0) {
        operators.push(token[0]);
      }
    }
    // если токен - оператор
    else if (isOperator(token[0])) {
      // пока стек операторов не пуст и приоритет верхнего оператора больше или
      // равен приоритету текущего оператора
      while (!operators.empty() &&
             precedence(operators.top()) >= precedence(token[0])) {
        // достаем из стека операторов последний оператор
        char op = operators.top();
        operators.pop();

        // достаем из стека значений два последних значения
        double num2 = values.top();
        values.pop();
        double num1 = values.top();
        values.pop();

        // вычисляем операцию и добавляем результат в стек значений
        values.push(doOperation(num1, num2, op));
      }
      // добавляем текущий оператор в стек операторов
      operators.push(token[0]);
    }
    // если токен - открывающая скобка, то
    else if (token == "(") {
      operators.push(token[0]);
    }
    // если токен - закрывающая скобка, то
    else if (token == ")") {
      // пока верхний элемент стека операторов не является открывающей скобкой
      while (!operators.empty() && operators.top() != '(') {
        // достаем из стека операторов последний оператор
        char op = operators.top();
        operators.pop();

        // достаем из стека значений два последних значения
        double num2 = values.top();
        values.pop();
        double num1 = values.top();
        values.pop();

        // вычисляем операцию и добавляем результат в стек значений
        if (op == '(') {
          continue;
        } else if (functionPriority(std::string(1, op)) > 0) {
          values.push(doFunction(std::string(1, op), num2));
        } else {
          values.push(doOperation(num1, num2, op));
        }
      }
      // удаляем из стека операторов открывающую скобку
      if (!operators.empty() && operators.top() == '(') {
        operators.pop();
      }
    }
  }

  // вычисляем оставшиеся операции
  while (!operators.empty()) {
    // достаем из стека операторов последний оператор
    char op = operators.top();
    operators.pop();
    // достаем из стека значений два последних значения
    double num2 = values.top();
    values.pop();
    double num1 = values.top();
    values.pop();

    // вычисляем операцию и добавляем результат в стек значений
    if (op == '(') {
      continue;
    } else if (functionPriority(std::string(1, op)) > 0) {
      values.push(doFunction(std::string(1, op), num2));
    } else {
      values.push(doOperation(num1, num2, op));
    }
  }

  // возвращаем результат
  return values.top();
}
