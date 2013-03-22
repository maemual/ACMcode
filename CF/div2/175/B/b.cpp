/*************************************************************************
	> File Name: b.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年03月21日 星期四 23时55分18秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

int tra[100005];
bool vis[100005] = {0};
int main()
{
	int n,s,t;
	scanf("%d %d %d",&n,&s,&t);
	for (int i = 1; i <= n; i++)
		scanf("%d",&tra[i]);
	if (s == t){
		printf("0\n");
		return 0;
	}
	if (tra[s] == s){
		printf("-1\n");
		return 0;
	}
	int pos = s;
	vis[pos] = true;
	int ans = 0;
	while (1){
		ans++;
		pos = tra[pos];
		if (vis[pos]){
			printf("-1\n");
			return 0;
		}
		vis[pos] = true;
		//printf("%d\n",pos);
		if (pos == t)
			break;
	}
	printf("%d\n",ans);
	return 0;
}
