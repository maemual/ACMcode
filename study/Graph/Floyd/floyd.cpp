#include <cstdio>
const int MAX_LEN = 100;
int cost[MAX_LEN][MAX_LEN];
int dis[MAX_LEN][MAX_LEN];
int n;
void floyd()
{
	for (int i=0;i<n;i++)
	  for (int j=0;j<n;j++)
		dis[i][j] = cost[i][j];

	for (int k=0;k<n;k++)
	  for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
		  if (cost[i][k] + cost[k][j] < cost[i][j])
			cost[i][j] = cost[i][k] + cost[k][j];
}
int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	  for (int j=0;j<n;j++)
		scanf("%d",&cost[i][j]);
	floyed();
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		  printf("%5d",cost[i][j]);
		printf("\n");
	}
}
