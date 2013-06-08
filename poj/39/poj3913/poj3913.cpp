#include <cstdio>

int main()
{
	int cas;
	scanf("%d",&cas);
	int a,b,c;
	printf("Gnomes:\n");
	while (cas--)
	{
		scanf("%d%d%d",&a,&b,&c);
		if (a > b && b >c || a < b && b < c)
		  printf("Ordered\n");
		else 
		  printf("Unordered\n");
	}
	return 0;
}
