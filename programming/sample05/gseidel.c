/* Gauss-Seidel method with relaxation parameter */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NN       50
#define MAX_ITER 1000
#define EPS      1e-6

int main()
{
    int i, j, iter, n, converged;
    double a[NN][NN];
    double b[NN];
    double x[NN];
    double s;
    double alpha;
    
    /* --- 入力 --- */
    // 1 行目に n、以降に a[i][j], b[i] が data53.txt と同形式で並ぶものとする
    if (scanf("%d", &n) != 1 || n > NN) {
        fprintf(stderr, "Invalid n\n");
        return 1;
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%lf", &a[i][j]);
        }
        scanf("%lf", &b[i]);
    }
    
    /* relaxation factor を標準入力から受け取る */
    printf("Relaxation parameter α (0 < α ≤ 1)? ");
    if (scanf("%lf", &alpha) != 1 || alpha <= 0.0 || alpha > 1.0) {
        fprintf(stderr, "Invalid α; must be in (0,1]\n");
        return 1;
    }

    /* 初期解 x を 0 に初期化 */
    for (i = 0; i < n; i++) {
        x[i] = 0.0;
    }

    /* 反復 */
    for (iter = 1; iter <= MAX_ITER; iter++) {
        converged = 1;
        printf(" Iteration %d\n", iter);
        for (i = 0; i < n; i++) {
            s = b[i];
            for (j = 0; j < n; j++) {
                if (j != i) s -= a[i][j] * x[j];
            }
            s /= a[i][i];
            if (fabs(x[i] - s) > EPS) {
                converged = 0;
            }
            /* relaxation update */
            x[i] += alpha * (s - x[i]);
            printf("   x[%d] = % .8f\n", i, x[i]);
        }
        if (converged) {
            printf("Converged in %d iterations.\n", iter);
            break;
        }
    }
    if (!converged) {
        printf("Did NOT converge in %d iterations.\n", MAX_ITER);
    }

    /* 結果出力 */
    printf("\nSolution:\n");
    for (i = 0; i < n; i++) {
        printf(" x[%d] = % .8f\n", i, x[i]);
    }

    return 0;
}