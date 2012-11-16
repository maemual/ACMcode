#include <cstdio>
#include <climits>
const int MAX_LEN = 100;
int dp[MAX_LEN+5][MAX_LEN+5];
int a[MAX_LEN+5][MAX_LEN+5];
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int row,col;
	scanf("%d%d",&row,&col);
	for (int i=1;i<=row;i++)
		for (int j=1;j<=col;j++)
			scanf("%d",&a[i][j]);
	dp[1][1] = a[1][1];
	for (int i=2;i<=row;i++)
	  dp[1][i] = max(dp[1][i-1],a[1][i]);

	for (int i=2;i<=row;i++)
	{
		dp[i][i] = dp[i-1][i-1] + a[i][i];
		for (int j=i+1;j<=col;j++)
		  dp[i][j] = max(dp[i][j-1],dp[i-1][j-1]+a[i][j]);
	}
	printf("%d\n",dp[row][col]);
	return 0;
}
