#include <cstdio>
#include <list>
using namespace std;

int main()
{
	int n,m,k;
	while (scanf("%d%d%d",&n,&m,&k) != EOF)
	{
		list<int> ll;
		for (int i=1;i<=n;i++)
			ll.push_back(i);
		int cnt=1;
		int ans;
		list<int>::iterator ix = ll.begin();
		int q = 0;
		while (1)
		{
			while (q <= m)
			{
				ix++;
				if (ix == ll.end())
					ix = ll.begin();
				q++;
			}
			if (*ix == k)
			{
				ans = cnt;
				break;
			}
			ll.erase(ix);
			cnt++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
