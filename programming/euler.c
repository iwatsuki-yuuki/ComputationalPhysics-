/* Euler method (classical Runge-Kutta method) */
#include <math.h>
#include <stdio.h>
double fxd(double x), fx(double x);

int main()
{
  int n;
  double y,a,b,k,x,dif;

  /* use fixed step count */
  int nmax = 10;
  double h = 1.0 / nmax;

  printf(" n     x      Numerical   Exact     |Error|\n");
  x=0.;  y=0.;  n=0;
  printf("%2d %6.2lf %10.6lf %10.6lf %10.6lf\n", 0, x, y, fx(x), fabs(fx(x) - y));

  /* Modified Euler (Heun) method */
  for (n = 1; n <= nmax; n++) {
      double k1 = fxd(x);
      double x_temp = x + h;
      double y_temp = y + h * k1;
      double k2 = fxd(x_temp);
      y += (h / 2.0) * (k1 + k2);
      x += h;
      dif = fabs(fx(x) - y);
      printf("%2d %6.2lf %10.6lf %10.6lf %10.6lf\n", n, x, y, fx(x), dif);
  }
}
  
double fxd(double x)
{
  double fxd=1.-2*x ;
  return fxd ;
}
  
double fx(double x)
{
  double fx=x-x*x ;
  return fx ;
}
