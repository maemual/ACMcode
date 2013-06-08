#include <stdio.h>

int main()
{
	int cas;
	scanf("%d",&cas);
	int k;
	for (k=1;k<=cas;k++)
	{
		int m,n;
		scanf("%d %d",&m,&n);
		int product = m*n;
		if (product%2 == 1)
		  printf("Scenario #%d:\n%d.41\n\n",k,product);
		else 
		  printf("Scenario #%d:\n%d.00\n\n",k,product);
	}
	return 0;
}
