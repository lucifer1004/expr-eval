#ifndef CALCULATOR_CALCULATOR_H
#define CALCULATOR_CALCULATOR_H

#include <cmath>
#include <stack>
#include <string>

using namespace std;

class Calculator {
  static int priority(char c);
  static int operate(int a, char op, int b);

public:
  static int eval(string s);
};

#endif //CALCULATOR_CALCULATOR_H
