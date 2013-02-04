#include <stdio.h>

int main()
{
	int m;
	int i;
	while (scanf("%d",&m) != EOF)
	{
		int x,y;
		scanf("%d",&x);
		for (i = 1; i < m; i++)
		{
			scanf("%d",&y);
			x ^= y;
		}
		if (x != 0)
		  printf("Yes\n");
		else
		  printf("No\n");
	}
	return 0;
}
