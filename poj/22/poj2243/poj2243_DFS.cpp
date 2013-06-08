#include <cstdio>
int dx[8]={1,2, 2, 1,-1,-2,-2,-1};
int dy[8]={2,1,-1,-2,-2,-1, 1, 2};
int vis[10][10];
int ans = 100;
int xbegin,ybegin,xend,yend;
void dfs(int x,int y,int k)
{

	vis[x][y] = k;
	if (x == xend && y == yend)
	{
		if (ans > k)
			ans = k;
		return;
	}
	for (int i=0;i<8;i++)
	{
		x += dx[i];
		y += dy[i];
		if (x <= 8 && y <= 8 && x >= 1 && y>=1 
			&& (vis[x][y] > k+1 || vis[x][y] == -1))
		{
			dfs(x,y,k+1);
		}
		y -= dy[i];
		x -= dx[i];
	}
}

int main()
{
	char ch;
	while ((ch = getchar()) != EOF)
	{
		xbegin = ch - 'a' + 1;
		ch = getchar();
		ybegin = ch - '0';
		
		getchar();
		
		ch = getchar();
		xend = ch - 'a' + 1;
		ch = getchar();
		yend = ch - '0';
		getchar();
		if (xbegin == xend && ybegin == yend)
		{
			printf("To get from %c%c to %c%c takes %d knight moves.\n",xbegin+'a'-1,ybegin+'0',xend+'a'-1,yend+'0',0);
			continue;
		}
		for (int i=1;i<=8;i++)
		  for (int j=1;j<=8;j++)
			vis[i][j] = -1;
		
		dfs(xbegin,ybegin,0);
		
		printf("To get from %c%c to %c%c takes %d knight moves.\n",xbegin+'a'-1,ybegin+'0',xend+'a'-1,yend+'0',vis[xend][yend]);
	}
	return 0;
}
