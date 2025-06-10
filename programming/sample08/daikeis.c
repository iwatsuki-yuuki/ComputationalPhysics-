/* trapezoidal rule */
#include <math.h>
#include <stdio.h>
float kansuu(float x) ;

int main()
{
  int i,n,nn,nnn;
  float x1,xs,xf,h,sum;
  float fx, pi;
  FILE *fp;

   printf("          n            pi          h          error  \n") ;

   fp=fopen("daikeis.txt", "w");
       
  pi=3.14159265359 ;
    
  /*  n=1000 ; */
  nnn=15 ;

    for(nn=0 ; nn<nnn ; ++nn)
      {
        n=(int)pow((float)2,(float)nn) ;
  
        sum=0. ;
        x1=0. ;
        xs=0. ;
        xf=1. ;
        h=(xf-xs)/(float)n ;

        sum+=h*kansuu(xs)/2. ;
        sum+=h*kansuu(xf)/2. ;
  
       x1=xs ;
   for(i=1 ; i<n ; ++i)
      {
	x1+=h ;
	
	sum+=kansuu(x1)*h ;
	  
      }

   printf("%12d  %16.12lf %le %le \n",n, sum, h, fabs(sum-pi)) ;

   fprintf(fp, "%le %le \n", h, fabs(sum-pi)) ;
}
}

float kansuu(float x)
{
  float fx=4./(1.+x*x) ;
  return fx ;
}
