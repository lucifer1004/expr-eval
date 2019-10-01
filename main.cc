#include "calculator.h"
#include <cassert>

int main() {
  assert(Calculator::eval("1+2*8") == 17);
  assert(Calculator::eval("2^(2+3)") == 32);
  return 0;
}