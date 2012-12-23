#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int a,m;
        scanf("%d%d",&a,&m);
        int mt = a;
        int nt = m;
        int temp;
        if (mt < nt)
        {
            temp = mt;
            mt = nt;
            nt = temp;
        }
        temp = 0;
        while (nt != 0)
        {
            temp = nt;
            nt = mt % nt;
            mt = temp;
        }
        if (mt != 1)
        {
            printf("Not Exist\n");
        }
        else
        {
            for (int x = 1;;x++)
            {
                if ((a*x-1) % m == 0)
                {
                    printf("%d\n",x);
                    break;
                }
            }
        }
    }
    return 0;
}
