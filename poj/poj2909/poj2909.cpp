#include <cstdio>
#include <cstring>
const int MAX_LEN = 32767;
bool prime[MAX_LEN+5];
int main()
{
	int p =4;
	memset(prime,1,sizeof(prime));
	for (int i=2;i<MAX_LEN;i++)
	{
		if (prime[i])
		{
			while (p<MAX_LEN)
			{
				prime[p] = false;
				p += i;
			}
		}
		p = 2*(i+1);
	}
	prime[0] = false;
	prime[1] = false;
	int n;
	while (1)
	{
		scanf("%d",&n);
		if (n == 0)
		  break;
		int sum = 0;
		if (prime[n-2])
		  sum++;
		for (int i=3;i<=n/2;i+=2)
		{
			if (prime[i] && prime[n-i])
			  sum++;
		}
		printf("%d\n",sum);
	}
	return 0;
}
