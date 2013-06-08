/*
 *	Problem: 2251		User: maemual
 *	Memory: 1244K		Time: 32MS
 *	Language: G++		Result: Accepted
 *	2012-07-22 17:01:13
 */
#include <iostream>
#include <cstring>
using namespace std;
const int MAX_SIZE = 30;

char map[MAX_SIZE+5][MAX_SIZE+5][MAX_SIZE+5];
bool vis[MAX_SIZE+5][MAX_SIZE+5][MAX_SIZE+5];
int dx[]={ 0, 0, 1, 0, 0,-1};
int dy[]={ 0,-1, 0, 0, 1, 0};
int dz[]={-1, 0,-0, 1, 0, 0};
int lev,row,col;
int head,tail;
int sx,sy,sz,ex,ey,ez;
struct node{
	int x,y,z,step;
}queue[1000000];
void init()
{
	memset(vis,0,sizeof(vis));
	for (int i=0;i<lev;i++)
	{
		for (int j=0;j<row;j++)
		{
			for (int k=0;k<col;k++)
			{
				cin >> map[i][j][k];
				if (map[i][j][k] == 'S'){
					sx = i;
					sy = j;
					sz = k;
				}else if (map[i][j][k] == 'E'){
					ex = i;
					ey = j;
					ez = k;
				}
			}
		}
	}
}
void push(int x,int y,int z,int step)
{
	queue[tail].x = x;
	queue[tail].y = y;
	queue[tail].z = z;
	queue[tail++].step = step;
}
int bfs()
{
	int x,y,z,step;
	int xx,yy,zz,ss;
	head = tail = 0;
	push(sx,sy,sz,0);
	vis[sx][sy][sz] = true;
	while (head<=tail)
	{
		x = queue[head].x;
		y = queue[head].y;
		z = queue[head].z;
		step = queue[head].step;
		if (x==ex && y==ey && z==ez)
		  return step;
		
		for (int i=0;i<6;i++)
		{
			xx = x+dx[i];
			yy = y+dy[i];
			zz = z+dz[i];
			if (xx>=0 && xx<lev && yy>=0 && yy<row && zz>=0 && zz<col
				&& !vis[xx][yy][zz] && map[xx][yy][zz] != '#')
			{
				vis[xx][yy][zz] = true;
				push(xx,yy,zz,step+1);
			}
		}
		head++;
	}
	return -1;
}
int main()
{
	while (1)
	{
		cin >> lev >> row >> col;
		if (lev == 0&& row==0 && col==0)
		  break;
		init();
		int cnt = bfs();
		if (cnt == -1)
		  cout << "Trapped!" << endl;
		else 
		  cout << "Escaped in " << cnt << " minute(s)." << endl;
	}
	return 0;
}
