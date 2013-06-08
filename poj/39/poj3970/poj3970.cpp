#include <cstdio>
long long gcd(long long a,long long b)
{
	if (a%b==0) return b;
	return gcd(b,a%b);
}
long long lcm(long long a,long long b)
{
	return a/gcd(a,b)*b;
}
int main()
{
	int n;
	while (1)
	{
		scanf("%d",&n);
		if (n == 0)
		  break;
		long long ans;
		scanf("%lld",&ans);
		if (n != 1){
			long long x;
			for (int i=1;i<n;i++)
			{
				scanf("%lld",&x);
				ans = lcm(ans,x);
			}
		}
		if (ans >=1000000)
		  printf("Too much money to pay!\n");
		else
		  printf("The CEO must bring %lld pounds.\n",ans);
	}
	return 0;
}
