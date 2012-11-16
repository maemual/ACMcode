#include <cstdio>
#include <cstring>
#include <algorithm>
const int MAX_LEN = 12;
int a[MAX_LEN+5];
int ans[MAX_LEN+5];
int sum,n;
bool flag;
bool cmp(int p,int q)
{
	return p>q;
}
void dfs(int k,int p,int need)
{
	if (need==0)
	{
		for (int i=0;i<k-1;i++)
		  printf("%d+",ans[i]);
		printf("%d\n",ans[k-1]);
		flag = false;
		return;
	}
	for (int i=p;i<n;i++)
	{
		if (i==p || a[i]!=a[i-1] && need-a[i]>=0)
		{
			ans[k] = a[i];
			dfs(k+1,i+1,need-a[i]);
		}
	}
}
int main()
{
	while (1)
	{
		scanf("%d%d",&sum,&n);
		if (sum==0 && n==0)
		  break;
		for (int i=0;i<n;i++)
		  scanf("%d",&a[i]);
		std::sort(a,a+n,cmp);
		memset(ans,0,sizeof(ans));
		printf("Sums of %d:\n",sum);
		flag = true;
		dfs(0,0,sum);
		if (flag)
		  printf("NONE\n");
	}
	return 0;
}
