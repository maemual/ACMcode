#include <cstdio>
#include <cstring>
int dx[]={1,2, 2, 1,-1,-2,-2,-1};
int dy[]={2,1,-1,-2,-2,-1, 1, 2};
bool vis[10][10];
int xbegin,ybegin,xend,yend;
int head,tail;
struct node{
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
	head = 0;
	tail = 0;
	push(xbegin,ybegin,0);
	vis[xbegin][ybegin] = true;
	int x,y,step;
	while (head <= tail)
	{
		x = queue[head].x;
		y = queue[head].y;
		step = queue[head].step;
		if (x==xend && y==yend)
		  return step;
		for (int i=0;i<8;i++)
		{
			if (x+dx[i]<=8 && y+dy[i]<=8 && x+dx[i]>=1 && y+dy[i]>=1
					&& !vis[x+dx[i]][y+dy[i]])
			{
				vis[x+dx[i]][y+dy[i]] = true;
				push(x+dx[i],y+dy[i],step+1);
			}
		}
		head++;
	}
	return -1;
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
		memset(vis,0,sizeof(vis));
		int cnt = bfs();

		printf("To get from %c%c to %c%c takes %d knight moves.\n",xbegin+'a'-1,ybegin+'0',xend+'a'-1,yend+'0',cnt);
	}
	return 0;
}
