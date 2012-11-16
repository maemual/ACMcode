#include <cstdio>
int main()
{
    int n=0,m=0,p=0,c=0;
    while(scanf("%d%d%d%d",&n,&m,&p,&c)!=EOF && n!=0 && m!=0 && p!=0 && c!=0)
    {
        printf("%d\n",p-m+n);
    }
    return 0;
}
