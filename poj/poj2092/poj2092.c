#include <stdio.h>
#include <string.h>
int main()
{
	int num[10005];
	int n,m;
	int i,j,x;
	int max1,max2;
	while (1)
	{
		scanf("%d %d",&n,&m);
		if (n == 0 && m == 0)
		  break;
		memset(num,0,sizeof(num));
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				scanf("%d",&x);
				num[x]++;
			}
		}
		max1 = -1;
		for (i = 1; i <= 10000; i++)
		{
			if (num[i] > max1)
			  max1 = num[i];
		}
		max2 = -1;
		for (i = 1; i <= 10000; i++)
		{
			if (num[i] > max2 && num[i] < max1)
			  max2 = num[i];
		}
		for (i = 1; i <= 10000; i++)
		{
			if (num[i] == max2)
			{
				printf("%d",i);
				break;
			}
		}
		i++;
		for (;i <= 10000; i++)
		{
			if (num[i] == max2)
			{
				printf(" %d",i);
			}
		}
		printf("\n");
	}
	return 0;
}
