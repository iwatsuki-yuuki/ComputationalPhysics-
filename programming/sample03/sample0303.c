/*  sample0401.c Newton method */
#include <stdio.h>
#include <math.h>

int main()
{
  int i,n;
  double x[11];
  double f(),df();

  n=9;
  x[0]=5.0;

  for (i=0; i <= n; i++) {

    x[i+1]=x[i] - f(x[i]) / df (x[i]);  /* correct this line for Newton method */
    
    printf("x(%d)=%e f(x)=%e res=%e\n", i+1,x[i+1], f(x[i+1]), fabs(x[i+1]-x[i]));
  }
}

  double f(x)
    double x;
  {
    return(exp(x)-sin(x)-2.);
  }

  double df(x)
    double x;
  {
    return(exp(x)-cos(x));
  }
