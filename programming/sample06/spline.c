/* Cubic spline with Gauss-Seidel method */

#include <stdio.h>
#include <math.h>
#define NN 50
#define MAX_ITER 50
#define eps 1e-6
#define alp 1.0

int main()
{
  int i,j,k,n,nn,ndata,iter,ok;
  double a[NN][NN] ;
  double b[NN] ;
  double x[NN] ;
  double x1[NN] ;
  double y1[NN] ;
  double h[NN] ;
  double p,q,s;
  FILE *file;
  
  /* read data file */

  fscanf(stdin, "%d",&ndata);

  n=ndata-1;
  
  for (i=0; i<ndata ;++i)
    {
     fscanf(stdin, "%lf",&x1[i]);
     fscanf(stdin, "%lf",&y1[i]);
    }

  /* calculate h_i */

  for (i=1; i<ndata ;++i)
    {
      h[i]=x1[i]-x1[i-1];
      }

  /* initialize a[i][j] */

  for (i=1; i<ndata ; ++i)
    {
     for (j=1; j<ndata ; ++j)
       {
         a[i][j]=0.;
       }
    }
	   
  /* calculate a[i][j] */

  a[1][1]=(h[1]+h[2])/3. ;
  a[2][1]=h[2]/6. ;

  for (i=2; i<n-1 ; ++i)
    {
      a[i-1][i]=(h[i])/6.;
      a[i][i]=(h[i]+h[i+1])/3.;
      a[i+1][i]=(h[i+1])/6.;
    }

  a[n-2][n-1]=h[n-1]/6. ;
  a[n-1][n-1]=(h[n-1]+h[n])/3. ;

  /* calculate b[i] */

  for (i=1; i<n ; ++i)
    {
      b[i]=(y1[i+1]-y1[i])/h[i+1]-(y1[i]-y1[i-1])/h[i];
    }

  /* print matrics */

  for (i=1; i<n ; ++i)
    {
     for (j=1; j<n ; ++j)
       {
         printf("a%d%d=%lf ", i,j,a[i][j]);
       }
     printf("b%d=%lf \n",i,b[i]);
    }

  /* start Gauss-Seidel */

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
    for (i=1; i<n; i++) {
      s=b[i];
      for (j=0   ; j<i; j++) s-=a[i][j]*x[j];
      for (j=i+1 ; j<n; j++) s-=a[i][j]*x[j];
      s/=a[i][i];

      /* convergence?  ; */
      if(ok && fabs(x[i]-s)>eps)
	ok=0;
      
      /*   update  x[i] */
      x[i]+=alp*(s-x[i]);
      printf ( " x%d=%lf \n", i,x[i]);
    }
    if(ok==1){
  for (i=1 ; i<n ; ++i)
      {
        printf(" ok=%d ",ok);
	printf ( " x%d=%lf \n", i,x[i]);
      }
  return 0;
    }
  }
}
