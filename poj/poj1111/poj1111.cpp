#include <cstdio>
#include <cstring>
int dx[8]={1,-1,0,0,1,-1,1,-1};
int dy[8]={0,0,1,-1,1,-1,-1,1};
int row,col,xsta,ysta;
const int MAX_LEN = 25;
char map[MAX_LEN][MAX_LEN];
bool vis[MAX_LEN][MAX_LEN];
int total = 0;
void dfs(int x,int y)
{
	int newx,newy;
	vis[x][y] = true;
	for (int i=0;i<8;i++)
	{
		newx = x + dx[i];
		newy = y + dy[i];
		if (newx>0 && newx<=row && newy>0 && newy<=col)
		{
			if (map[newx][newy] == 'X' && vis[newx][newy] == false)
				dfs(newx,newy);
			else if (map[newx][newy] == '.' && (newx == x|| newy == y))
			{
				total++;
			}
		}
		else if (newx == x || newy == y)
			total++;
	}
}
int main()
{
	while (1)
	{
		scanf("%d%d%d%d",&row,&col,&xsta,&ysta);
		if (row == 0 && col == 0 && xsta == 0 && ysta == 0)
			break;
		for (int i=1;i<=row;i++)
		{
			getchar();
			for (int j=1;j<=col;j++)
			{
				scanf("%c",&map[i][j]);
			}
			
		}
		memset(vis,0,sizeof(vis));
		total = 0;
		dfs(xsta,ysta);
		printf("%d\n",total);
	}
	return 0;
}
