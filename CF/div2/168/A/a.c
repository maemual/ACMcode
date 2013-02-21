#include <stdio.h>
#include <string.h>
int main()
{
    int times[5][5];
    int state[5][5];
    int i,j;
    memset(times,0,sizeof(times));
    for (i = 1; i <= 3; i++)
        for (j = 1; j <= 3; j++)
            scanf("%d",&times[i][j]);

    int k;
    for (i = 1; i <= 3; i++)
    {
        for (j = 1; j <= 3; j++)
        {
            if ((times[i][j] + times[i-1][j] + times[i+1][j]
                + times[i][j+1] + times[i][j-1]) % 2 == 0)
                state[i][j] = 1;
            else 
                state[i][j] = 0;
        }
    }

    for (i = 1; i <=3; i++)
    {
        for (j = 1; j <= 3; j++)
            printf("%d",state[i][j]);
        printf("\n");
    }
    return 0;
}
