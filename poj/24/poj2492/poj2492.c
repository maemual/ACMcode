/*************************************************************************
	> File Name: poj2492.c
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年05月01日 星期三 11时40分55秒
 ************************************************************************/

#include<stdio.h>

#define MAX_LEN 2005
int n,m;
int parent[MAX_LEN],opp[MAX_LEN];
void make_set(){
	int x;
	for (x = 1; x <= n; x++){
		parent[x] = x;
		opp[x] = 0;
	}
}
int find_set(int x){
	if (x != parent[x])
		parent[x] = find_set(parent[x]);
	return parent[x];
}
void union_set(int x, int y){
	x = find_set(x);
	y = find_set(y);
	if (x == y) return ;
	parent[y] = x;
}
int main()
{
	int i,j,k;
	int x,y;
	int cas;
	scanf("%d", &cas);
	for (k = 1; k <= cas; k++){
		scanf("%d %d", &n, &m);
		make_set();
		int flag = 0;
		while (m--){
			scanf("%d %d", &x, &y);
			if (flag) continue;
			if (find_set(x) == find_set(y))
				flag = 1;
			if (opp[x] == 0 && opp[y] == 0){
				opp[x] = y;
				opp[y] = x;
			}else if (opp[x] == 0){
				opp[x] = y;
				union_set(x, opp[y]);
			}else if (opp[y] == 0){
				opp[y] = x;
				union_set(y, opp[x]);
			}else{
				union_set(x, opp[y]);
				union_set(y, opp[x]);
			}
		}
		printf("Scenario #%d:\n", k);
		if (flag)
			printf("Suspicious bugs found!\n\n");
		else
			printf("No suspicious bugs found!\n\n");
	}
	return 0;
}
