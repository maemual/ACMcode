#include <stdio.h>

int main()
{
	int n,i;
	while (1)
	{
		scanf("%d",&n);
		if (n == 0)
		  break;
		int p = 1 << ((n - 1960) / 10 + 2);
		double sum = 1.0;
		int k = 1;
		for (i = 1; i <= p; i++)
		{
			sum *= 2.0;
			if (sum > k)
			{
				k++;
				sum /= k;
			}
		}
		printf("%d\n",k);
	}
	return 0;
}
