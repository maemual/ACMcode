#include <stdio.h>
#include <math.h>
int main()
{
    int t,num,m,res,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&num,&m);
        res = 0 ;
        n = (int)sqrt((double)m)*2;
        for(int i=2;i<=n;i++)
        {
            if(m*2%i==0 && m*2/i+1-i>0 && (m*2/i+1-i)%2==0 )
            {
                res++;
            }
        }
        printf("%d %d\n",num,res);
    }
    return 0;
}
