#include <cstdio>
#include <cstring>
#include <climits>
int map[10][10];
int vis[10][10];
struct node
{
	int x,y;
}q[1000000];
int sum;
int main()
{
	int cas;
	scanf("%d",&cas);
	while (cas--)
	{
		getchar();
		char ch;
		int xbegin=-1,ybegin=-1,xend=-1,yend=-1;
		for (int i=1;i<=8;i++)
		{
			for (int j=1;j<=8;j++)
			{
				scanf("%c",&ch);
				if (ch == '*')
				  map[i][j] = 1;
				else if (ch == '#')
				  map[i][j] = 0;
				else if (ch == 'T')
				{
					xend = i;
					yend = j;
					map[i][j] = 0;
				}else if (ch == 'S')
				{
					xbegin = i;
					ybegin = j;
					map[i][j] = 0;
				}
				vis[i][j] = 0;
			}
			getchar();
		}
		if (xbegin == -1 || xend == -1 || ybegin == -1 || yend == -1)
		{
			printf("No way!\n");
			continue;
		}

		int head=0;
		int tail=0;
		sum = 0;
		memset(q,0,sizeof(q));
		q[tail].x = xbegin;
		q[tail].y = ybegin;
		while (q[tail].x != xend || q[tail].y != yend)
		{
			int xx = q[head].x+1;
			int yy = q[head].y-2;
			if (xx>=1 && xx<=8 && yy>=1 && yy<=8 && map[xx][yy]==0)	
			{
				tail++;
				q[tail].x = xx;
				q[tail].y = yy;
				
				if (xx == xend && yy == yend)
				  sum++;
			}
		}
/*		for (int i=0;i<8;i++)
		{
		  for (int j=0;j<8;j++)
			printf("%d ",map[i][j]);
		  printf("\n");
		}
		printf("\n");
		*/
	}
	return 0;
}
