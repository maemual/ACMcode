#include <cstdio>

int main()
{
	int cas;
	scanf("%d",&cas);
	long long n,m,num,ans;
	for (int i=1;i<=cas;i++)
	{
		scanf("%lld%lld",&n,&m);
		num = (m-n)+1;
		ans = (n+m)*num/2;
		printf("Scenario #%d:\n%lld\n\n",i,ans);
	}	
	return 0;
}
