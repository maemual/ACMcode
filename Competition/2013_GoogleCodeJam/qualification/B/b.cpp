/*************************************************************************
	> File Name: b.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年04月13日 星期六 16时23分06秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;

#define MAX_LEN 105
int main()
{
	int cas;
	int n,m;
	int map[MAX_LEN][MAX_LEN];
	int map2[MAX_LEN][MAX_LEN];
	int row[MAX_LEN],col[MAX_LEN];
	//freopen("in.in", "r", stdin);
	scanf("%d",&cas);
	for (int k = 1; k <= cas; k++){
		scanf("%d %d", &n, &m);
		int mmax = 0;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				scanf("%d",&map[i][j]);
				map2[i][j] = 1000;
				if (mmax < map[i][j])
					mmax = map[i][j];
			}
		}
		if (n == 1 || m == 1){
			printf("Case #%d: YES\n", k);
			continue;
		}
		for (int i = 1; i <= n; i++)
			row[i] = 0;
		for (int j = 1; j <= m; j++)
			col[j] = 0;
		bool flag;
		for (int p = mmax; p >= 1; p--){
			for (int i = 1; i <= n; i++){
				if (p < row[i])
					continue;
				for (int j = 1; j <= m; j++){
					if (map2[i][j] > p){
						map2[i][j] = p;
						if (map2[i][j] == map[i][j]){
							row[i] = max(row[i],p);
							col[j] = max(col[j],p);
						}
					}
				}
			}
			for (int i = 1; i <= m; i++){
				if (p < col[i])
					continue;
				for (int j = 1; j <= n; j++){
					if (map2[j][i] > p){
						map2[j][i] = p;
						if (map2[j][i] == map[j][i]){
							row[j] = max(row[j],p);
							col[i] = max(col[i],p);
						}
					}
				}
			}
		}
		flag = false;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				if (map[i][j] != map2[i][j]){
					flag = true;
					break;
				}
			}
			if (flag)
				break;
		}
		if (flag)
			printf("Case #%d: NO\n", k);
		else
			printf("Case #%d: YES\n", k);
	}
	return 0;
}
