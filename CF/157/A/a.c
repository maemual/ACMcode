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

/*		printf("\n");
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			printf("i:%d j:%d %c",i,j,map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	*/
	int flag = 0;
	for (i = 0; i < 8; i++)
	{
		if (map[i][0] == map[i][7])
		{
//			printf("%d\n",i);
			flag = 1;
			break;
		}
		for (j = 0; j < 7; j++)
		{
			if (map[i][j] == map[i][j+1])
			{
//				printf("%c",map[i][j]);
				flag = 1;
				break;
			}
		}
//		printf("\n");
		if (flag)
		  break;
	}
	if (flag)
	  printf("NO\n");
	else
	  printf("YES\n"); 
	return 0;
}
