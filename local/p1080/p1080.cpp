#include <cstdio>

int main()
{
	int cas;
	int a,b,c;
	scanf("%d",&cas);
	while (cas--)
	{
		scanf("%d %d %d",&a,&b,&c);
		if (a*a+b*b==c*c || a*a+c*c==b*b || b*b+c*c==a*a)
		  printf("Y\n");
		else
		  printf("N\n");
	}
	return 0;
}
