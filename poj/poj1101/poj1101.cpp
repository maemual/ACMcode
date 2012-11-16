/***************************************
 *	Problem: 1101		User: maemual
 *	Memory: 492K		Time: 0MS
 *	Language: G++		Result: Accepted
 *	2012-07-19 16:54:53
 **************************************/
#include <cstdio>
#include <cstring>
const int MAX_SIZE = 75;
int map[MAX_SIZE+5][MAX_SIZE+5];
int vis[MAX_SIZE+5][MAX_SIZE+5];
int dis[MAX_SIZE+5][MAX_SIZE+5];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int row,col;
int xsta,ysta,xend,yend;
int head,tail;
struct node{
	int x,y;
}queue[1000000];
void bfs(int x,int y)
{
	int newx,newy;
	head = tail = 0;
	queue[tail].x = x;
	queue[tail++].y = y;
	vis[x][y] = true;
	while (head<=tail)
	{
		x = queue[head].x;
		y = queue[head].y;
		if (x == xend && y == yend)
		  return;
		for (int i=0;i<4;i++)
		{
			newx = x+dx[i];
			newy = y+dy[i];
			//把同一个方向上能探索到的点全部加入队列
			while ( newx>=0 && newx<row && newy>=0 && newy<col && !vis[newx][newy] && map[newx][newy]==0)
			{
				queue[tail].x = newx;
				queue[tail++].y = newy;
				vis[newx][newy] = true;
				dis[newx][newy] = dis[x][y]+1;//转折点数量为起始点加一
				newx += dx[i];
				newy += dy[i];
			}
		}
		head++;
	}
}
int main()
{
	int cas = 0;
	char ch;
	while (1)
	{
		scanf("%d %d",&col,&row);
		if (row==0 && col==0)
		  break;
		memset(map,0,sizeof(map));
		for (int i=1;i<=row;i++)
		{
			getchar();
			for (int j=1;j<=col;j++)
			{
				ch = getchar();
				if (ch == 'X')
				  map[i][j] = 1;
			}
		}
		row+=2;
		col+=2;
		int caspair = 0;
		printf("Board #%d:\n",++cas);
		while (1)
		{
			scanf("%d %d %d %d",&ysta,&xsta,&yend,&xend);
			if (xsta==0 && ysta==0 && xend==0 && yend==0)
			  break;
			memset(vis,0,sizeof(vis));
			memset(dis,0,sizeof(dis));
			map[xend][yend] = 0;
			bfs(xsta,ysta);
			if (dis[xend][yend])
			  printf("Pair %d: %d segments.\n",++caspair,dis[xend][yend]);
			else 
			  printf("Pair %d: impossible.\n",++caspair);
			map[xend][yend] = 1;
		}
		printf("\n");
	}
	return 0;
}
