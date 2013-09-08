#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct tree
{
	vector<int> child;
	int flag;
}node[100010];
int n,m;
int dp[100010];
void bfs(int fa,int now,int cnt)
{
	for(int i = 0;i < node[now].child.size();i++)
	{
		int son = node[now].child[i];
		if(son == fa)	continue;
		if(node[son].flag)
		  continue;
		if(dp[son] != 0 && dp[son] <= cnt)
		  continue;
        bfs(now,son,cnt+1);
		if(dp[son] == 0 || dp[son] > cnt)
		  dp[son] = cnt;
	}
}
int main()
{
	scanf("%d %d", &n, &m);
	int x,y;
	for(int i = 1; i <= n-1;i++){
		scanf("%d %d",&x,&y);
		node[x].child.push_back(y);
		node[y].child.push_back(x);
	}
	node[1].flag = true;
	dp[1] = 0;
	bfs(-1 , 1, 1);
	for(int i = 1; i <= m; i++)
	{
		scanf("%d %d",&x,&y);
		if (x == 2)
            printf("%d\n", dp[y]);
		else{
			node[y].flag = true;
			dp[y] = 0;
			bfs(-1,y,1);
		}
	}
	return 0;
}
