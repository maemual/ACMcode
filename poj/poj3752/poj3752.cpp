#include <cstdio>
#include <cstring>
const int MAX_LEN = 1000;
int map[MAX_LEN][MAX_LEN];
int row,col;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
bool check(int x,int y)
{
	if (x < 0 || y < 0 || x >= row || y >= col || map[x][y] != 0)
		return false;
	return true;
}
int main()
{
	while (scanf("%d%d",&row,&col) != EOF)
	{
		memset(map,0,sizeof(map));
		int x=0,y=0;
		int k=0;
		for (int i=0;i<row*col;i++)
		{
			map[x][y] = i % 26 + 'A';
			if (!check(x+dx[k],y+dy[k]))
				k = (k+1) % 4;
			x += dx[k];
			y += dy[k];
		}
		for (int i=0;i<row;i++)
		{
			for (int j=0;j<col;j++)
			{
				printf("%4c",map[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
