#include <stdio.h>
#include <string.h>
char ans[3000][3000];
int p[]={1,3,9,27,81,243,729,2187};
int n;
void doit(int x,int y,int flag,int len)
{
	if (flag == 0)
	  return ;
	if (len == 1)
	{
		ans[x][y] = 'X';
		return ;
	}
	len /= 3;
	doit(x,y,1,len);doit(x,y+len,0,len);doit(x,y+2*len,1,len);
	doit(x+len,y,0,len);doit(x+len,y+len,1,len);doit(x+len,y+2*len,0,len);
	doit(x+2*len,y,1,len);doit(x+2*len,y+len,0,len);doit(x+2*len,y+2*len,1,len);
}
int main()
{
	int i,j;
	while (1)
	{
		scanf("%d",&n);
		if (n == -1)
		  break;
		memset(ans,' ',sizeof(ans));
		doit(0,0,1,p[n-1]);
		for (i = 0; i < p[n-1]; i++)
		{
			for (j = 0; j < p[n-1]; j++)
			  printf("%c",ans[i][j]);
			printf("\n");
		}
		printf("-\n");
	}
	return 0;
}
