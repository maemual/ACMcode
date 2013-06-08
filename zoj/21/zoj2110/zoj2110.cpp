/*
 * 560MS
 */
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
const int MAX_SIZE = 7;
char map[MAX_SIZE+5][MAX_SIZE+5];
bool vis[MAX_SIZE+5][MAX_SIZE+5];
int dx[]={-1,0,1, 0};
int dy[]={ 0,1,0,-1};
int xsta,ysta,xend,yend;
int row,col,t;
bool flag;
void init()
{
	for (int i=0;i<row;i++)
		for(int j=0;j<col;j++)
		{
			cin>>map[i][j];
			if(map[i][j]=='S')
			{
				xsta=i;
				ysta=j;
			}
			else if(map[i][j]=='D')
			{
				xend=i;
				yend=j;
			}
			vis[i][j]=false;
		}
}
void dfs(int x,int y,int k)
{
	if (flag)
	  return;
	if (k==t&&x==xend&&y==yend)
	{
		flag = true;
		return ;
	}
	int dis = abs(x-xend)+abs(y-yend);
	if ( dis > (t-k))
	  return ;
	if ( dis%2 != (t-k)%2)
	  return ;
	int xx,yy;
	for (int i=0;i<4;i++)
	{
		xx = x+dx[i];
		yy = y+dy[i];
		if (xx>=0&&xx<row&&yy>=0&&yy<col && !vis[xx][yy] && map[xx][yy]!='X')
		{
			vis[xx][yy] = true;
			dfs(xx,yy,k+1);
			vis[xx][yy] = false;
		}
	}
}
int main()
{
	while (1)
	{
		scanf("%d %d %d",&row,&col,&t);
		if (row==0&&col==0&&t==0)
		  break;
		init();
		flag = false;
		vis[xsta][ysta] = true;
		dfs(xsta,ysta,0);
		if (flag)
		  printf("YES\n");
		else
		  printf("NO\n");
	}
	return 0;
}
