#include <cstdio>
#include <climits>
const int MAX_LEN = 100000;
int a[MAX_LEN+5];
int dp1[MAX_LEN+5];
int dp2[MAX_LEN+5];

int main()
{
	int n;
	while (1)
	{
		scanf("%d",&n);
		if (n == 0)
		  break;
		for (int i=0;i<n;i++)
		  scanf("%d",&a[i]);
		int maxSum=INT_MIN,thisSum=0;
		for (int i=0;i<n;i++)
		{
			thisSum += a[i];
			if (thisSum > maxSum)
			  maxSum = thisSum;
			if (thisSum < 0)
			  thisSum = 0;
			dp1[i] = maxSum;
		}

/*		for (int i=0;i<n;i++)
		  printf("%d ",dp1[i]);
		printf("\n");
*/
		maxSum=INT_MIN;
		thisSum = 0;
		for (int i=n-1;i>=0;i--)
		{
			thisSum += a[i];
			if (thisSum > maxSum)
			  maxSum = thisSum;
			if (thisSum < 0)
			  thisSum = 0;
			dp2[i] = maxSum;
		}

/*		for (int i=0;i<n;i++)
		  printf("%d ",dp2[i]);
		printf("\n");
*/
		int ans = INT_MIN;
		for (int i=0;i<n-1;i++)
		{
			if (ans < dp1[i]+dp2[i+1])
			  ans = dp1[i]+dp2[i+1];
		}
		printf("%d\n",ans);
	}
	return 0;
}
