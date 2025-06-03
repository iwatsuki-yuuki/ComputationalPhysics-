#include <stdio.h>
#include <stdlib.h>

// least squares method

// function least squares method
void lsm(double x[],double y[], int N, double *a0, double *a1)
{
        int i;
        double a00=0. ,a01=0., a02=0., a11=0., a12=0.;
 
        for (i=0;i<N;i++) {
                a00+=1.0;
                a01+=x[i];
                a02+=y[i];
                a11+=x[i]*x[i];
                a12+=x[i]*y[i];
	}
 
        *a0 = (a02*a11-a01*a12) / (a00*a11-a01*a01);
        *a1 = (a00*a12-a01*a02) / (a00*a11-a01*a01);

	printf("a00=%f  a01=%f  a02=%f \n", a00, a01, a02);
	printf("a11=%f  a12=%f \n", a11, a12);
}

int main()
{
#define LINE_BUF_SIZE 1024

  double x[100], y[100];
  int n=0;
  double a0 = 0, a1 = 0;
  static char line[LINE_BUF_SIZE];

    // read data & define data number n

    while(fscanf(stdin, "%lf %lf",&(x[n]),&(y[n]))>1) { 
      printf("x=%lf,y=%lf\n", x[n],y[n]);
      n++;
    }
    
    printf("n=%d\n", n);
	  
 // call function least squares method
        lsm(x, y, n, &a0, &a1);
	
        printf("a0=%f\na1=%f \n \n", a0, a1);
	printf("f(x)=%f*x+%f \n", a1, a0);
        
    return 0;
}

