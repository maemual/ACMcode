#include <cstdio>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <climits>
const int MAX_LEN = 105;
int cost[MAX_LEN][MAX_LEN];
int dis[MAX_LEN];
bool found[MAX_LEN];
int n;
int choose()
{
	int min = INT_MAX;
	int minpos = -1;
	for (int i=0; i < n; i++){
		if (dis[i] < min && !found[i]){
			min = dis[i];
			minpos = i;
		}
	}
	return minpos;
}
void dijkstra(int v)
{
	for (int i=0; i < n; i++)
	{
		found[i] = false;
		dis[i] = cost[v][i];
	}
	found[v] = true;
	dis[v] = 0;
	for (int i=0; i < n; i++)
	{
		int u = choose();
		found[u] = true;
		for (int w = 1; w < n; w++)
		{
			if (!found[w])
			{
				if (dis[u] + cost[u][w] < dis[w])
					dis[w] = dis[u] + cost[u][w];
			}
		}
	}
}
int main()
{
	scanf("%d",&n);
	char s[MAX_LEN];
	memset(cost,0,sizeof(cost));
	for (int i=1;i<n;i++)
	{
		for (int j=0;j<i;j++)
		{
			scanf("%s",s);
			if (s[0] == 'x')
			  cost[i][j] =cost[j][i]= 0x3fffffff;
			else
			  cost[i][j] = cost[j][i] = atoi(s); 
		}
	}
	dijkstra(0);
	int max = 0;
	for (int i=1;i<n;i++)
	{
		if (max < dis[i])
		  max = dis[i];
	}
	printf("%d\n",max);
	return 0;
}
