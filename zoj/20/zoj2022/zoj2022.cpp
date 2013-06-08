#include <cstdio>

int main()
{
	int n;
	int cas;
	scanf("%d",&cas);
	while (cas--)
	{
		scanf("%d",&n);
		int sum=0;
		for (int i=5;i<=n;i*=5)
		  sum+=n/i;
		printf("%d\n",sum);
	}
}
