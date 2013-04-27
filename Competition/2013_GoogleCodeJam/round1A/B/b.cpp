#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
int a[20];
bool vis[20];
int n;
int r,e;
int ans;
void dfs(int id,int en,int tmp)
{
	if(id>n)
	{
		ans=max(ans,tmp);
		return ;
	}
	for(int i=0;i<=en;i++)
	{
		dfs(id+1,min(e,en-i+r),tmp+i*a[id]);
	}

}
int main()
{
	int t;
	int game=0;
	scanf("%d",&t);
	while(t--)
	{
		game++;
		scanf("%d%d%d",&e,&r,&n);
		memset(a,0,sizeof(a));
		memset(vis,false,sizeof(vis));
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		ans=0;
		dfs(1,e,0);
		printf("Case #%d: %d\n",game,ans);
	}
	return 0;
}

