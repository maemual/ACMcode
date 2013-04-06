/*************************************************************************
	> File Name: test.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年04月06日 星期六 20时47分54秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;

int n,m;
int s,t,k;
int mar[1005][1005];
int vis[1005][1005];
int cnt;
int ans;
void dfs(int s){
	if (s == t){
		if (cnt % k < ans)
			ans = cnt % k;
		return ;
	}
	for (int i = 1; i <= n; i++){
		if (vis[s][i] == 1){
			vis[s][i] = 0;
			cnt += mar[s][i];
			dfs(i);
			cnt -= mar[s][i];
			vis[s][i] = 1;
		}
	}
}
int main()
{
	int x,y,v;
	while (scanf("%d %d",&n,&m) != EOF){
		memset(vis,-1,sizeof(vis));
		for (int i = 0; i < m; i++){
			scanf("%d %d %d",&x,&y,&v);
			mar[x][y] = v;
			vis[x][y] = 1;
		}
		scanf("%d %d %d",&s,&t,&k);
		cnt = 0;
		ans = 1000000;
		dfs(s);
		printf("%d\n",ans);
	}
	return 0;
}
