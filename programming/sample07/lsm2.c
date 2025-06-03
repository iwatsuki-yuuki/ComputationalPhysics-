#include <stdio.h>
#include <math.h>

// least squares method for exponential fitting
void lsm(double x[], double y[], int N, double *a0, double *a1)
{
    int i;
    double a00 = 0.0, a01 = 0.0, a02 = 0.0, a11 = 0.0, a12 = 0.0;

    for (i = 0; i < N; i++) {
        double Y = log(y[i]);  // y = A * e^(B*x) → ln(y) = ln(A) + B*x
        a00 += 1.0;
        a01 += x[i];
        a02 += Y;
        a11 += x[i] * x[i];
        a12 += x[i] * Y;
    }

    *a0 = (a02 * a11 - a01 * a12) / (a00 * a11 - a01 * a01);  // ln(A)
    *a1 = (a00 * a12 - a01 * a02) / (a00 * a11 - a01 * a01);  // B

    printf("a00=%f  a01=%f  a02=%f\n", a00, a01, a02);
    printf("a11=%f  a12=%f\n", a11, a12);
}

int main()
{
    double x[100], y[100];
    int n = 0;
    double a0 = 0.0, a1 = 0.0;

    while (fscanf(stdin, "%lf %lf", &x[n], &y[n]) == 2) {
        printf("x=%lf, y=%lf\n", x[n], y[n]);
        n++;
    }

    printf("n=%d\n", n);

    lsm(x, y, n, &a0, &a1);

    printf("a0 (ln A) = %f\n", a0);
    printf("a1 (B) = %f\n", a1);
    printf("近似式: f(x) = %f * e^(%f x)\n", exp(a0), a1);

    return 0;
}