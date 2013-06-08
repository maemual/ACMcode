#include <stdio.h>
const int M = 10000;

struct Matrix 
{
    int v[3][3];
}m;

Matrix mtMul(Matrix A, Matrix B)     //  求矩阵 A * B
{
    Matrix C;
    C.v[0][0] = (A.v[0][0]*B.v[0][0] + A.v[0][1]*B.v[1][0]) % M;
    C.v[0][1] = (A.v[0][0]*B.v[0][1] + A.v[0][1]*B.v[1][1]) % M;
    C.v[1][0] = (A.v[1][0]*B.v[0][0] + A.v[1][1]*B.v[1][0]) % M;
    C.v[1][1] = (A.v[1][0]*B.v[0][1] + A.v[1][1]*B.v[1][1]) % M;
    return C;
}

Matrix mtPow(Matrix A, int k)        //  求矩阵 A ^ k
{
    if(k == 1) return A;
    A = mtPow(A, k / 2);
    if(k % 2 == 0) {
        return mtMul(A, A);
    } else {
        return mtMul(mtMul(A, A), m);
    }
}

int main()
{
    int n;
    m.v[0][0] = 0; m.v[0][1] = 1;
    m.v[1][0] = 1; m.v[1][1] = 1;
    while(scanf("%d", &n) && n != -1)
    {
        if(n == 0) {
            printf("0\n");
            continue;
        }
        Matrix A = mtPow(m, n);
        printf("%d\n", A.v[0][1]);
    }
    return 0;
}
