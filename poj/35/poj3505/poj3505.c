#include <stdio.h>

#define MAX_LEN 50
struct node{
	int h,l;
}loc[MAX_LEN*MAX_LEN+5];
int h,k;
int doit(int a,int b)
{
	if (a > b)
	{
		int t = a;
		a = b; 
		b = t;
	}
	return (b-a)>(k-b+a)?(k-b+a):(b-a);
}
int main()
{
	int cas;
	scanf("%d",&cas);
	int i,j;
	int temp;
	int n;
	int turn[MAX_LEN+5];
	while (cas--)
	{
		scanf("%d %d",&h,&k);
		n = 0;
		for (i = 1; i <= h; i++)
		{
			turn[i] = 1;
			for (j = 1; j <= k; j++)
			{
				scanf("%d",&temp);
				if (temp != -1)
				{
					loc[temp].h = i;
					loc[temp].l = j;
					n++;
				}
			}
		}
		int ans = 0;
		for (i = 1; i <= n; i++)
		{
			ans += 20*(loc[i].h - 1) + 5*doit(loc[i].l,turn[loc[i].h]);
			turn[loc[i].h] = loc[i].l;
		}
		printf("%d\n",ans);
	}
	return 0;
}
