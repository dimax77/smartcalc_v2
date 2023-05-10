#ifndef EVAL_H
#define EVAL_H
#include <cmath>

double eval(double x) {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    double n1, n2, res;
    int count = out_.length();
    for (int i = 0; i < count; ++i) {
      if (is_num(out_[i])) {
        char num[count];
        int j = 0;
        while (is_num(out_[i])) {
          num[j++] = out_[i++];
          if (out_[i] == '.') {
            num[j++] = '.';
            ++i;
          } else if (out_[i] == ',') {
            num[j++] = '.';
            ++i;
          }
        }
        i = i - 1;
        num[j] = '\0';
        double n = atof(num);
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
    return res;
  }


#endif