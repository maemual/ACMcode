#include <stdio.h>
#include <string.h>
#define MAX_LEN 10005

int ticket[MAX_LEN];
int main()
{
	int m,n;
	int i;
	int x;
	int sum;
	while (1)
	{
		scanf("%d %d",&n,&m);
		if (n == 0 && m == 0)
		  break;
		memset(ticket,0,sizeof(ticket));
		for (i = 0; i < m; i++)
		{
			scanf("%d",&x);
			ticket[x]++;
		}
		sum = 0;
		for (i = 1; i <= n; i++)
		{
			if (ticket[i] > 1)
			  sum++;
		}
		printf("%d\n",sum);
	}
	return 0;
}
