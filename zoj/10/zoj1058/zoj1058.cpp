#include <cstdio>
double a[6][6];
int country[11];
int main()
{
	int cas;
	int k=0;
	scanf("%d",&cas);
	while (cas--)
	{
		for (int i=1;i<=5;i++)
		  for (int j=1;j<=5;j++)
			scanf("%lf",&a[i][j]);
		int n;
		scanf("%d",&n);
		while (n)
		{
			if (n == 0)
			  break;
			for (int i=1;i<=n;i++)
			  scanf("%d",&country[i]);
			country[0] = 1;
			country[n+1] = 1;
			double money;
			scanf("%lf",&money);
			for (int i=1;i<=n+1;i++)
			{
				money = ((int)(money*a[country[i-1]][country[i]]*100+0.5))/100.0;
				//printf("%lf   ",money);
			}
			printf("%.2lf\n",money);
			scanf("%d",&n);
		}
		if (cas != 0)
		  printf("\n");
	}
	return 0;
}
