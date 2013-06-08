#include <stdio.h>
#include <string.h>
int a[105][105];
int search(int x,int y)
{
	a[x][y]=0;
	if (a[x][y+1]) search(x,y+1);
	if (a[x][y-1]) search(x,y-1);
	if (a[x-1][y-1]) search(x-1,y-1);
	if (a[x-1][y+1]) search(x-1,y+1);
	if (a[x-1][y]) search(x-1,y);
	if (a[x+1][y-1]) search(x+1,y-1);
	if (a[x+1][y]) search(x+1,y);
	if (a[x+1][y+1]) search(x+1,y+1);
	return 0;
}
int main()
{
	int i,j,n,m;
	while (scanf("%d%d",&m,&n)&&m)
	{
		memset(a,0,sizeof(a));
		while (getchar() == ' ') ;
		for (i=1;i<=m;i++)
		{
			for (j=1;j<=n;j++)
				if (getchar()=='@') a[i][j]=1;
			getchar();
		}
		int num=0;
		for (i=1;i<=m;i++)
			for (j=1;j<=n;j++)
				if (a[i][j]) {num++;search(i,j);}
		printf("%d\n",num);
	}
	return 0 ;
}
