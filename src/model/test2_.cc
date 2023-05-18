#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

bool isOperand(char c) {
    return (c >= '0' && c <= '9' || c == 'x');
}

int getPrecedence(char op) {
    if (op == '^') {
        return 3;
    }
    else if (op == '*' || op == '/') {
        return 2;
    }
    else if (op == '+' || op == '-') {
        return 1;
    }
    else {
        return -1;
    }
}

bool isMathExpressionValid(string exp) {
    stack<char> st;
    st.push('N');
    int len = exp.length();
    for (int i = 0; i < len; i++) {
        char c = exp[i];
        if (isOperand(c)) {
            continue;
        }
        else if (isOperator(c)) {
            while (st.top() != 'N' && getPrecedence(c) <= getPrecedence(st.top())) {
                st.pop();
            }
            st.push(c);
        }
        else if (c == '(') {
            st.push('(');
        }
        else if (c == ')') {
            while (st.top() != 'N' && st.top() != '(') {
                st.pop();
            }
            if (st.top() == '(') {
                st.pop();
            }
            else {
                return false;
            }
        }
    }
    while (st.top() != 'N') {
        st.pop();
    }
    return (st.empty());
}

int main() {
    string expression1 = "a+b";
    string expression2 = "cos(sin(3-4x))^5";
    string expression3 = "sin(5-5x)))))";
    cout << expression1 << " is " << (isMathExpressionValid(expression1) ? "valid" : "invalid") << endl;
    cout << expression2 << " is " << (isMathExpressionValid(expression2) ? "valid" : "invalid") << endl;
    cout << expression3 << " is " << (isMathExpressionValid(expression3) ? "valid" : "invalid") << endl;
    return 0;
}
