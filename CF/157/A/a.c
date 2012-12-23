#include <stdio.h>
#include <string.h>

int main()
{
	char map[10][10];
	int i,j;
	for (i = 0; i < 8; i++)
	{
		scanf("%s",map[i]);
	}
	int flag = 0;
	for (i = 0; i < 8; i++)
	{
		if (strcmp(map[i],"WBWBWBWB") && strcmp(map[i],"BWBWBWBW"))
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n"); 
	return 0;
}
