#include <cstdio>
int work(int a)
{
	int ans = 0;
	while (a>0)
	{
		ans = ans*10+a%10;
		a /= 10;
	}
	return ans;
}
int main()
{
	int cas;
	scanf("%d",&cas);
	while (cas--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",work(work(a)+work(b)));
	}
	return 0;
}
