#ifndef POSTFIX_H
#define POSTFIX_H
#include <cstring>
#include <string>

#include "stack.h"

namespace s21 {
class postfix {
 private:
  std::string in_;
  std::string out_;

 public:
  bool isNum(char c) {
    bool yes = false;
    if (c > 47 && c < 58) {
      yes = true;
    }
    return yes;
  }

  void to_postfix(std::string& src, std::string& dest) {
    int n = src.length;
    //   stack* head = stack_init();
    bool err = false;
    bool no_num = true;
    stack stack;
    int j = 0, i = 0;
    for (; i < n; i++, j++) {
      char c = a[i];
      if (isNum(c)) {
        dest[j] = c;
        no_num = false;
      } else if (c == '.') {
        if (!isNum(dest[j - 1])) dest[j++] = '0';
        dest[j] = c;
      } else if (c == 'x') {
        dest[j] = c;
        no_num = false;
      } else {
        if (c == '^') {
          while (stack.gettop() == 'u') dest[j++] = stack.pop();
          push(c, &head);
        } else if (strchr("-+*/(", c) != NULL) {
          switch (c) {
            case '(':
              no_num = 1;
              stack.push(c);
              break;
            case '/':
            case '*':
              while (stack.gettop() == '*' || stack.gettop() == '/' ||
                     stack.gettop() == 's' || stack.gettop() == 'c' ||
                     stack.gettop() == 't' || stack.gettop() == 'q' ||
                     stack.gettop() == 'l' || stack.gettop() == 'o' ||
                     stack.gettop() == 'm' || stack.gettop() == 'a' ||
                     stack.gettop() == '^' || stack.gettop() == 'u') {
                dest[j++] = stack.pop();
              }
              stack.push(c);
              break;
            case '+':
            case '-':
              if (no_num) {
                if (c == '-') stack.push('u');
              } else {
                no_num = 1;
                while (stack.gettop() == '+' || stack.gettop() == '*' ||
                       stack.gettop() == '/' || stack.gettop() == '-' ||
                       stack.gettop() == 's' || stack.gettop() == 'c' ||
                       stack.gettop() == 't' || stack.gettop() == 'q' ||
                       stack.gettop() == 'l' || stack.gettop() == 'o' ||
                       stack.gettop() == 'm' || stack.gettop() == 'a' ||
                       stack.gettop() == '^' || stack.gettop() == 'u') {
                  dest[j++] = stack.pop();
                }
                stack.push(c);
              }
              break;
          }
        } else if (strchr("acmlst", c) != NULL) {
          switch (c) {
            case 'a':
              if (m[i + 1] == 'c' && m[i + 2] == 'o' && m[i + 3] == 's') {
                stack.push('a');
                i += 3;
              } else if (m[i + 1] == 's' && m[i + 2] == 'i' &&
                         m[i + 3] == 'n') {
                stack.push('i');
                i += 3;
              } else if (m[i + 1] == 't' && m[i + 2] == 'a' &&
                         m[i + 3] == 'n') {
                stack.push('v');
                i += 3;
              } else {
                err = 1;
                break;
              }
              break;
            case 'c':
              if (m[i + 1] == 'o' && m[i + 2] == 's') {
                stack.push(c);
                i = i + 2;
              } else {
                err = 1;
                break;
              }
              break;
            case 'm':
              if (m[i + 1] == 'o' && m[i + 2] == 'd') {
                if (no_num) {
                  err = 1;
                  break;
                }
                stack.push('m');
                i += 2;
              } else {
                err = 1;
                break;
              }
              break;
            case 'l':
              if (m[i + 1] == 'n') {
                stack.push(c);
                i = i + 1;
              } else if (m[i + 1] == 'o' && m[i + 2] == 'g') {
                stack.push('o');
                i += 2;
              } else {
                err = 1;
                break;
              }
              break;
            case 's':
              if (m[i + 1] == 'q' && m[i + 2] == 'r' && m[i + 3] == 't') {
                c = 'q';
                stack.push(c);
                i = i + 3;
              } else if (m[i + 1] == 'i' && m[i + 2] == 'n') {
                stack.push(c);
                i = i + 2;
              } else {
                err = 1;
                break;
              }
              break;
            case 't':
              if (m[i + 1] == 'a' && m[i + 2] == 'n') {
                stack.push(c);
                i = i + 2;
              } else {
                err = 1;
                break;
              }
              break;
          }
        } else if (c == ')') {
          while (stack.gettop() != '(') {
            dest[j] = stack.pop();
            j++;
            if (stack.gettop() == -1) {
              err = 1;
              break;
            }
          }
          if (err) break;
          stack.pop();
        } else {
          err = 1;
          break;
        }
      }
    }
    while (stack.gettop() != -1) {
      char rest = stack.pop();
      if (rest == '(') err = 1;
      dest[j++] = rest;
    }
    dest[j] = 0;
    if (err) {
      strcpy(dest, "error");
    }
    return err;
  }
};
};  // namespace s21

#endif  // POSTFIX_H