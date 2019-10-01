#include "calculator.h"

using namespace std;

int Calculator::priority(char c) {
  switch (c) {
    case '+':
    case '-':
      return 1;
    case '*':
    case '/':
      return 2;
    case '^':
      return 3;
    case '(':
      return 4;
    default:
      return 0;
  }
}

int Calculator::operate(int a, char op, int b) {
  switch (op) {
    case '+':
      return a + b;
    case '-':
      return a - b;
    case '*':
      return a * b;
    case '/':
      return a / b;
    case '^':
      return pow(a, b);
    default:
      return 0;
  }
}

int Calculator::eval(string s) {
  s += ")";
  stack<int> nums;
  stack<char> ops;
  ops.push('(');
  int curr = 0;
  int digit = 0;
  for (int i = 0; i < s.size(); ++i) {
    switch (s[i]) {
      case ')':
        if (digit > 0) nums.push(curr);
        curr = 0;
        digit = 0;
        while (ops.top() != '(') {
          char op = ops.top();
          ops.pop();
          if (nums.size() >= 2) {
            int b = nums.top();
            nums.pop();
            int a = nums.top();
            nums.pop();
            nums.push(operate(a, op, b));
          }
        }
        ops.pop();
        break;
      case '+':
      case '-':
      case '*':
      case '/':
      case '(':
      case '^':
        if (digit > 0) {
          nums.push(curr);
          if (s[i] == '(') ops.push('*');
        }
        curr = 0;
        digit = 0;
        while (ops.top() != '(' && priority(ops.top()) >= priority(s[i])) {
          char op = ops.top();
          ops.pop();
          if (nums.size() >= 2) {
            int b = nums.top();
            nums.pop();
            int a = nums.top();
            nums.pop();
            nums.push(operate(a, op, b));
          }
        }
        ops.push(s[i]);
        break;
      case ' ':
        break;
      default:
        curr = curr * 10 + s[i] - '0';
        digit++;
    }
  }
  return nums.top();
}