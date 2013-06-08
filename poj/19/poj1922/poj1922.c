#include <stdio.h>
#include <math.h>
int main()
{
	int n;
	double x,y,tmp,ans;
	int i;
	while (1)
	{
		scanf("%d",&n);
		if (n == 0)
		  break;
		ans = 999999999;
		for (i = 0; i < n; i++)
		{
			scanf("%lf%lf",&x,&y);
			if (y < 0)
			  continue;
			tmp = 4500.0 * 3.6 / x + y;
			if (tmp < ans)
			  ans = tmp;
		}
		printf("%.lf\n",ceil(ans));
	}
	return 0;
}
