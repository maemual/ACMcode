#include <stdio.h>

int main()
{
	int n,u,d;
	while (1)
	{
		scanf("%d %d %d",&n,&u,&d);
		if (n == 0 && u == 0 && d == 0)
		  break;
		int t = 0;
		while (1)
		{
			n -= u;
			t++;
			if (n <= 0)
			  break;
			n += d;
			t++;
		}
		printf("%d\n",t);
	}
	return 0;
}
