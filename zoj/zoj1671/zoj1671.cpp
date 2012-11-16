#include <cstdio>
#include <cstring>
const int MAX_SIZE = 8;
int map[MAX_SIZE+5][MAX_SIZE+5];
int vis[MAX_SIZE+5][MAX_SIZE+5];
int dx[]={-1,0,1, 0};
int dy[]={ 0,1,0,-1};
int row,col;
int head,tail;
int sx,sy,ex,ey;
struct node{
	int x,y,step,hp;	
}queue[1000000];
void push(int x,int y,int step,int hp)
{
	queue[tail].x = x;
	queue[tail].y = y;
	queue[tail].step = step;
	queue[tail++].hp = hp;
}
int bfs()
{
	head = tail = 0;
	push(sx,sy,0,6);
	int x,y,step,hp;
	int xx,yy;
	while (head<tail)
	{
		x = queue[head].x;
		y = queue[head].y;
		step = queue[head].step;
		hp = queue[head++].hp;
		if (hp==0)
		  continue;
		for (int i=0;i<4;i++)
		{
			xx = x+dx[i];
			yy = y+dy[i];
			if (xx>=0 && xx<row && yy>=0 && yy<col && map[xx][yy] != 0
				&& hp-1>vis[xx][yy])
			{
				if (map[xx][yy] == 3)
				  return step+1;
				if (map[xx][yy] == 4){
					vis[xx][yy] = 6;
					push(xx,yy,step+1,6);
				}
				if (map[xx][yy] == 1){
					vis[xx][yy] = hp-1;
					push(xx,yy,step+1,hp-1);
				}
			}
		}
	}
	return -1;
}
int main()
{
	while (1)
	{
		scanf("%d %d",&col,&row);
		if (row==0&&col==0)
		  break;
		for (int i=0;i<row;i++)
		  for (int j=0;j<col;j++)
		  {
			  scanf("%d",&map[i][j]);
			  if (map[i][j] == 2){
				  sx = i;
				  sy = j;
			  }
		  }
		memset(vis,0,sizeof(vis));
		vis[sx][sy] = 6;
		int cnt = bfs();
		printf("%d\n",cnt);
	}
	return 0;
}
