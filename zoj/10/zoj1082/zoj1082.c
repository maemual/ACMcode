#include <stdio.h>
#define MAX_LEN 105
#define INT_MAX 1000000
int a[MAX_LEN][MAX_LEN];
int n;
void init()
{
	int i,j;

	for (i = 0; i < MAX_LEN; i++)
	{
		for (j = 0; j < MAX_LEN; j++)
		{
			if (i == j)
			  a[i][j] = 0;
			else 
			  a[i][j] = INT_MAX;
		}
	}
}
void input()
{
	int m,p,time;
	int i,j;
	for (i = 1; i <= n; i++)
	{
		scanf("%d",&m);
		for (j = 1; j <= m; j++)
		{
			scanf("%d %d",&p,&time);
			a[i][p] = time;
		}
	}
}
void floyd()
{
	int i,j,k;
	for (k = 1; k <= n; k++)
	  for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
		  if (a[i][k] + a[k][j] < a[i][j])
			a[i][j] = a[i][k] + a[k][j];
}
int main()
{
	int i,j;
	while (1)
	{
		scanf("%d",&n);
		if (n == 0)
		  break;
		init();
		input();
		floyd();
		int pos,min = INT_MAX;
		for (i = 1; i <= n; i++)
		{
			int max = 0;
			for (j = 1; j <= n; j++)
			{
				if (a[i][j] > max)
				  max = a[i][j];
			}
			if (max < min)
			{
				min = max;
				pos = i;
			}
		}
		if (min != INT_MAX) 
		  printf("%d %d\n",pos,min);
		else 
		  printf("disjoint\n");
	}
	return 0;
}
