/* Lagrange's interpolation polynominal */

#include <stdio.h>
#include <math.h>
#define NN 11

int main()
/*(xval,x,y,k,m,n)*/
{

  int k,m,n;
  double xval,x[NN],y[NN], dx;
  int i,j,ii,iimax,n_read;
  double s,ai;
  FILE *f_out;

  f_out=fopen("lag.txt", "w");       

  /* read data file */
  {
  fscanf(stdin, "%d",&n_read);
    
    n=n_read-1; m=n;k=0; iimax=100;
    
    for (i=0; i<=n ;++i)
    {
      fscanf(stdin, "%lf %lf",&x[i],&y[i]);
    }


 dx=(x[n]-x[0])/iimax ;
       
       for (ii=0 ; ii < iimax+1; ++ii)
	 {
    xval=x[0]+ii*dx;

       s=0.0;
       for (i=k ; i<=k+m ; ++i)
	 {
	   ai=1.0;
	   for ( j=k ; j<=k+m ; ++j)
	     if (i!=j )
	       ai*=(xval-x[j])/(x[i]-x[j]);
	   s+=y[i]*ai;
	 }
       fprintf(f_out, "%lf %lf \n",xval, s);
}
fclose(f_out);
  
  return(s);
     }
}
