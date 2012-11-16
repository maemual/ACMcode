#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAX_LEN = 64;
bool vis[MAX_LEN+5];
int sticks[MAX_LEN+5];
int sum,part,len;
int n;
bool cmp(int  a,int b)
{
	return a>b;
}
bool dfs(int unused,int left,int target_len)
{
	if (unused == 0 && left == 0)
	  return true;
	if (left == 0)
	  left = target_len;

	for (int i=0;i<n;i++)
	{
		if (!vis[i] && sticks[i] <= left)
		{
			vis[i] = true;
			if (dfs(unused-1,left-sticks[i],target_len))
			  return true;
			vis[i] = false;
			if (sticks[i] == left || left == target_len)
			  return false;
		}
	}
	return false;
}
int main()
{
	while (1)
	{
		scanf("%d",&n);
		if (n == 0)
		  break;
		sum = 0;
		memset(vis,0,sizeof(vis));
		for (int i=0;i<n;i++)
		{
			scanf("%d",&sticks[i]);
			sum += sticks[i];
		}
		std::sort(sticks,sticks+n,cmp);
		for (int i=sticks[0];i<=sum;i++)
		{
			if (sum % i == 0)
			{
				if (dfs(n,0,i))
				{
					printf("%d\n",i);
					break;
				}
			}
		}
	}
	return 0;
}
