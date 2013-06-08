/*************************************************************************
	> File Name: poj1611.c
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年05月02日 星期四 10时31分43秒
 ************************************************************************/

#include<stdio.h>

#define MAX_LEN 30005
int n,m;
int par[MAX_LEN],tot[MAX_LEN];
void make_set(){
	int i;
	for (i = 0; i < n; i++){
		par[i] = i;
		tot[i] = 1;
	}
}
int find_set(int x){
	if (par[x] != x)
		par[x] = find_set(par[x]);
	return par[x];
}
void union_set(int a, int b){
	int x = find_set(a);
	int y = find_set(b);
	if (x == y)
		return ;
	tot[x] += tot[y];
	par[y] = x;
}
int main()
{
	int i,j;
	int x,y,z;
	while (1){
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0)
			break;
		make_set();
		for (i = 0; i < m; i++){
			scanf("%d", &x);
			scanf("%d", &y);
			for (j = 1; j < x; j++){
				scanf("%d", &z);
				union_set(y,z);
			}
		}
		printf("%d\n",tot[find_set(0)]);
	}
	return 0;
}
