#include <cstdio>
const int MAX_LEN = 10000;
int a[MAX_LEN+5];
int main()
{
	int n;
	for (int i=1;i<=MAX_LEN;i++)
		a[i] = i;
	for (int i=2;i<MAX_LEN;i++)
	{
		for (int j=i+1;j<=MAX_LEN;j++)
		{
			if (a[j] % a[i] == 0)
				a[j] /= a[i];
		}
	}
	//for (int i=1;i<=MAX_LEN;i++)
	//	a[i] %= 99999989;
	while (scanf("%d",&n) != EOF)
	{
		long long sum = 1;
		for (int i=1;i<=n;i++)
		{
			sum = ((sum % 99999989)* a[i] ) % 99999989;
		}
		printf("%lld\n",sum % 99999989);
	}
	return 0;
}
