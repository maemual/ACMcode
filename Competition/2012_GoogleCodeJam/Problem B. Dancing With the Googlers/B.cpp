#include <stdio.h>
#include <string.h>
int main()
{
    freopen("B-large.in","r",stdin);
	freopen("out1.out","w",stdout);
    int t;
    scanf("%d",&t);
    for (int k=1;k<=t;++k)
    {
        int n,s,p;
        int a[100];
        int b[100];
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        scanf("%d%d%d",&n,&s,&p);
        for (int i=0;i<n;++i)
            scanf("%d",&a[i]);

        for (int i=0;i<n;++i)
        {
            if (a[i]>=28)
            {
                a[i] = 10;
            }else if (a[i]==0)
            {
                a[i] = 0;
            }
            else if (a[i] % 3 == 0)
            {
                a[i] = a[i]/3;
                b[i] = 1;
            }
            else if (a[i] % 3 == 1)
            {
                a[i] = a[i]/3 +1;
            }
            else if (a[i] % 3 == 2)
            {
                a[i] = a[i]/3 +1;
                b[i] = 1;
            }
        }
        int count=0;
        for (int i=0;i<n;++i)
        {
            if (a[i]>=p)
            {
                count++;
            }
            else if (b[i] == 1 && s>0)
            {
                a[i]++;
                if (a[i]>=p)
                {
                    count++;
                    s--;
                }
            }
        }
        printf("Case #%d: %d\n",k,count);
    }
    return 0;
}
