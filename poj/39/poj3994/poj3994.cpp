#include <cstdio>

int main()
{
	int k=0,n;
	while (1)
	{
		scanf("%d",&n);
		if (n == 0)
		  break;
		n *= 3;
		printf("%d. ",++k);
		if (n % 2 == 0)
		{
			printf("even ");
			n /= 2;
			n *= 3;
			n /= 9;
		}
		else
		{
			 printf("odd ");
			 n = (n+1)/2;
			 n *=3;
			 n/=9;
		}
		printf("%d\n",n);
	}
	return 0;
}
