#include <stdio.h>
#include <string.h>
#define MAX_LEN 2050
int ans[MAX_LEN][MAX_LEN];
int p[]={1,2,4,8,16,32,64,128,256,512,1024,2048};
int n;
void doit(int x,int y,int k)
{
	if (k == 1)
	{
						ans[x][y] = '/';			ans[x][y+1] = '\\';
		ans[x+1][y-1] = '/';ans[x+1][y]='_';ans[x+1][y+1]='_';ans[x+1][y+2] = '\\';
		return ;
	}
						doit(x,y,k-1);
	doit(x+p[k-1],y-p[k-1],k-1);doit(x+p[k-1],y+p[k-1],k-1);
}
int main()
{
	int i,j;
	while (1)
	{
		scanf("%d",&n);
		if (n == 0)
		  break;
		memset(ans,' ',sizeof(ans));
		doit(0,p[n]-1,n);
		for (i = 0; i < p[n]; i++)
		{
			for (j = 0; j < p[n]+i+1; j++)
			{
				  printf("%c",ans[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
