#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    for (int ca = 1;ca <= t;++ca)
    {
        int n,k;
        int a[50001];
        scanf("%d%d",&n,&k);
        printf("Case %d:\n",ca);
        for (int i = 1;i <= n;++i)
        {
            a[i] = k;
        }
        int x;
        scanf("%d",&x);
        while (x != 0)
        {
            if (x == 1)
            {
                int i,j,c;
                scanf("%d%d%d",&i,&j,&c);
                for (int m = i;m <=j;++m)
                {
                    a[m] += c;
                }
            }
            else
            {
                int sum = 0;
                int i,j;
                scanf("%d%d",&i,&j);
                for (int m = i;m <= j;++m)
                {
                    sum += a[m];
                }
                printf("%d\n",sum);
            }
            scanf("%d",&x);
        }
    }
    return 0;
}
