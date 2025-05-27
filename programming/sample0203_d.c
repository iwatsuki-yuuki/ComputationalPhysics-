/* sample0203_d.c */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    int i, n;
    double h, eee, e, dif;
    FILE *outfile;

    /* 真の e = exp(1.0) を倍精度で計算 */
    eee = exp(1.0);

    /* 出力ファイル名を out_d.txt に */
    outfile = fopen("out_d.txt", "w");
    if (outfile == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    n = 20;
    for (i = 1; i <= n; i++) {
        /* 刻み幅 h = 10^(-i) */
        h = pow(10.0, -i);
        /* (1+h)^(1/h) を倍精度で計算 */
        e = pow(1.0 + h, 1.0 / h);
        /* 真値との差の絶対値 */
        dif = fabs(eee - e);

        /* h, 誤差, 近似 e を出力 */
        fprintf(outfile, "%e %e %e\n", h, dif, e);
        printf("%e %e %e\n", h, dif, e);
    }

    fclose(outfile);
    return 0;
}