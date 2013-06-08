#include <cstdio>
#include <cstring>
#include <ctime>
const int MAX_LEN = 10000000;
bool prime[MAX_LEN+5];
/*bool isprime(int n)
{
	if (n < 2) return false;
	if (n == 2 || n == 3) return true;
	for (int i=2;i*i<=n;i++)
	{
		if (n%i == 0)
		  return false;
	}
	return true;
}*/
int main()
{
	//long long start = clock();
	memset(prime,0,sizeof(prime));
	prime[0] = false;
	prime[1] = false;
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
		p = 2*(i+1);
	}
	//for (int i=0;i<MAX_LEN;i++)
	//{
	//	if (isprime(i))
	//	  prime[i] = true;
	//}
	int n,m;
	while (1)
	{
		scanf("%d%d",&n,&m);
		if (n == -1 && m ==-1)
		  break;
		int sum = 0;
		for (int i=n;i<=m;i++)
		{
			if (prime[i])
			  sum++;
		}
		printf("%d\n",sum);
	}
	//for (int i=0;i<100;i++)
	//  if (prime[i])
	//	printf("%d ",i);
	//printf("\n");
	//long long end = clock();
	//printf("%lld\n",end-start);
	return 0;
}
