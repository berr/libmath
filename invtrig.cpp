#include "invtrig.h"

#include <iostream>

double arcsin(double x) {
  // Computes the arcsin(x) = sin^(-1)(x). Which is the angle (in radians) that has the given sine.
  // The computation is done using Newton's method.
  // We want to find a x0 that |sin(x0) - x | < PRECISION.
  // The iteration is as usual, the initial value is always pi / 4, but in the same quadrant as x.
  // X_n+1 = Xn - f(Xn) / f'(Xn) = Xn - (sin(Xn) + x) / cos(Xn) = Xn - (sin(Xn) - x) / cos(Xn)
  double value = sign(x) * pi / 4.0;

  if (abs((abs(x) - 1)) < PRECISION)
    return sign(x) * pi / 2.0;

  if (abs(x) < PRECISION)
    return 0;

  double current_sin = sin(value);
  while (abs(current_sin - x) > PRECISION) {
    value = value - (current_sin - x) / cos(value);
    current_sin = sin(value);
  }

  return value;  
}

double arccos(double x) {
  // Computes the arccos(x) = cos^(-1)(x). Which is the angle (in radians) that has the given cosine.
  // The computation is done using Newton's method.
  // We want to find a x0 that |cos(x0) - x | < PRECISION.
  // The iteration is as usual, the initial value is always pi / 4, but in the same quadrant as x.
  // X_n+1 = Xn - f(Xn) / f'(Xn) = Xn - (-cos(Xn) + x) / sin(Xn) = Xn + (cos(Xn) - x) / sin(Xn)
  double value = pi / 4.0;
  if (x < 0)
    value += pi / 2.0;

  if (abs((abs(x) - 1)) < PRECISION) {
    if (x > 0)
      return 0;
    else
      return pi;
  }

  if (abs(x) < PRECISION)
    return pi / 2.0;

  double current_cos = cos(value);
  while (abs(current_cos - x) > PRECISION) {
    value = value + (current_cos - x) / sin(value);
    current_cos = cos(value);
  }

  return value;  
}


double arctan(double x) {
  // Computes the arctan(x) = tan^(-1)(x). Which is the angle (in radians) that has the given tangent.
  // If |x| <= 1 we can use the taylor series: arctan(x) = x - x^3/3 + x^5/5 - ... + (-1)^n+1 * x^(2n+1) / (2n+1)
  // If |x| > 1 then we can use the following trigonometric identity:
  // f(x) = arctan(x) + arctan(1/x) = sign(x) * pi/2
  // If we take the first derivative of f we get:
  // 1/(1 + x^2) - 1/(1 + x^2) = 0, for all x. Which means that f is constant.
  // Now, if we apply f at 0:
  // f(1) = arctan(1) + arctan(1) = 2 * pi / 4 = pi / 2
  // f(-1) = arctan(-1) + arctan(-1) = 2 * - pi / 4 = - pi / 2
  
  if (abs(x) > 1) {
    return sign(x) * pi / 2.0 - arctan(1.0/x);
  }

  
  int n = 3;
  double value = x;
  double x2 = x * x;
  double next_xn = x * x2;
  double error = next_xn / 3.0;
  int sign = 1;

  while (abs(error) > PRECISION) {
    //std::cout << error << std::endl;
    sign = -sign;
    value += sign * error;

    n += 2;
    next_xn *= x2;
    error = next_xn / ((double) n);    
  }


  return value;  
}


