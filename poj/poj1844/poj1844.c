#include <stdio.h>

int main()
{
	int s,sum;
	int i;
	while (scanf("%d",&s) != EOF)
	{
		sum = 0;
		i = 0;
		while (1)
		{
			sum += i;
			if (sum >= s && (sum - s) % 2 == 0)
			{
				printf("%d\n",i);
				break;
			}
			i++;
		}
	}
	return 0;
}
