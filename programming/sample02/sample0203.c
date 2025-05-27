/* sample0203.c */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
  int i, n;
  float e,h,eee,dif;
  FILE *outfile;

  eee=exp(1.0);

  outfile = fopen("out_s.txt", "w");

  n=20;
  for (i=1;i<=n; i++) {

  h = powf(10.0, (-i));
  e = powf((1.0+h), (1./h));

  dif=fabs(eee-e);

  fprintf(outfile, "%e %e %e \n",h,dif,e);
  printf("%e %e %e \n",h,dif,e);
    }

  fclose(outfile);
  
  return 0;
}
