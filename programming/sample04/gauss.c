/* Gauss elmination */
#include <stdio.h>
#define NN 50

int main()
{
  int i,j,k,n;
  double a[NN][NN] ;
  double b[NN],x[NN] ;
  double p,q,s;
  FILE *file;

  /* read data file */
  
  scanf("%d",&n);

  for (i=0; i<n ;++i)
    {
    for (j=0; j<n ; ++j)
      {
	scanf("%lf",&a[i][j]);
      }
    scanf("%lf",&b[i]);
    }

  for (i=0; i<n ; ++i)
    {
     for (j=0; j<n ; ++j)
       {
         printf("a%d%d=%lf ", i,j,a[i][j]);
       }
     printf("b%d=%lf \n",i,b[i]);
    }

  /* start Gauss elmination */
  
  for (k=0 ; k<n-1 ; ++k )
    {
      p=a[k][k];
      for ( j=k+1 ; j<n ; ++j )
	a[k][j]/=p;
        b[k]/=p;
      for ( i=k+1 ; i<n ; ++i )
	{
	  q=a[i][k];
	  for ( j=k+1 ; j<n ; ++j )
	    a[i][j]-=q*a[k][j];
   	    b[i]-=q*b[k];
	}
    }
  x[n-1]=b[n-1]/a[n-1][n-1];
  for ( k=n-2 ; k>=0 ; --k )
    {
      s=b[k];
      for ( j=k+1 ; j<n ; ++j )
	s-=a[k][j]*x[j];
      x[k]=s;
    }

  /* print result */
  
  for (i=0 ; i<n ; ++i)
      {
	printf ( " x%d=%lf \n", i,x[i]);
      }
  printf ( "\n" ) ;
 return 0;
}
