#include <cstdio>
int map[10][10];
bool vis[10][10];
int dx[]={-1,0,1, 0};
int dy[]={ 0,1,0,-1};
struct node
{
	int x,y;
	int from;
}queue[1000000];
node ans[50];
int main()
{
	for (int i=0;i<10;i++)
	  for (int j=0;j<10;j++)
	  {
		  map[i][j] = 1;
		  vis[i][j] = false;
	  }

	for (int i=1;i<=5;i++)
	  for (int j=1;j<=5;j++)
		scanf("%d",&map[i][j]);

	/*for (int i=1;i<=5;i++)
	{
	  for (int j=1;j<=5;j++)
		printf("%d ",map[i][j]);
	  printf("\n");
	}*/
	int head = 0;
	int tail = 0;
	queue[tail].x = 1;
	queue[tail].y = 1;
	queue[tail].from = -1;
	vis[queue[tail].x][queue[tail].y] = true;
	bool flag = false;
	while (queue[tail].x != 5 || queue[tail].y != 5)
	{
		for (int i=0;i<4;i++)
		{
			if (map[queue[head].x+dx[i]][queue[head].y+dy[i]] == 0 && !vis[queue[head].x+dx[i]][queue[head].y+dy[i]])
			{
				tail++;
				queue[tail].x = queue[head].x+dx[i];
				queue[tail].y = queue[head].y+dy[i];
				queue[tail].from = head;
				vis[queue[tail].x][queue[tail].y] = true;
			}
			if (queue[tail].x == 5 && queue[tail].y == 5)
			{
				flag = true;
				break;
			}
		}
		if (flag)
		  break;
		head++;
	}
	int k = 0;
	while (queue[tail].from != -1)
	{
		ans[k].x = queue[tail].x;
		ans[k].y = queue[tail].y;
		tail = queue[tail].from;
		k++;
	}
	ans[k].x = 1;
	ans[k].y = 1;
	for (int i=k;i>=0;i--)
	{
		printf("(%d, %d)\n",ans[i].x-1,ans[i].y-1);
	}
	return 0;
}
