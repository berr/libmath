#include "libmath.h"

#include <iostream>
#include <iomanip>

int main() {

  std::cout << std::setprecision(25);
  
  //std::cout << "e^0 = " << exp(0) << std::endl;
  std::cout << "e^1 = " << exp(1) << std::endl;
  //std::cout << std::setprecision(16) << "e^100 = " << exp(100) << std::endl;

  //std::cout << ceil(4) << std::endl;
  //std::cout << exp_2_int(4) << std::endl;
  std::cout << "ln(2) = " << ln(2) << std::endl;
  //std::cout << "ln(9) = " << ln(9) << std::endl;
  //std::cout << "ln(8) = " << ln(8) << std::endl;
  //std::cout << "ln(0.5625) = " << ln(0.5625) << std::endl;
  //std::cout << "ln(72) = " << ln(72) << std::endl;

  std::cout << "10^3 = " << pow(10, 3) << std::endl;
  std::cout << "log2(16) = " << log(2, 16) << std::endl;
  std::cout << "log2.3(6597) = " << log(2.3, 6597) << std::endl;
  
  


  return 0;
}
