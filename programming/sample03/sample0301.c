/* sample0301.c */
#include <stdio.h>
#include <math.h>

int main()
{
  int i,n;
  double x,x1,y1;
  double xfunction();

  /*  printf("data number n="); */
  /*   scanf("%d",&n); */

  n=100;
  
  for (i=1; i <= n; i++) {
    x1=1.;
  printf("input x=");
  scanf("%lf",&x1);
  if(fabs(x1)>=100){return 0;}
  y1=xfunction(x1);

      printf("%e %e \n", x1, y1);
  }
}

  double xfunction(x)
    double x;
  {
    return(exp(x)-sin(x)-2.);
  }
