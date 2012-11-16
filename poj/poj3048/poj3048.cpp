#include <cstdio>
const int MAX_LEN = 5000;
int prime[20000];
int arr[MAX_LEN+5];
int n;
bool isprime(int n){
	if (n == 2 || n == 3) return true;
	for (int i=2;i*i<=n;i++)
	{
		if (n%i == 0)
		  return false;
	}
	return true;
}
int main()
{
	int j=1;
	prime[0]=1;
	for (int i=2;i<20000;i++)
		if (isprime(i))
			prime[j++]=i;

	scanf("%d",&n);
	for (int i=0;i<n;i++)
	  scanf("%d",&arr[i]);
	int max=-1;
	int maxnum = -1;
	for (int i=0;i<n;i++)
	{
		for (int k=j-1;k>=0;k--)
		{
			if (arr[i] % prime[k] == 0)
			{
				if (max < prime[k])
				{
					max = prime[k];
					maxnum = arr[i];
				}
				break;
			}
		}
	}
	printf("%d\n",maxnum);
	return 0;
}
