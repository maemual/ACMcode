#include<stdio.h>
int main()
{
    int a[4], t1, t2, min1, min2;
    while(scanf("%d%d%d%d", a, a+1, a+2, a+3) != EOF)
    {
        if(!a[0] && !a[1] && !a[2] && !a[3])
            break;
        if(a[1] < a[0])
        {
            t1 = a[1];
            a[1] = a[0];
            a[0] = t1;
        }
        if(a[3] < a[2])
        {
            t2 = a[3];
            a[3] = a[2];
            a[2] = t2;
        }
        min1 = a[2] * 100 / a[0];
        min2 = a[3] * 100 / a[1];
        if(min2 < min1)
            min1 = min2;
        if(min1 <= 0)
            min1 = 1;
        else if(min1 > 100)
            min1 = 100;
        printf("%d\%\n", min1);
    }
    return 0;
}
