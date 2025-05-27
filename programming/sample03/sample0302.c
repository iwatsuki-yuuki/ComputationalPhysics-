/*  sample0302.c */
#include <stdio.h>
#include <math.h>

int main()
{
  int i,n;
  double x,x0,x1,y0,y1,xs,xf,xm,ym,dx;
  double f();

  xs=0.;
  xf=10.;
  dx=1.e-6;
  n=50;

  for (i=1; i <= n; i++) {
    x0=xs;
    x1=xf;
    xm=(xs+xf)/2.;
    y0=f(x0);
    y1=f(x1);
    ym=f(xm);

      if(y0*ym <= 0.) {
      printf("%e %e %e \n", x0, xm, y0*ym);

    xs=x0;
    xf=xm;
     }
  else if(y1*ym <= 0.) {
  printf("%e %e %e \n", xm, x1, y1*ym);

    xs=xm;
    xf=x1;
  }

      if((fabs(xs-xf))<=dx) {
      printf("fin x=%e dx=%e\n", 0.5*(xs+xf) , dx);
        return(0);
      }
  }
}

  double f(x)
    double x;
  {
    return(exp(x)-sin(x)-2.);
  }
