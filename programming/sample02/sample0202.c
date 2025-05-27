/* sample0202.c */
#include <stdio.h>
#include <math.h>

int main()
{
float a, b, c, d, s;

  a = 100001.0;
  b = 0.123456;
  c = 0.111111;
  d = -100000.0;

  s = 0.0;
  s += a;
  s += b;
  s += c;
  s += d;

  printf("%f\n",s);
  return 0;
}
