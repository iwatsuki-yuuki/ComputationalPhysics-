/* sample0201.c */
#include <stdio.h>
#include <math.h>

int main()
{
  short int a1, a2, a3, a4, a5, a6;
  short int b1, b2, b3, b4, b5, b6;
  short int c1, c2, c3;

  a1 = 10;
  a2 = 9;
  a3 = 8;
  a4 = 7;
  a5 = 6;
  a6 = 5;

  b1 = 6;
  b2 = 5;
  b3 = 4;
  b4 = 3;
  b5 = 2;
  b6 = 1;

  c1 = (a1*a2*a3*a4*a5*a6);
  c2 = (b1*b2*b3*b4*b5*b6);
  c3 = c1/c2;
 /* c3 = (a1*a2*a3*a4*a5*a6)/(b1*b2*b3*b4*b5*b6); */

  printf("%d\n",c3);
  
  return 0;
}
