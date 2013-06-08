#include <cstdio>

int main()
{
	int n;
	int ans;
	while (scanf("%d",&n) != EOF)
	{
		int m = 1;
		ans = 1;
		while (m != 0)
		{
			m = (m*10+1)%n;
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
