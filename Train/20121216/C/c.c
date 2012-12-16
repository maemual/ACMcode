#include <stdio.h>
#include <string.h>
#define MAX_LEN 10005
#define MAX 9999999
int n,m;
int mat[MAX_LEN][MAX_LEN];
int vis[MAX_LEN];
void bfs(int ori)
{
/*	if (ori != k)
	  mat[ori][k] = 1;
	int i;
	for (i = 1; i <= n; i++)
	{
	//	if (!vis[i] && mat[k][i] == 1)
		if (mat[k][i] == 1)
		{
		//	vis[i] = 1;
			dfs(ori,i);
			//vis[i] = 0;
		}
	}
	*/
	int que[1000000];
	int head = 0,tail = 0;
	int i;
	que[tail++] = ori;
	while (head <= tail)
	{
		for (i = 1; i <= n; i++)
		{
			if (!vis[i] && mat[que[head]][i] == 1)
			{
				vis[i] = 1;
				que[tail++] = i;
				mat[ori][i] = 1;
			}
		}
		head++;
	}
}
int main()
{
	int i,j;
	while (scanf("%d %d",&n,&m) != EOF)
	{
		memset(mat,MAX,sizeof(mat));
	//	for (i = 0; i < MAX_LEN; i++)
	//	  mat[i][i] = 0;
		int x,y;
		for (i = 0; i < m; i++)
		{
			scanf("%d %d",&x,&y);
			mat[x][y] = 1;
		}
		for (i = 1; i <= n; i++)
		{
			memset(vis,0,sizeof(0));
			vis[i] = 1;
			bfs(i);
		}
		int cnt = 0;
		for (i = 1; i <= n; i++)
		{
			int sum = 0;
			for (j = 1; j <= n; j++)
			{
				if (mat[j][i] == 1)
				  sum++;
			}
			if (sum == n-1)
			  cnt++;
		}
		printf("%d\n",cnt);
	}
}
