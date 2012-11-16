#include <cstdio>
#include <cstring>
const int MAX_LEN = 7;
int map[MAX_LEN+5][MAX_LEN+5];
bool vis[MAX_LEN+5][MAX_LEN+5];
int dx[]={-1,0,1, 0};
int dy[]={ 0,1,0,-1};
int row,col;
bool flag;
bool check()
{
	for (int i=0;i<row;i++)
	{
		for (int j=0;j<col;j++)
		  if (!vis[i][j])
			return false;
	}
	return true;
}
void dfs(int x,int y)
{
	vis[x][y] = true;
	if (check())
	{
		flag = true;
		return;
	}
	for (int i=0;i<4;i++)
	{
		if (x+dx[i]>=0&&x+dx[i]<row&&y+dy[i]>=0&&y+dy[i]<col
			&& !vis[x+dx[i]][y+dy[i]] && map[x+dx[i]][y+dy[i]]==0)
		{
			dfs(x+dx[i],y+dy[i]);
		}
	}
	if (!flag)
	{
		vis[x][y] = false;
	}
}
int main()
{
	while (1)
	{
		char ch;
		scanf("%d %d",&row,&col);
		if (row==0 && col==0)
		  break;
		memset(vis,0,sizeof(vis));
		for (int i=0;i<row;i++)
		{
			getchar();
			for (int j=0;j<col;j++)
			{
				scanf("%c",&ch);
				if (ch == '.')
				  map[i][j] = 0;
				else {
				  map[i][j] = 1;
				  vis[i][j] = true;
				}
			}
		}
		flag = false;
		dfs(0,0);
		if (flag)
		  printf("YES\n");
		else
		  printf("NO\n");
	}
	return 0;
}
