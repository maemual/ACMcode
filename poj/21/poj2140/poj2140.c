#include <stdio.h>

int main()
{
	int n;
	int i,j;
	int sum;
	int ans;
	while (scanf("%d",&n) != EOF)
	{
		ans = 0;
		for (i = 1; i <= n; i++)
		{
			sum = 0;
			for (j = 0; ; j++)
			{
				sum = (2*i+j)*(j+1)/2;
				if (sum > n)
				  break;
				else if (sum == n)
				  ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
