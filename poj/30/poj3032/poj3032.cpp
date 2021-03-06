#include <cstdio>
#include <queue>
using namespace std;

int main()
{
	int cas;
	scanf("%d",&cas);
	int n;
	int ans[20];
	while (cas--)
	{
		queue<int> q;
		scanf("%d",&n);
		q.push(n);
		for (int i=n-1;i>=1;i--)
		{
			q.push(i);
			for (int j=1;j<=i;j++)
			{
				int temp=q.front();
				q.pop();
				q.push(temp);
			}
		}
		for (int i=0;!q.empty();i++)
		{
			ans[i] = q.front();
			q.pop();
		}
		for (int i=n-1;i>0;i--)
			printf("%d ",ans[i]);
		printf("%d\n",ans[0]);
	}
	return 0;
}
