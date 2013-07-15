/*************************************************************************
  > File Name: d.cpp
  > Author: maemual
  > Mail: maemual@gmail.com 
  > Created Time: 2013年07月14日 星期日 13时46分19秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

#define MAX_LEN 100005
int v[MAX_LEN];
bool flag[MAX_LEN];
int n,m;
void make_set(int x){
	v[x] = x;
	flag[x] = true;
}
int find_set(int x){
	int fx = v[x];
	if (x == fx)
		return x;
	v[x] = find_set(v[x]);
	if (flag[x] == flag[fx])
		flag[x] = true;
	else
		flag[x] = false;
	return v[x];
}
void union_set(int a, int b, int f){
	int x = find_set(a);
	int y = find_set(b);
	if (f == 0){
		if (x == y){
			if (flag[a] != flag[b]){
				printf("da pian zi\n");
			}
		}else{
			v[x] = y;
			if (flag[a] == flag[b])
				flag[x] = true;
			else
				flag[x] = false;
		}
	}else{
		if (x == y){
			if (flag[a] == flag[b]){
				printf("da pian zi\n");
			}
		}else{
			v[x] = y;
			if (flag[a] == flag[b])
				flag[x] = false;
			else
				flag[x] = true;
		}
	}
}
int main()
{
	int a, b, c;
	while (scanf("%d%d", &n, &m) != EOF){
		for (int i = 1; i <= n; i++){
			make_set(i);
		}
		int x, y;
		for (int i = 0; i < m; i++){
			scanf("%d %d %d", &a, &b, &c);
			if (c == 0){
				union_set(a, b, 0);
			}else if (c == 1){
				union_set(a, b, 1);
			}else{
				x = find_set(a);
				y = find_set(b);
				if (x != y){
					printf("not sure yet\n");
				}else if (flag[a] == flag[b]){
					printf("we are a team\n");
				}else if (flag[a] != flag[b]){
					printf("we are not a team\n");
				}
			}
		}
	}
	return 0;
}
