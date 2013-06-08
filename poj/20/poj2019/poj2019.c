#include <stdio.h>
#include <string.h>
#define MAX_LEN 255
int main()
{
	int field[MAX_LEN][MAX_LEN];
	int table[MAX_LEN][MAX_LEN];
	int i,j;
	int p,q;
	int min,max;
	int n,b,k;
	scanf("%d %d %d",&n,&b,&k);
	for (i = 1; i <= n; i++)
	  for (j = 1; j <= n; j++)
		scanf("%d",&field[i][j]);

	memset(table,0,sizeof(table));
	for (i = 1; i <= n - b + 1; i++)
	{
		for (j = 1; j <= n - b + 1; j++)
		{
			max = -1;min = 999999999;
			for (p = i; p < i+b; p++)
			{
				for (q = j; q < j+b; q++)
				{
					if (field[p][q] > max)
					  max = field[p][q];
					if (field[p][q] < min)
					  min = field[p][q];
				}
			}
			table[i][j] = max - min;
		}
	}
	int x,y;
	for (i = 0; i < k; i++)
	{
		scanf("%d %d",&x,&y);
		printf("%d\n",table[x][y]);
	}
	return 0;
}
