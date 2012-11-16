#include <cstdio>
int main()
{
	int n;
	int k;
	int sum=0;
	while(scanf("%d%d",&n,&k) != EOF)
	{
		sum=n;
		while(n/k)
		{
			sum+=(n/k);
			n=n%k+n/k;
		}
		printf("%d\n",sum);
	}
	return 0;
}
