/*************************************************************************
	> File Name: d.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年07月18日 星期四 09时43分07秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;

#define MAX_LEN 505

bool flag[MAX_LEN][MAX_LEN];
int main()
{
	int n, m;
	int T;
	scanf("%d", &T);
	int start[MAX_LEN], end[MAX_LEN];
	while (T--){
		scanf("%d %d", &n, &m);
		memset(flag, false, sizeof(flag));
		for (int i = 0; i < m; i++){
			scanf("%d", &start[i]);
		}
		for (int i = 0; i < m; i++){
			scanf("%d", &end[i]);
		}
		for (int i = 0; i < m; i++){
			flag[start[i]][end[i]] = true;
			flag[end[i]][start[i]] = true;
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (flag[i][j])
					cnt++;
			}
		}
		printf("%.3lf\n", cnt / 2.0 / n);
	}
	return 0;
}
