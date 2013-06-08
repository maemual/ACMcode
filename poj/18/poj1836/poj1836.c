#include <stdio.h>
#define MAX_LEN 1010

double array[MAX_LEN];
int dp1[MAX_LEN],dp2[MAX_LEN];

int max(int a,int b)
{
	return a > b? a : b;
}
int min(int a,int b)
{
	return a > b?b:a;
}
int main()
{
	int n;
	int i,j;
	int temp;
	scanf("%d",&n);
	for (i = 1; i <= n; i++)
	  scanf("%lf",&array[i]);

	dp1[0] = 0;
	for (i = 1; i <= n; i++)
	{
		for (j = 0; j < i; j++)
		  if (array[i] > array[j])
			dp1[i] = max(dp1[j]+1,dp1[i]);
	}
	for (i = 1; i <= n; i++)
	  dp1[i] = max(dp1[i],dp1[i-1]);

	dp2[n+1] = 0;
	for (i = n; i >= 1; i--)
	{
		for (j = n+1; j > i; j--)
		  if (array[i] > array[j])
			dp2[i]= max(dp2[j]+1,dp2[i]);
	}
	for (i = n; i >= 1; i--)
	  dp2[i] = max(dp2[i],dp2[i+1]);

	temp = 0;
	for (i = 1; i <= n; i++)
	  temp = max(dp1[i]+dp2[i+1],temp);

	printf("%d\n",n-temp);
	return 0;
}
