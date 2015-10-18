#include "trig.h"


static inline double simplify_rad(double x) {
  // Uses the fact that trigonometric functions are periodic to avoid
  // calculations with big numbers.
  // sin(2pi * k + x) = sin(x)
  // cos(2pi * k + x) = cos(x)
  // where 0 <= x < 2pi
  
  const double two_pi = 2 * pi;
  while (x > two_pi) {
    x -= two_pi;
  }

  return x;
}


double cos(double x) {
  // Calculates the cosine of a real number (in radians)
  //
  // cos(x) = 1 - x^2/2! + x^4/4! + ... + (-1)^n - x^(2n) / (2n)!
  // The convergence is given by the alterating series test

  x = simplify_rad(x);
  if (abs(x) < PRECISION)
    return 1;
  if (abs(abs(x) - pi) < PRECISION)
    return -1;
  if (abs(abs(x) - pi / 2.0) < PRECISION)
    return 0;
  if (abs(abs(x) - 3.0 * pi / 2.0) < PRECISION)
    return 0;

  int n = 2;
  double value = 1;
  double x2 = x * x;
  double next_term = value * x2 / 2.0;
  int sign = 1;

    
  while(abs(next_term) > PRECISION) {
    sign = -sign;
    value += sign * next_term;

    n += 2;
    
    next_term = next_term * x2 / ((double) (n-1) * (n));    
  }


  return value;
}

double sec(double x) {
  return 1.0 / cos(x);
}


double sin(double x) {
  // Calculates the sine of a real number (in radians)
  //
  // sin(x) = x - x^3/3! + x^5/5! + ... + (-1)^n - x^(2n+1) / (2n+1)!
  // The convergence is given by the alterating series test
  x = simplify_rad(x);

  if (abs(x) < PRECISION)
    return 0;
  if (abs(abs(x) - pi) < PRECISION)
    return 0;
  if (abs(abs(x) - (pi / 2.0)) < PRECISION)
    return 1;
  if (abs(abs(x) - 3.0 * pi / 2.0) < PRECISION)
    return -1;
  
  int n = 3;
  double value = x;
  double x2 = x * x;
  double next_term = value * x2 / 6.0;
  int sign = 1;
    
  while(abs(next_term) > PRECISION) {
    sign = -sign;
    value += sign * next_term;

    n += 2;
    
    next_term = next_term * x2 / ((double) (n-1) * (n));    
  }


  return value;
  
}

double csc(double x) {
  return 1.0/sin(x);
}


double tan(double x) {
  return sin(x) / cos(x);    
}

double cot(double x) {
  return cos(x)/sin(x);
}

double radian_to_degree(double o){
  // pi * radians = 180 degrees
  // 1 * radian = 180 / pi
  // o radians = o * (180 / pi)
  return o * (180.0 / pi);

}

double degree_to_radian(double o) {
  // pi radians = 180 degrees
  // 1 degree = pi / 180
  // o degrees = o * pi / 180
  return o * (pi / 180.0);

}


