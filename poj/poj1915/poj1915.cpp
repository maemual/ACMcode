/***************************************
 *	Problem: 1915		User: maemual
 *	Memory: 1540K		Time: 63MS
 *	Language: G++		Result: Accepted
 *	2012-07-19 10:30:30
 ***************************************/
#include <cstdio>
#include <cstring>
#include <climits>
const int MAX_SIZE = 300;
int dx[]={1,2,2,1,-1,-2,-2,-1};
int dy[]={2,1,-1,-2,-2,-1,1,2};
bool vis[MAX_SIZE+5][MAX_SIZE+5];
int xbegin,ybegin,xend,yend;
int size;
int head,tail;
struct node
{
	int x,y,step;
}queue[1000000];
void push(int x,int y,int step)
{
	queue[tail].x = x;
	queue[tail].y = y;
	queue[tail++].step = step;
}
int bfs()
{
	int x,y,step;
	while (head<=tail)
	{
		x = queue[head].x;
		y = queue[head].y;
		step = queue[head].step;
		if (x==xend&&y==yend)
		  return step;
		for (int i=0;i<8;i++)
		{
			if (x+dx[i]<size && x+dx[i]>=0 && y+dy[i]<size && y+dy[i]>=0 
				&& !vis[x+dx[i]][y+dy[i]])
			{
				if (x+dx[i] == xend && y+dy[i] == yend)
				  return step+1;
				push(x+dx[i],y+dy[i],step+1);
				vis[x+dx[i]][y+dy[i]] = true;
			}
		}
		head++;
	}
}
int main()
{
	int cas;
	scanf("%d",&cas);
	while (cas--)
	{
		scanf("%d",&size);
		scanf("%d%d%d%d",&xbegin,&ybegin,&xend,&yend);
		if (xbegin == xend && xend == yend)
		{
			printf("%d\n",0);
			continue;
		}
		memset(vis,0,sizeof(vis));
		head = tail = 0;
		push(xbegin,ybegin,0);
		printf("%d\n",bfs());
	}
	return 0;
}
