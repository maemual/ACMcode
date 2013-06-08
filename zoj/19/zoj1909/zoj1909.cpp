#include <cstdio>
#include <cstring>
#include <algorithm>
const int MAX_LEN = 20;
int sticks[MAX_LEN+5];
bool vis[MAX_LEN+5];
int len,num,n,sum;
bool cmp(int a,int b)
{
	return a>b;
}
bool dfs(int now,int need,int k)
{
	if (need == 0)
	{
		now++;
		need = len;
		k = 0;
	}
	if (now == 3)
	  return true;
	for (int i=k;i<n;i++)
	{
		if (!vis[i] && need>=sticks[i])
		{
			vis[i] = true;
			if (dfs(now,need-sticks[i],i+1))
			  return true;
			vis[i] = false;
			if (need == len || need == sticks[i])
			  return false;
			while (sticks[i]==sticks[i+1])
				i++;
		}
	}
	return false;
}
int main()
{
	int cas;
	scanf("%d",&cas);
	while (cas--)
	{
		scanf("%d",&n);
		sum = 0;
		for (int i=0;i<n;i++)
		{
			scanf("%d",&sticks[i]);
			sum+=sticks[i];
		}
		if (sum%4!=0)
		{
			printf("no\n");
			continue;
		}
		len = sum / 4;
		std::sort(sticks,sticks+n,cmp);
		memset(vis,0,sizeof(vis));
		if (dfs(0,len,0))
		  printf("yes\n");
		else 
		  printf("no\n");
	}
	return 0;
}
