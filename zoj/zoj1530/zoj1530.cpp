#include <cstdio>
const int MAX_LEN = 10000000;
unsigned long long queue[MAX_LEN];
int main()
{
	int n;
	while (scanf("%d",&n) != EOF)
	{
		if (n == 0)
		  break;
		long long ans = 1;
		int head=0,tail=0;
		queue[tail++]=ans;
		while (1)
		{
			ans = queue[head++];
			ans*=10;
			if (ans%n==0)
			  break;
			queue[tail++]=ans;
			ans++;
			if (ans%n==0)
			  break;
			queue[tail++]=ans;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
