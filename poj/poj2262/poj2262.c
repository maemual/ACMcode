#include <stdio.h>

#define MAX_LEN 1000005

int prime[MAX_LEN];
int main()
{
	int i,j;
	for (i = 2; i < MAX_LEN; i++)
	  prime[i] = 1;
	for (i = 2; i < MAX_LEN; i++)
	{
		if (prime[i])
		{
			for (j = 2; i*j < MAX_LEN; j++)
			  prime[i*j] = 0;
		}
	}
	int n;
	int flag;
	while (1)
	{
		scanf("%d",&n);
		if (n == 0)
		  break;
		flag = 1;
		for (i = 3; i <= n / 2; i++)
		{
			if (prime[i] && prime[n-i])
			{
				printf("%d = %d + %d\n",n,i,n-i);
				flag = 0;
				break;
			}
		}
		if (flag)
		  printf("Goldbach's conjecture is wrong.\n");
	}
	return 0;
}
