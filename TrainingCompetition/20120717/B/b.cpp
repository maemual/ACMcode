#include <cstdio>
#include <cstring>
const int MAX_LEN = 500;
int dx[]={-1,0, 0,1};
int dy[]={ 0,1,-1,0};
int map[MAX_LEN+5][MAX_LEN+5];
bool vis[MAX_LEN+5][MAX_LEN+5];
int sta[MAX_LEN+5][MAX_LEN+5];
int row,col,d;
int begin,end;
bool dfs(int x,int y)
{
	if (sta[x][y] )
	  return true;
	if (map[x][y]>map[begin][end])
	  return true;
	vis[x][y] = true;
	for (int i=0;i<4;i++)
	{
		if (!vis[x+dx[i]][y+dy[i]] && map[x+dx[i]][y+dy[i]] != -1 && map[x+dx[i]][y+dy[i]]>map[begin][end]-d)
		{
			if (dfs(x+dx[i],y+dy[i]))
			{
				vis[x][y] = false;
				return true;
			}
		}
	}
	vis[x][y] = false;
	return false;
}
int main()
{
	int cas;
	scanf("%d",&cas);
	while (cas--)
	{
		scanf("%d%d%d",&row,&col,&d);
		memset(map,-1,sizeof(map));
		memset(vis,0,sizeof(vis));
		memset(sta,0,sizeof(sta));
		for (int i=1;i<=row;i++)
		  for (int j=1;j<=col;j++)
			scanf("%d",&map[i][j]);

		for (int i=1;i<=row;i++)
		{
			for (int j=1;j<=col;j++)
			{
				begin = i;
				end = j;
				if (dfs(i,j))
				  sta[i][j] = true;
			}
		}
		int ans=0;
		for (int i=1;i<=row;i++)
		{
			for (int j=1;j<=col;j++)
			{
				if (sta[i][j])
				  ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
