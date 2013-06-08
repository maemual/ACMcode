#include <cstdio>
const int MAX_LEN = 100000;
int dp[MAX_LEN+5];
int a[MAX_LEN+5];
int main()
{
	int n;
	while (scanf("%d",&n) != EOF)
	{
		for (int i=0;i<n;i++)
		  scanf("%d",&a[i]);
		int max;
		for (int i=0;i<n;i++)
		{
			max = 0;
			for (int j =0;j<i;j++)
			{
				if (a[j] < a[i])
				{
					if (max < dp[j])
					  max = dp[j];
				}
			}
			dp[i] = max+1;
		}
		/*for (int i=0;i<n;i++)
		  printf("%d ",dp[i]);
		printf("\n");*/
		max = -1;
		for (int i=0;i<n;i++)
		{
			if (max < dp[i])
			  max = dp[i];
		}
		printf("%d\n",max);
	}
	return 0;
}
