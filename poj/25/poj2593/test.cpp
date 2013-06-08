#include <cstdio>
int a[1000];
int dp[1000];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	  scanf("%d",&a[i]);
	int maxSum=0,thisSum=0;
	for (int i=0;i<n;i++)
	{
		thisSum += a[i];
		if (thisSum > maxSum)
		  maxSum = thisSum;
		else if (thisSum < 0)
		  thisSum = 0;
		dp[i] = maxSum;
	}
	for (int i=0;i<n;i++)
	  printf("%d ",dp[i]);
	printf("\n%d\n",maxSum);
	return 0;
}
