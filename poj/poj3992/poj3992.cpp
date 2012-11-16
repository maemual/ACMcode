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
void swap(long long &x,long long &y)
{
	if (x < y)
	{
		long long temp = x;
		x = y;
		y = temp;
	}
}
int main()
{
	long long n,m;
	while (1)
	{
		scanf("%lld%lld",&n,&m);
		if (n == 0 && m == 0)
		  break;
		swap(n,m);
		if (n % m == 0)
			printf("%lld\n",n/m);
		else
			printf("%lld\n",lcm(n,m)/gcd(n,m));
	}
	return 0;
}
