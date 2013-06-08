#include <stdio.h>
int main()
{
    double sum;
    long i,n;

    printf("# Cards  Overhang\n");
    while(scanf("%ld",&n)!=EOF){
        sum=0;
        for(i=1;i<=n;i++)
            sum+=0.5/i;
        printf("%5ld%10.3lf\n",n,sum);
    }

    return 0;   /* NZEC */
}
