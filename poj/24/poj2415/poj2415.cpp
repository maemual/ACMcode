/*
 *	Problem: 2415		User: maemual
 *	Memory: 1140K		Time: 16MS
 *	Language: G++		Result: Accepted
 *	2012-07-19 21:25:25
 */
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int MAX_LEN = 60;
char map[MAX_LEN+5][MAX_LEN+5];
bool vis[MAX_LEN+5][MAX_LEN+5][MAX_LEN+5];
int n;
struct node{
	int a,b,c;
	int step;
}cur,next;
int bfs()
{
	vis[cur.a][cur.b][cur.c] = true;
	if (cur.a==cur.b && cur.b==cur.c)
	  return 0;
	queue<node> q;
	cur.step = 0;
	q.push(cur);
	while (!q.empty())
	{
		cur = q.front();
		q.pop();
		for (int i=1;i<=n;i++)
		{
			if (map[cur.a][i]==map[cur.b][cur.c] && !vis[i][cur.b][cur.c])
			{
				if (i==cur.b && cur.b==cur.c)
				  return cur.step+1;
				vis[i][cur.b][cur.c] = true;
				next.a = i;
				next.b = cur.b;
				next.c = cur.c;
				next.step = cur.step+1;
				q.push(next);
			}
			if (map[cur.b][i]==map[cur.a][cur.c] && !vis[cur.a][i][cur.c])
			{
				if (cur.a==i && i==cur.c)
				  return cur.step+1;
				vis[cur.a][i][cur.c] = true;
				next.a = cur.a;
				next.b = i;
				next.c = cur.c;
				next.step = cur.step+1;
				q.push(next);
			}
			if (map[cur.c][i]==map[cur.a][cur.b] && !vis[cur.a][cur.b][i])
			{
				if (cur.a==cur.b && cur.b==i)
				  return cur.step+1;
				vis[cur.a][cur.b][i] = true;
				next.a = cur.a;
				next.b = cur.b;
				next.c = i;
				next.step = cur.step+1;
				q.push(next);
			}
		}
	}
	return -1;
}
int main()
{
	while (1)
	{
		scanf("%d",&n);
		if (n==0)
		  break;
		scanf("%d%d%d",&cur.a,&cur.b,&cur.c);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				cin >> map[i][j];
		memset(vis,0,sizeof(vis));
		int cnt = bfs();
		if (cnt == -1)
		  printf("impossible\n");
		else 
		  printf("%d\n",cnt);
	}
	return 0;
}
