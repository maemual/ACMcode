#include <cstdio>
#include <climits>
int main()
{
	int x,n;
	while (1)
	{
		scanf("%d",&n);
		if (n == 0)
		  break;
		int sum = 0;
		int max = INT_MIN;
		int min = INT_MAX;
		for (int i=0;i<n;i++)
		{
			scanf("%d",&x);
			sum += x;
			if (max < x)
			  max = x;
			if (min > x)
			  min = x;
		}
		printf("%d\n",(sum-max-min)/(n-2));
	}
	return 0;
}
