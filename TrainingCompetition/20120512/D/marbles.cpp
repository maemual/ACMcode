#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        int c1,n1,c2,n2;
        scanf("%d%d",&c1,&n1);
        scanf("%d%d",&c2,&n2);
        int max=2100000000;
        int num1=0,num2=0;
        for (int i=0;i<= n/n1;++i)
        {
            for (int j=0;j<= n/n2;++j)
            {
                if (n1*i+n2*j == n)
                {
                    if (c1*i+c2*j < max)
                    {
                        num1 = i;
                        num2 = j;
                        max = c1*i+c2*j;
                    }
                }
            }
        }
        if (max == 2100000000)
        {
            printf("failed\n");
        }else printf("%d %d\n",num1,num2);
    }
    return 0;
}
