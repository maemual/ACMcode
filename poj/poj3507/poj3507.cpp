#include <cstdio>
#include <climits>
int main()
{
	int n;
	int a[6];
	while (1)
	{
		int max = INT_MIN;
		int min = INT_MAX;
		int sum = 0;
		for (int i=0;i<6;i++)
		{
			scanf("%d",&a[i]);
			if (max < a[i])
				max = a[i];
			if (min > a[i])
				min = a[i];
			sum += a[i];
		}
		if (sum == 0)
			break;
		double ave = (sum - max - min) / 4.0;
		printf("%g\n",ave);
	}
	return 0;
}
