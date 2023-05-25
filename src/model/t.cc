#include <iostream>
#include <string>

int main() {
  double n = 3.000000;
  std::string str = std::to_string(n);

  // Удаление нулей в десятичной части
  size_t dotPos = str.find('.');
  if (dotPos != std::string::npos) {
    size_t lastNonZero = str.find_last_not_of('0');
    if (lastNonZero != std::string::npos && lastNonZero > dotPos) {
      str.erase(lastNonZero + 1);
    }
  }

  std::cout << "Converted string: " << str << std::endl;
  return 0;
}
