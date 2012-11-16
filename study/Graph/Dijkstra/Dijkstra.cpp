#include <cstdio>
#include <climits>
const int MAX_LEN = 100;
int cost[MAX_LEN][MAX_LEN];
int dis[MAX_LEN];
bool found[MAX_LEN];
int n;
int choose(int dis[],int n,bool found[])
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
	for (int i=0; i < n-2; i++)
	{
		int u = choose(dis,n,found);
		found[u] = true;
		for (int w = 0; w < n; w++)
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
	for (int i=0;i<n;i++)
	  for (int j=0;j<n;j++)
		scanf("%d",&cost[i][j]);
	for (int i=0;i<n;i++)
	{
		dijkstra(i);
		for (int i=0;i<n;i++)
		  printf("%5d",dis[i]);
		printf("\n");
	}
}
