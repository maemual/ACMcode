#include <cstdio>
const int MAX_N = 3402;
const int MAX_M = 12880;
int dp[MAX_M+5]={0};
int w[MAX_N];
int d[MAX_N];
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int n,m;
	while (scanf("%d%d",&n,&m) != EOF)
	{
		for (int i=0;i<n;i++)
		  scanf("%d%d",&w[i],&d[i]);
		for (int i=0;i<n;i++)
			for (int j=m;j>=w[i];j--)
				dp[j] = max(dp[j],dp[j-w[i]]+d[i]);
		printf("%d\n",dp[m]);
	}
	return 0;
}
