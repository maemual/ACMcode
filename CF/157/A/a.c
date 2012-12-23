#include <stdio.h>
#include <string.h>

int main()
{
	char map[10][10];
	int i,j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			scanf("%c",&map[i][j]);
		}
		getchar();
	}

	int flag = 0;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 7; j++)
		{
			if (map[i][j] == map[i][j+1])
			{
				flag = 1;
				break;
			}
		}
		if (flag)
		  break;
	}
	if (flag)
	  printf("NO\n");
	else
	  printf("YES\n"); 
	return 0;
}
