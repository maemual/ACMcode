#include <cstdio>

int main()
{
	int n;
	scanf("%d",&n);
	int sum = 0;
	int k = 1;
	for (int i = 1; i <= n; i++)
	{
		sum += (n-i)*i+1;
	}
	printf("%d\n",sum);
	return 0;
}
