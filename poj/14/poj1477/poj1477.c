#include <stdio.h>

int main()
{
	int n;
	int sum,avg,ans;
	int arr[55];
	int i;
	int cas = 1;
	while (1)
	{
		scanf("%d",&n);
		if (n == 0)
		  break;
		sum = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%d",&arr[i]);
			sum += arr[i];
		}
		avg = sum / n;
		ans = 0;
		for (i = 0; i < n; i++)
		{
			if (arr[i] > avg)
			{
				ans += arr[i] - avg;
			}
		}
		printf("Set #%d\nThe minimum number of moves is %d.\n\n",cas++,ans);
	}
	return 0;
}
