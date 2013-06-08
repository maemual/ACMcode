#include <cstdio>
#include <queue>
using namespace std;
struct cmp
{
	bool operator()(int &a,int &b)
	{
		return a>b;
	}
};
priority_queue<int,vector<int>,cmp> q;
int main()
{
	int n;
	while (scanf("%d",&n) != EOF)
	{
		int x;
		for (int i=0;i<n;i++)
		{
			scanf("%d",&x);
			q.push(x);
		}
		long long ans = 0;
		long long k;
		for (int i=1;i<n;i++)
		{
			k = q.top();
			q.pop();
			k += q.top();
			q.pop();
			ans += k;
			q.push(k);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
