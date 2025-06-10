/* trapezoidal rule */
#include <math.h>
#include <stdio.h>
double kansuu(double x) ;

int main()
{
  int i,n,nn,nnn;
  double x1,xs,xf,h,sum;
  double fx, pi;
  FILE *fp;

   printf("  n               pi            h            error\n") ;

   fp=fopen("daikeid.txt", "w");
       
  pi=3.14159265359 ;
    
  /*  n=1000 ; */
  nnn=7 ;  // 1, 2, 4, 8, 16, 32, 64まで計算

    for(nn=0 ; nn<nnn ; ++nn)
      {
        n=(int)pow((double)2,(double)nn) ;
  
        sum=0. ;
        x1=0. ;
        xs=0. ;
        xf=1. ;
        h=(xf-xs)/(double)n ;

        sum+=h*kansuu(xs)/2. ;
        sum+=h*kansuu(xf)/2. ;
  
       x1=xs ;
   for(i=1 ; i<n ; ++i)
      {
	x1+=h ;
	
	sum+=kansuu(x1)*h ;
	  
      }

   printf("%5d %16.12lf %le %le\n", n, sum, h, fabs(sum-pi)) ;

   fprintf(fp, "%le %le \n", h, fabs(sum-pi)) ;
}
}

double kansuu(double x)
{
  double fx=4./(1.+x*x) ;
  return fx ;
}

  
