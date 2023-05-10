#include <iostream>
#include <stack>
#include <string>

using namespace std;

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

string infixToPostfix(string infix) {
  stack<char> s;
  string postfix = "";

  for (int i = 0; i < infix.length(); i++) {
    char c = infix[i];
    if (isalnum(c)) {
      postfix += c;
    } else if (c == '(') {
      s.push(c);
    } else if (c == ')') {
      while (!s.empty() && s.top() != '(') {
        postfix += s.top();
        s.pop();
      }
      s.pop();  // remove '(' from stack
    } else {
      while (!s.empty() && precedence(c) <= precedence(s.top())) {
        postfix += s.top();
        s.pop();
      }
      s.push(c);
    }
  }

  while (!s.empty()) {
    postfix += s.top();
    s.pop();
  }

  return postfix;
}

int main() {
  string infix = "sin(2*x^2)-ln(---11)))";
  string postfix = infixToPostfix(infix);
  cout << "Infix: " << infix << endl;
  cout << "Postfix: " << postfix << endl;
  return 0;
}
