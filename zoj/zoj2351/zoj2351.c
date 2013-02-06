#include <stdio.h>
#include <math.h>

int main()
{
	int n,m;
	double ka,acid,res,temp;
	int test;
	int i;
	scanf("%d",&test);
	for (i = 0; i < test; i++)
	{
		if (i)
		  printf("\n");
		while (1)
		{
			scanf("%lf %lf %d %d",&ka,&acid,&m,&n);
			if (ka == 0 && acid == 0 && m == 0 && n == 0)
			  break;
			temp = (-ka + (double)sqrt(ka*ka+4*n*acid*ka*m)) / (2*n);
			res = -log10(temp);
			printf("%.3lf\n",res);
		}
	}
	return 0;
}
