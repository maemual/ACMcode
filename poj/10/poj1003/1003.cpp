#include <stdio.h>

int main()
{
	float len,sum;
	int n;
	while (1)
	{
		scanf("%f",&len);
		if (len == 0.00)
			break;
		n=1;
		sum=0;
		while (sum<len)
		{
			sum += 1.0 / (n+1);
			n++;
		}
		printf("%d card(s)\n",n-1);
	}
	return 0;
}
