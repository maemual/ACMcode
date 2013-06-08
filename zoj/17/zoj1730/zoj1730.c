#include <stdio.h>

int main()
{
	int cas;
	scanf("%d",&cas);
	int n;
	while (cas--)
	{
		scanf("%d",&n);
		printf("%d\n",(n/2*(n/2-1))/2+(n-n/2)*(n-n/2-1)/2);
	}
	return 0;
}
