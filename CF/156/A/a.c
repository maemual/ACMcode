#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int i;
	int sum0 = 0,sum1 = 0,sum2 = 0;
	int x;
	for (i = 0; i < n; i++)
	{
		scanf("%d",&x);	
		if (i % 3 == 0)
		  sum0 += x;
		else if (i % 3 == 1)
		  sum1 += x;
		else
		  sum2 += x;
	}
	if (sum0 >= sum1 && sum0 >= sum2)
	  printf("chest\n");
	else if (sum1 >= sum0 && sum1 >= sum2)
	  printf("biceps\n");
	else 
	  printf("back\n");
	return 0;
}
