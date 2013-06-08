#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sum;
char map[1001][81];

void dfs(int i, int j)
{
	if (map[i][j] == '.') return;
	else if (map[i][j] == '*')
	{
		sum++;
		map[i][j] = '.';
		dfs(i, j + 1);
		dfs(i, j - 1);
		dfs(i + 1, j);
		dfs(i - 1, j);
	}
}

int main()
{
	int i,j,w,h,max;
	scanf("%d%d", &h, &w);
	for (i = 1; i <= w; i++)
	{
		getchar();
		for (j = 1; j <= h; j++)
		{
			scanf("%c", &map[i][j]);
		}
	}
	max = 0;
	for (i = 1; i <= w; i++)
	{
		for (j = 1; j <= h; j++)
		{
			if (map[i][j] == '*')
			{
				sum = 0;
				dfs(i, j);
				if(sum > max) max = sum;
			}
		}
	}
	printf("%d\n", max);
	//system("pause");
	return 0;
}
