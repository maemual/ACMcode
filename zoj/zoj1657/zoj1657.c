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
	int ans;
	while (1)
	{
		scanf("%d",&n);
		if (n == 0)
		  break;
		flag = 1;
		ans = 0;
		for (i = 2; i <= n / 2; i++)
		{
			if (prime[i] && prime[n-i])
			{
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
