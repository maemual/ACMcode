#include <cstdio>
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
const int MAX_LEN = 1000;
int map[MAX_LEN+5][MAX_LEN+5];
bool vis[MAX_LEN+5][MAX_LEN+5];
int len[MAX_LEN+5][MAX_LEN+5];
int r,c;
int dp(int x,int y)
{

	if (len[x][y] > 0)
		return len[x][y];

	int max = 0;
	int cnt = 0;
	for (int i=0;i<4;i++)
	{
		if (x+dx[i]>=0 && x+dx[i]<=r-1 && y+dy[i]>=0 && y+dy[i]<=c-1)
		{
			if (map[x+dx[i]][y+dy[i]] == '*' && !vis[x+dx[i]][y+dy[i]])
			{
				vis[x+dx[i]][y+dy[i]] = true;
				cnt = dp(x+dx[i],y+dy[i]);
				vis[x+dx[i]][y+dy[i]] = false;
				if (max < cnt)
					max = cnt;
			}
		}
	}
	len[x][y] = max + 1;
	return len[x][y];
}
int main()
{
	scanf("%d%d\n",&c,&r);
	for (int i=0;i<r;i++)
	{
		for (int j=0;j<c;j++)
		{
			scanf("%c",&map[i][j]);
			vis[i][j] = false;
			len[i][j] = 0;
		}
		getchar();
	}
	for (int i=0;i<r;i++)
	{
		for (int j=0;j<c;j++)
		{
			if (map[i][j] == '*')
			{
				vis[i][j] = true;;
				dp(i,j);
				vis[i][j] = false;
			}
		}
	}
	int max = 0;
	for (int i=0;i<r;i++)
	{
		for (int j=0;j<c;j++)
		{
			if (max < len[i][j])
			{
				max = len[i][j];
			}
		}
	}
	printf("%d\n",max);
	return 0;
}
