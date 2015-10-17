#include "basic.h"

int ceil(double x) {
  int value = (int) x;
  double difference = x - value;    
  return difference <= PRECISION ? value : value + 1;  
}

int floor(double x) {
  int value = (int) x;
  double difference = x - value;    
  return difference <= PRECISION ? value -1 : value;  
}


double abs(double x) {  
  return x > 0? x : -x;  
}


double exp_2_int(int n) {
  double result = 1 << ceil(abs(n));
  if (n < 0)
    result = 1.0 / result;
  
  return result;
}

double ceil_log_2(double x) {
  int n = 1;
  
  while (x > 2) {
    ++n;
    x /= 2;    
  }

  return n;
}


