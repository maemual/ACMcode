/*************************************************************************
	> File Name: f.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年07月18日 星期四 10时14分17秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;

#define MAX_LEN 105
int mmap[MAX_LEN][MAX_LEN];
int main()
{
	int n, m, k;
	int T;
	scanf("%d", &T);
	int x, y;
	while (T--){
		scanf("%d %d %d", &n, &m, &k);
		memset(mmap, 0, sizeof(mmap));
		for (int i = 0; i < m; i++){
			scanf("%d %d", &x, &y);
			mmap[x][y] = mmap[y][x] = 1;
		}
		int cnt = 0;
		bool flag = true;
		int ans = 0;
		while (flag){
			flag = false;
			for (int i = 0; i < n; i++){
				for (int j = i + 1; j < n; j++){
					if (mmap[i][j] == 1) continue;
					cnt = 0;
					for (int p = 0; p < n; p++){
						if (mmap[i][p] && mmap[j][p])
							cnt++;
					}
					if (cnt >= k){
						mmap[i][j] = 1;
						mmap[j][i] = 1;
						ans++;
						flag = true;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
