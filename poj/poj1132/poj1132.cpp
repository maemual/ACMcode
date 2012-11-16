#include <cstdio>
#include <cstring>
char map[40][40];
char path[1005];
int main()
{
	int cas;
	scanf("%d",&cas);
	for (int k=1;k<=cas;k++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		scanf("%s",path);
		memset(map,'.',sizeof(map));
		int len = strlen(path);
		for (int i=0;i<len;i++)
		{
			if (path[i] == 'E')
			  map[x++][y-1] = 'X';
			else if (path[i] == 'N')
			  map[x][y++] = 'X';
			else if (path[i] == 'W')
			  map[--x][y] = 'X';
			else if (path[i] == 'S')
			  map[x-1][--y] = 'X';
		}
		printf("Bitmap #%d\n",k);
		for (int i=31;i>=0;i--)
		{
			for (int j=0;j<32;j++)
			{
				printf("%c",map[j][i]);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
