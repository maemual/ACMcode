#include <cstdio>

int main()
{
	int cas;
	scanf("%d",&cas);
	while (cas--)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if (b-a == c-b && c-b == d-c)
			printf("%d %d %d %d %d\n",a,b,c,d,2*d-c);
		else
			printf("%d %d %d %d %d\n",a,b,c,d,d*d/c);
	}
	return 0;
}
