#include <stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int dis,tim;
        scanf("%d%d",&dis,&tim);

        double oldfee = 11,newfee = 11;
        double oldtimeFee = tim * 0.4;
        double newtimeFee = tim * 0.625;

        if (dis <= 3)
        {
            oldfee += oldtimeFee;
            newfee += newtimeFee;
        }
        else if (dis <= 10)
        {
            oldfee += oldtimeFee + (dis - 3) * 2;
            newfee += newtimeFee + (dis - 3) * 2.5;
        }
        else if (dis > 10)
        {
            oldfee += oldtimeFee + 14 + (dis - 10) * 3;
            newfee += newtimeFee + 17.5 + (dis - 10) * 3.75;
        }
        int nf = (int) (newfee + 0.5);
        int of = (int) (oldfee + 0.5);
        printf("%d\n",nf - of);
    }
    return 0;
}
