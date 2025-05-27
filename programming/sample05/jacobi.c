/* Jacobi's method */

#include <stdio.h>
#include <math.h>
#define NN 50
#define MAX_ITER 50
#define eps 1e-6
#define alp 1.0

int main()
{
  int i,j,k,n,nn,iter,ok;
  double a[NN][NN] ;
  double b[NN] ;
  double x[NN],xn[NN] ;
  double p,q,s;
  FILE *file;
  
  /* read data file */
  
  fscanf(stdin, "%d",&n);
  for (i=0; i<n ;++i)
    {
    for (j=0; j<n ; ++j)
      {
      fscanf(stdin, "%lf",&a[i][j]);
      }
      fscanf(stdin, "%lf",&b[i]);
    }

  for (i=0; i<n ; ++i)
    {
     for (j=0; j<n ; ++j)
       {
         printf("a%d%d=%lf ", i,j,a[i][j]);
       }
     printf("b%d=%lf \n",i,b[i]);
    }

  /* set initial x[i] */
  for (i=0; i<n ; ++i)
    {
      x[i]=0. ;
      }

    ok=0;

  /* start iteration */
 
  for (iter=1; iter<=MAX_ITER; iter++) {
    printf ( " iter=%d ok=%d \n", iter,ok);
    ok=1;
    for (i=0; i<n; i++) {
      s=b[i];
      for (j=0   ; j<i; j++) s-=a[i][j]*x[j];
      for (j=i+1 ; j<n; j++) s-=a[i][j]*x[j];
      s/=a[i][i];

      /* convergence?  ; */
      if(ok && fabs(x[i]-s)>eps)
	ok=0;

      /* new xn[i]  ; */
      xn[i]+=alp*(s-x[i]);
      printf ( " x%d=%lf \n", i,x[i]);
    }
  /* replace x[i] with xn[i]  */
    for (i=0; i<n ;++i) {
      x[i]=xn[i];
    }

    if(ok==1){
  for (i=0 ; i<n ; ++i)
      {
        printf(" ok=%d ",ok);
	printf ( " x%d=%lf \n", i,x[i]);
      }
  return 0;
    }
  }
}
