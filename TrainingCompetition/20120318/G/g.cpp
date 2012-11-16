#include <stdio.h>

int main()
{
    int n,m;
    int c,d;
    int a[50010];
    while (scanf("%d%d",&n,&m) != EOF)
    {
        for (int i = 1;i <=n;++i)
            a[i] = 0;
        for (int i = 0;i < m;++i)
        {
            scanf("%d%d",&c,&d);
            if (c == 1)
            {
                a[d] = 1;
            }else if (c == 2){
                int count1 = 0;
                int count2 = 0;
                if (a[d] == 1)
                {
                    printf("0\n");
                }
                else
                {
                    for (int j = d;j <= n;++j)
                    {
                        if (a[j] == 0)
                        ++count1;
                        else break;
                    }
                    for (int j = d;j >=1;--j)
                    {
                        if (a[j] == 0)
                            ++count2;
                        else break;
                    }
                    printf("%d\n",count1+count2-1);
                }
            }else if (c == 3){
                a[d] = 0;
            }
        }
    }

    return 0;
}
