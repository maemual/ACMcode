#include <stdio.h>
#define INF 100000 //无穷大

int num, a[101][101];

void Floyd(void) //Floyd算法求最短路径
{
    int i, j, k;

    //特别注意:循环的k,i,j的顺序不能改变。我测试过把顺序改为i,j,k就错了。
    for (k=1; k<=num; k++)
        for (i=1; i<=num; i++)
            for (j=1; j<=num; j++)
                if (a[i][k]+a[k][j] < a[i][j])
                    a[i][j] = a[i][k] + a[k][j];
    return;
}

int main()
{
    int i, j;
    int m, contact, time, minTime, max, person;

    while (scanf("%d", &num) && num)
    {
        for (i=1; i<=num; i++)
            for (j=1; j<=num; j++)
            {
                if (i != j) a[i][j] = INF;
                else        a[i][j] = 0;
            }
        for (i=1; i<=num; i++)
        {
            scanf("%d", &m);
            for (j=1; j<=m; j++)
            {
                scanf("%d %d", &contact, &time);
                a[i][contact] = time;
            }
        }

        Floyd(); //调用Floyd函数
        minTime = INF;
        for (i=1; i<=num; i++)
        {
            max = 0;
            for (j=1; j<=num; j++)
            {
                if (a[i][j] > max) max = a[i][j];
            }
            if (max < minTime)
            {
                minTime = max;
                person = i;
            }
        }
        if (minTime != INF)   printf("%d %d\n", person, minTime);
        else                  printf("disjoint\n");
    }
}

