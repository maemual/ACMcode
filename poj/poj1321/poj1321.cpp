/*
 *	Problem: 1321
 *	Memory: 388K		Time: 63MS
 *	Language: G++		Result: Accepted
 *	2012-07-12-21-40
 */
#include <cstdio>
#include <cstring>
const int MAX_SIZE = 8;
char map[MAX_SIZE+5][MAX_SIZE+5];
bool vis[MAX_SIZE+5];
int n,k,ans,sum;
void dfs(int x,int y)
{
	if (sum == k)
	{
		ans++;
		return;
	}
	vis[y] = false;
	for (int i=x+1;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			if (map[i][j] == '#' && vis[j])
			{
				sum++;
				dfs(i,j);
				sum--;
			}
		}
	}
	vis[y]=true;
}
int main()
{
	while (1)
	{
		scanf("%d %d",&n,&k);
		if (n==-1&&k==-1)
		  break;
		for (int i=0;i<n;i++)
		{
			getchar();
			for (int j=0;j<n;j++)
			{
				scanf("%c",&map[i][j]);
			}
		}
		sum = 0;
		ans = 0;
		memset(vis,1,sizeof(vis));
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
			{
				if (map[i][j] == '#')
				{
					sum = 1;
					dfs(i,j);
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
