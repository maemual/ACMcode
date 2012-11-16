#include <cstdio>
const int MAX_LEN = 32767;
long long a[MAX_LEN+5];
int main()
{
	while (scanf("%lld%lld%lld",&a[0],&a[1],&a[2]) != EOF)
	{
		for (int i=3;i<=99;i++)
		  a[i] = a[i-1]+a[i-2]+a[i-3];
		printf("%d\n",a[99]);
	}
	return 0;
}
