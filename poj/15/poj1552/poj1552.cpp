#include <stdio.h>

int main()
{
	int a[100];
	int x,i,sum;
	while (scanf("%d",&x))
	{
		if (x == -1)
			break;
		sum = 0;
		for (i=1;i<=99;i++)
			a[i] = 0;
		while (x != 0)
		{
			a[x] = 1;
			scanf("%d",&x);
		}
		for (i=1;i<=49;i++)
		{
			if (a[i] == 1 && a[2*i] == 1)
			  sum++;
		}
		printf("%d\n",sum);
	}
	return 0;
}
