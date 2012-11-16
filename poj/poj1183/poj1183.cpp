#include <cstdio>
int main()
{
    long long a,b,result;
	scanf("%lld",&a);
	b = a * a + 1;
	for(int i = a; i > 0; i--)
	{
		if (b % i == 0)
		{
			result = i + 2 * a + (b / i);
			printf("%lld\n",result);
			break;
		}
	}
return 0;
}
