/*
 *未经优化，可以将空间复杂度降低
 */
#include <cstdio>
#include <cstring>
#include <ctime>
const int MAX_LEN = 1000;
int cost[MAX_LEN];
int val[MAX_LEN];
int f[MAX_LEN][MAX_LEN];
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int n,w;
	scanf("%d%d",&n,&w);
	memset(f,0,sizeof(f));
	for (int i=1;i<=n;i++)
		scanf("%d%d",&cost[i],&val[i]);
	for (int i=1;i<=n;i++)
	{
		for (int j=w;j>=cost[i];j--)
		{
			f[i][j] = max(f[i-1][j],f[i-1][j-cost[i]]+val[i]);
		}
	}
	printf("%d\n",f[n][w]);
	return 0;
}
