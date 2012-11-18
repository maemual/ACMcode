#include <stdio.h>

int main()
{
	int cas;
	scanf("%d",&cas);
	int n;
	int i,j;
	int a[32];
	while (cas--)
	{
		scanf("%d",&n);
		j = 0;
		for (i = 0; i < 32; i++)
		{
			if (n % 2 == 1)
				a[j++] = i;
			n >>= 1;
			if (n == 0)
			  break;
		}
		for (i = 0; i < j-1; i++)
		  printf("%d ",a[i]);
		printf("%d\n",a[j-1]);
	}
	return 0;
}
