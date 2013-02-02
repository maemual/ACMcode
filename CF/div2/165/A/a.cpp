#include <stdio.h>

int main()
{
	int t;
	int ang;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&ang);
		int n = 360 / (180 - ang);
		if ((n - 2)*180  == ang * n)
		  printf("YES\n");
		else
		  printf("NO\n");
	}
	return 0;
}
