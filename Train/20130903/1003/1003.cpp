#include<cstdio>

#define MAX_LEN 100005
int brr[MAX_LEN];
int main()
{
    int T;
    int n;
    scanf("%d", &T);
    while (T--){
       scanf("%d", &n);
       for (int i = 0; i < n; i++)
           scanf("%d", &brr[i]);
       for (int i = 0; i < n-1; i++)
           printf("0 ");
       printf("0\n");
       for (int i = 0; i < n-1; i++){
           printf("%d ", brr[i]);
       }
       printf("%d\n", brr[n-1]);
    }

    return 0;
}
