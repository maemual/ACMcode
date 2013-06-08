#include <cstdio>
const int MAX_LEN = 100; 
 
int a[MAX_LEN+5][MAX_LEN+5];
 
int MaxSubArray(int n, int* a)
{
    int max = 0;
    int b = 0;
    for (int i = 0; i < n; i++)
    {
        if (b > 0) 
		  b += a[i];
        else 
		  b = a[i];
        if (b > max) 
		  max = b;
    }
    return max;
}
 
int MaxSubMatrix(int m, int n)
{
    int i, j, k, sum;
    int max = 0;
    int b[MAX_LEN+5];
    for (i = 0; i < m; i++)
    {
        for (k = 0; k < n; k++)
            b[k] = 0;
 
        for (j = i; j < m; j++)
        {
            for (k = 0; k < n; k++)
                b[k] += a[j][k];
 
            sum = MaxSubArray(k, b);
            if (sum > max)
                max = sum;
        }
    }
    return max;
}
 
int main()
{
    int n;
	scanf("%d",&n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
			scanf("%d",&a[i][j]);
    printf("%d\n",MaxSubMatrix(n, n));
    return 0;
}
