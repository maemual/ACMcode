#include <stdio.h>

int main()
{
	int n,x;
	while (1)
	{
		scanf("%d",&n);
		if (n==0)
		  break;
		x = n&-n;
		printf("%d\n",n+x+(n^n+x)/x/4);
	}
	return 0;
}
