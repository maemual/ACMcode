#include <stdio.h>
#include <string.h>

char temple[6][6];
char ans[3000][3000];
int n,m;
int pow(int m,int n)
{
	int i,sum = 1;
	for (i = 0; i < n; i++)
	  sum *= m;
	return sum;
}
void doit(int x,int y,int flag,int wid)
{
	int i,j;
	if (flag == 0)
	  return;
	if (wid == n && flag == 1)
	{
		for (i = x; i < x + wid; i++)
		{
			for (j = y; j < y + wid; j++)
			  ans[i][j] = temple[i -  x][j - y];
		}
	}else {
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (temple[i][j] != ' ')
				  doit(x + i * wid / n,y + j * wid / n,1,wid / n);
				else
				  doit(x + i * wid / n,y + j * wid / n,0,wid / n);
			}
		}
	}
}
int main()
{
	int i,j;
	while (1)
	{
		scanf("%d",&n);
		if (n == 0)
		  break;
		memset(temple,' ',sizeof(temple));
		memset(ans,' ',sizeof(ans));
		getchar();
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			  temple[i][j] = getchar();
			getchar();
		}
		scanf("%d",&m);
		doit(0,0,1,pow(n,m));
		for (i = 0; i < pow(n,m); i++)
		{
			for (j = 0; j < pow(n,m); j++)
			  putchar(ans[i][j]);//poj is shit.putchar is AC,but printf is TLE.
			putchar('\n');
		}
	}
	return 0;
}
