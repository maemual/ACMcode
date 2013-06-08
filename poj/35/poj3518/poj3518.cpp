#include <cstdio>
#include <cstring>
const int MAX_LEN = 1299709;
bool prime[MAX_LEN+5];
int main()
{
	memset(prime,1,sizeof(prime));
	prime[0] = false;
	int p = 4;
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
		p = 2* (i+1);
	}
	int n;
	while (1)
	{
		scanf("%d",&n);
		if (n == 0)
		  break;
		int sum = 0;
		if (prime[n])
		  printf("%d\n",0);
		else {
			for (int i=n;i>1;i--)
			{
				if (!prime[i])
				  sum++;
				else break;
			}
			for (int i=n;i<MAX_LEN;i++)
			{
				if (!prime[i])
				  sum++;
				else break;
			}
			printf("%d\n",sum);
		}
	}
	return 0;
}
