#include <stdio.h>

int main()
{
    int i,n,a,b,c,miles;
    while(1)
    {
        scanf("%d",&n);
        if (n == -1)
            break;
        scanf("%d%d",a,b);
        miles=a*b;
        c=b;
        for (i=1;i<n;i++)
        {
            scanf("%d%d",a,b);
            c=b-c;
            miles += a*c;
            c=b;
        }
        printf("%d miles\n",miles);
    }
    return 0;
}
