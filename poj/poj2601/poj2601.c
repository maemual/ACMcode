#include <stdio.h>

int main()
{
	int i;
	int n;
	double a,b,c[3005],sum;
	while (scanf("%d",&n) != EOF)
	{
		sum = 0;
		scanf("%lf%lf",&a,&b);
		for (i = 1; i <= n; i++)
		{
			scanf("%lf",&c[i]);
			sum += (n - i + 1) * c[i];
		}
		sum = (n * a + b - 2 * sum) / (n + 1);
		printf("%.2lf\n",sum);
	}
	return 0;
}
