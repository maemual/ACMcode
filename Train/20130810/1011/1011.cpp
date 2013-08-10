#include<cstdio>

#define MAX_LEN 100
int arr[MAX_LEN+5][MAX_LEN+5];
int main()
{
    int T;
    int n, m;
    scanf("%d", &T);
    while (T--){
       scanf("%d %d", &n, &m);
       for (int i = 0; i < n; i++)
           for (int j = 0; j < m; j++)
               scanf("%d", &arr[i][j]);
       if (arr[n-1][m-1] == 0)
           printf("Bob\n");
       else
           printf("Alice\n");
    }
    return 0;
}
