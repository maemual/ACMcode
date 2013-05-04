/*************************************************************************
	> File Name: a.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年05月04日 星期六 09时48分26秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

#define MAX_LEN 105
int rank[MAX_LEN];
int v[MAX_LEN];
void make_set(int x){
	v[x] = x;
	//rank[x] = 0;
}
int find_set(int x){
	if (v[x] != x)
		v[x] = find_set(v[x]);
	return v[x];
}
void union_set(int x, int y){
	//if (rank[x] > rank[y])
	//	v[y] = x;
	//else if (rank[x] < rank[y])
	//	v[x] = y;
	//else if (rank[x] == rank[y]){
		v[x] = y;
	//	rank[y]++;
	//}
}
struct Edge{
	int x, y, w;
}e[MAX_LEN*MAX_LEN];
bool cmp(const Edge &e1, const Edge &e2){
	if (e1.w < e2.w)
		return true;
	else
		return false;
}
int main()
{
	int n,m;
	int ans;
	int mmax;
	int s1,s2;
	while (scanf("%d %d", &n, &m) != EOF){
		for (int i = 0; i < m; i++)
			scanf("%d %d %d", &e[i].x, &e[i].y, &e[i].w);
		sort(e,e+m,cmp);
		for (int i = 0; i < n; i++)
			make_set(i);
		ans = 0;
		mmax = 0;
		for (int i = 0; i < m; i++){
			s1 = find_set(e[i].x);
			s2 = find_set(e[i].y);
			if (s1 != s2){
				ans += e[i].w;
				if (mmax < e[i].w)
					mmax = e[i].w;
				union_set(s1,s2);
			}
		}
		printf("%d %d\n", ans, mmax);
	}
	return 0;
}
