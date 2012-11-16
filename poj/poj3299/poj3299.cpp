#include <cstdio>
#include <cmath>
int main()
{
	char ch1,ch2;
	double temp = 0,dewp = 0,humi = 0;
	while (1)
	{
		scanf("%c",&ch1);
		if (ch1 == 'E')
		  break;
		if (ch1 == 'T')
		  scanf("%lf",&temp);
		else if (ch1 == 'D')
		  scanf("%lf",&dewp);
		else if (ch1 == 'H')
		  scanf("%lf",&humi);

		getchar();
		scanf("%c",&ch2);
		if (ch2 == 'T')
		  scanf("%lf",&temp);
		else if (ch2 == 'D')
		  scanf("%lf",&dewp);
		else if (ch2 == 'H')
		  scanf("%lf",&humi);

		getchar();

		if (ch1 == 'T' && ch2 == 'D' || ch1 == 'D' && ch2 == 'T')
		{
			humi=temp + 0.5555*(6.11*exp(5417.7530*(1/273.16-1/(dewp+273.16)))-10.0);
		}else if (ch1 == 'H' && ch2 == 'D' || ch1 == 'D' && ch2 == 'H')
		{
			temp=humi - 0.5555*(6.11*exp(5417.7530*(1/273.16-1/(dewp+273.16)))-10.0);
		}else if (ch1 == 'T' && ch2 == 'H' || ch1 == 'H' && ch2 == 'T')
		{
			dewp=1/(1/273.16-log(((humi-temp)/0.5555+10.0)/6.11)/5417.7530)-273.16;
		}
		printf("T %.1f D %.1f H %.1f\n",temp,dewp,humi);
	}
	return 0;
}
