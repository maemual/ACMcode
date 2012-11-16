#include <cstdio>
#include <cstring>
const int MAX_LEN = 1000;
char map[MAX_LEN+5][MAX_LEN+5];
int vis[MAX_LEN+5][MAX_LEN+5];
int row,col,max,sum;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
void dfs(int x,int y)
{
	for (int i=0;i<4;i++)
	{
		x += dx[i];
		y += dy[i];
		if (x>=0 && x<=row-1 && y>=0 && y<=col-1 && map[x][y]== '*'&& !vis[x][y])
		{
			vis[x][y] = true;
			sum++;
			dfs(x,y);	
		}
		y -= dy[i];
		x -= dx[i];
	}
}
int main()
{
	scanf("%d%d\n",&col,&row);
	for (int i=0;i<row;i++)
	{
		for (int j=0;j<col;j++)
		  scanf("%c",&map[i][j]);
		getchar();
	}
	memset(vis,0,sizeof(vis));
	max = -1;
	for (int i=0;i<row;i++)
	{
		for (int j=0;j<col;j++)
		{
			if (map[i][j] == '*')
			{
				sum = 0;
				dfs(i,j);
				if (max < sum)
				  max = sum;
			}
		}
	}
	printf("%d\n",max);
	return 0;
}
