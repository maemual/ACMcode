#include <cstdio>
int main()
{
	long long  n,k;  // Must lld or you will get WA.
	while( scanf("%lld%lld",&n,&k)!=EOF && n )
	{
		long long int sum = 1;
		int x = 1;
		if( k == 0 )
		{
			printf("1\n");
			continue;
		}
		if( k > n-k ) // It is so important. Save time !!!
		  k = n-k;
		for(int i=n; i>n-k; i--)
		{
			sum *= i;
			sum /= x;
			x++;
		}
		printf("%lld\n",sum);
	}
	return 0;
}

