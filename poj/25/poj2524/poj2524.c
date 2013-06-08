/*************************************************************************
	> File Name: poj2524.c
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年06月08日 星期六 19时58分50秒
 ************************************************************************/

#include<stdio.h>

#define MAX_LEN 50000

int par[MAX_LEN + 5],rank[MAX_LEN + 5];
int n,m;
void make_set(int x){
	par[x] = x;
	rank[x] = 0;
}
int find_set(int x){
	if (par[x] != x)
		par[x] = find_set(par[x]);
	return par[x];
}
void union_set(int x, int y){
	x = find_set(x);
	y = find_set(y);
	if (rank[x] > rank[y])
		par[y] = x;
	else if (rank[x] < rank[y])
		par[x] = y;
	else {
		par[x] = y;
		rank[y]++;
	}
}
int main()
{
	int i;
	int x,y;
	int ans;
	int T = 0;
	while (scanf("%d %d", &n, &m) != EOF){
		if (n == 0 && m == 0)
			break;
		for (i = 1; i <= n; i++)
			make_set(i);
		for (i = 0; i < m; i++){
			scanf("%d %d", &x, &y);
			union_set(x, y);
		}
		ans = 0;
		for (i = 1; i <= n; i++){
			if (i == par[i])
				ans++;
		}
		printf("Case %d: %d\n", ++T, ans);
	}
	return 0;
}
