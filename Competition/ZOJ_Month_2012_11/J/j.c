#include <stdio.h>
#include <string.h>

#define MAX_LEN 20
struct node
{
	int step;
	int state[MAX_LEN+5];
}que[1000000];
int n,m;
int nail[10],nail_r[10];
int vis[1024];
int pow(int k)
{
	int sum = 1;
	int i;
	for (i = 0; i < k; i++)
	  sum *= 2;
	return sum;
}
int hash(int a[])
{
	int i;
	int sum = 0;
	for (i = m-1; i >=0; i--)
		sum += a[m-i-1]*pow(i);
	return sum;
}
int bfs()
{
	memset(vis,0,sizeof(vis));
	vis[hash(que[0].state)] = 1;
	int head = 0;
	int tail = 1;
	int i,j;
	while (head <= tail)
	{
		int s = que[head].step;
		int sta[20];
		for (i = 0; i < m; i++)
		  sta[i] = que[head].state[i];
		
		if (hash(sta) == 0)
		{
			return s;
		}
		if (n>m)
		{
			for (i = 0; i <= n-m; i++)
			{
				int temp[20];
				for (j = 0; j < m; j++)
				  temp[j] = sta[j];
				int k = 0;
				for (j = i; j < n; j++)
				  temp[k++] ^= nail[j];
				if (!vis[hash(temp)])
				{
					vis[hash(temp)] = 1;
					que[tail].step = s+1;
					for (j = 0; j < m; j++)
					  que[tail].state[j] = temp[j];
					tail++;
				}
			}
			for (i = 0; i <= n-m; i++)
			{
				int temp[20];
				for (j = 0; j < m; j++)
				  temp[j] = sta[j];
				int k = 0;
				for (j = 0; j < n; j++)
				  temp[k++] ^= nail_r[j];
				if (!vis[hash(temp)])
				{
					vis[hash(temp)] = 1;
					que[tail].step = s+1;
					for (j = 0; j < m; j++)
					  que[tail].state[j] = temp[j];
					tail++;
				}
			}
		}
		else 
		{
			for (i = 0; i < m; i++)
			{
				int temp[20];
				for (j = 0; j < m; j++)
				  temp[j] = sta[j];
				int k = 0;
				for (j = i; j < m; j++)
				  temp[j] ^= nail[k];
				if (!vis[hash(temp)])
				{
					vis[hash(temp)] = 1;
					que[tail].step = s+1;
					for (j = 0; j < m; j++)
					  que[tail].state[j] = temp[j];
					tail++;
				}
			}
			for (i = 0; i < m; i++)
			{
				int temp[20];
				for (j = 0; j < m; j++)
				  temp[j] = sta[j];
				int k = 0;
				for (j = i; j < m; j++)
				  temp[j] ^= nail_r[k++];
				if (!vis[hash(temp)])
				{
					vis[hash(temp)] = 1;
					que[tail].step = s+1;
					for (j = 0; j < m; j++)
					  que[tail].state[j] = temp[j];
					tail++;
				}
			}
		}
		head++;
	}
	return 0;
}
int main()
{
	int i,j;
	while (scanf("%d",&n) != EOF)
	{
		getchar();
		int flag = 0;
		for (i = 0; i < n; i++)
		{
			char ch = getchar();
			if (ch == '*')
			{
			  nail[i] = 1;
			  flag = 1;
			}else
			  nail[i] = 0;
		}

		scanf("%d",&m);

		if (!flag)
		{
			printf("-1\n");
			continue;
		}

		for (i = n-1; i >= 0; i--)
		  nail_r[n-i-1] = nail[i];

		memset(que,0,sizeof(que));
		for (i = 0; i < m; i++)
		  que[0].state[i] = 1;
		que[0].step = 0;
		int cnt = bfs();
		printf("%d\n",cnt);
	}
	return 0;
}
