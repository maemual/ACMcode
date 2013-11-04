/*
 *	Problem: 1011
 *	Memory: 392K		Time: 0MS
 *	Language: G++		Result: Accepted
 *	2012-07-18-20-32
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
const int MAX_LEN = 64;
int sticks[MAX_LEN+5];
bool vis[MAX_LEN+5];
int n,sum,num,len;
bool cmp(int a,int b)
{
	return a>b;
}
//now表示已拼成几根，need表示need长拼成这一根，从第k根木棍开始。
bool dfs(int now,int need,int k)
{
	//当此根木棍已经拼成
	if (need==0)
	{
		now++;
		need=len;
		k=0;
	}
	//当拼好num-1根的时候，还剩下一根，必然是可以拼成的，返回
	if (now == num-1)
	  return true;
	for (int i=k;i<n;i++)
	{
		if (!vis[i] && need>=sticks[i]){
			vis[i] = true;
			if (dfs(now,need-sticks[i],i+1))
			  return true;
			vis[i] = false;
			//此种长度len无法找到满足的组合，直接退出。
			if (need == len)
			  return false;
			//因为每根木棍都要用，但是此根木棍搜索失败，直接退出。
			if (need == sticks[i])
			  return false;
			//当此根搜索失败，那么与此根长度相同的可以直接跳过。
			while (sticks[i+1] == sticks[i])
			  i++;
		}
	}
	return false;
}
int main()
{
	while (scanf("%d",&n) != EOF)
	{
		if (n==0)
		  break;
		sum = 0;
		memset(vis,0,sizeof(vis));

		for (int i=0;i<n;i++){
			scanf("%d",&sticks[i]);
			sum+=sticks[i];
		}
		std::sort(sticks,sticks+n,cmp);//从大到小排序，便于搜索
		sticks[n] = 0;
		for (int i=sticks[0];i<=sum;i++)
		{
			if (sum%i==0)
			{
				num=sum/i;
				len=i;
				if (dfs(0,i,0))
				{
					printf("%d\n",i);
					break;
				}
			}
		}
	}
	return 0;
}
