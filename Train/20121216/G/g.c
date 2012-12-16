#include <stdio.h>
#include <string.h>
#define MAX 9999999
int vis[100005];
int a,b;
int queue[10000000];

int bfs()
{
	int i,j;
	int head = 0;
	int tail = 0;
	queue[tail++] = a;
	int div[100005];
	int next;
	while (head <= tail)
	{
		j = 0;
		for (i = 1; i*i <= queue[head]; i++)
		{
			if (queue[head] % i == 0)
			  div[j++] = i;
		}
		int temp = j;
		for (i = 0; i < temp; i++)
		{
			div[j++] = queue[head] / div[i];
		}
		div[j++] = queue[head];
		for (i = 0; i < j; i++)
		{
			next = queue[head] + div[i];
			if (next > 100000)
			  break;
			if (vis[queue[head]] + 1 < vis[next])
			{
				vis[next] = vis[queue[head]] + 1;
				queue[tail++] = next;
				if (next == b)
				  return vis[b];
			}
		}
		head++;
	}
	return -1;
}
int main()
{
	while (scanf("%d %d",&a,&b) != EOF)
	{
		memset(vis,MAX,sizeof(vis));
		vis[a] = 0;
		if (a == b)
		  printf("0\n");
		else if (a > b)
		  printf("-1\n");
		else 
		  printf("%d\n",bfs());
	}
	return 0;
}
