#include "basic.h"


double exp(double x) {
  // Calculates exponentiation as a series:
  // e^x = 1 + x + x^2/2! + ... + x^n / n!
  // The error is given by a limiting factor for the integral form
  // of the remainder of the series: Rn(x) <= (4^x * x^(n+1))/(n+1)! 

  // We want to iterate on n until: x^(n+1) / n! <= precision/4^x
  double precision_find = PRECISION * exp_2_int(-2 * ceil(x));

  int n = 1;
  double value = 1;
  double current_term = 1;
  double next_term = x;
  
  while (abs(next_term) > precision_find) {
    value += next_term;
    
    ++n;
    current_term = next_term;    
    next_term = current_term * x / (double)n;
  }

  return value;      
}


double ln(double x) {
  // Calculate ln as the alternating series ln(x+1) = (-1)^n x^n/n.
  // By the alternating series test, the remainder for the series is less
  // than the next term.
  // Since uniform convergence only exists for x in (0,2], a trick is needed to calculate
  // ln(x) where x > 2.
  //
  // If we set M = ceil(log2(x)), we can rewrite x as 2^M * x / 2^M.
  // But log(2^M * x / 2^M) = log(2^M) + log(x/2^M) = M * log(2) + log(x/2^M).
  // But since M = ceil(log2(x)) -> 2^M > x, thus x/2^M < 1 and we can compute the log.

  double factorization = 0;
  if(x >= 2) {
    double M = ceil_log_2(x);
    factorization = M * log_2;
    x = x / exp_2_int(M);
  }

  // The series computes ln(x+1), so to obtain ln(x), we need to calculate for x-1.
  x -= 1;
  
  int n = 2;
  double value = x;
  double next_xn = x*x;
  double error = next_xn / 2.0;
  int sign = 1;

  while (abs(error) > PRECISION) {
    sign = -sign;
    value += sign * error;

    ++n;
    next_xn *= x;
    error = next_xn / ((double)n);
  }

  return factorization + value;  

}

double pow(double a, double x) {
  // Calculate a power based on exp:
  // We split x into its integer and real parts: x = i + y.
  // a^x = a^i * a^y
  // We can iteratively calculate a^i, because ceil(x) is an integer,
  // so we avoid unecessary rounding errors.
  // To calculate a^y, we use:  
  // a^y = e^(ln a^y) = e^(y ln a)
  
  double integer_power = ceil(abs(x));
  double fractional_power = abs(x) - integer_power;

  double integer_part = 1;
  for (int i = 0; i < integer_power; ++i) {
    integer_part *= a;
  }

  double value = integer_part * exp(fractional_power * ln(a));
  if (x < 0) {
    value = 1.0 / value;
  }
  
  return value;
}


double log(double a, double x) {
  // Calculate log_a x based on ln
  // log_a x = c <-> a^c = x
  // But a^c = e^(c * ln a)
  // So, e^(c * ln a) = x and appling ln on both sides:
  // c * ln a = ln x
  //
  // And finally
  // c = ln x / ln a
  
  return ln(x) / ln(a);    
}


