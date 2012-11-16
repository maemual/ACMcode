#include <cstdio>
#include <cstring>
const int MAX_LEN = 45;
long long f[MAX_LEN];
int n;
long long sum;
int main()
{
	f[0] = 0;
	f[1] = 3;
	f[2] = 9;
	f[3] = 26;
	f[4] = 75;
	for (int i=5;i<=40;i++)
	{
		f[i] = f[i-1]*3 - f[i-3];
	}
	int cnt=0;
	while (scanf("%d",&n) != EOF)
	{
		printf("Case %d: %lld\n",++cnt,f[n]);
	}
	return 0;
}
