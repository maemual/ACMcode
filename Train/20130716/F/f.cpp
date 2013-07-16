/*************************************************************************
	> File Name: f.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年07月16日 星期二 12时18分09秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<limits.h>
#include<string.h>
using namespace std;

#define MAX_LEN 105
int n;
int mmap[MAX_LEN][MAX_LEN];
int mmin, mmax;
int vmin[MAX_LEN];
int ans;
bool vis[MAX_LEN];

bool dfs(int k){
	if (k == n){
		return true;
	}
	if (vmin[k] - mmin > ans)
		return false;
	int tmax, tmin;
	for (int i = 0; i < n; i++){
		if (!vis[i]){
			tmax = mmax;
			tmin = mmin;
			if (mmap[k][i] > mmax)
				mmax = mmap[k][i];
			if (mmap[k][i] < mmin)
				mmin = mmap[k][i];
			if (mmax - mmin > ans){
				mmax = tmax;
				mmin = tmin;
				continue;
			}
			vis[i] = true;
			if (dfs(k + 1))
				return true;
			vis[i] = false;
			mmax = tmax;
			mmin = tmin;
		}
	}
	return false;
}
int main()
{
	while (scanf("%d", &n) != EOF){
		memset(vmin, INT_MAX, sizeof(vmin));
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				scanf("%d", &mmap[i][j]);
				vmin[i] = min(vmin[i], mmap[i][j]);
			}
		}
		ans = 0;
		while (1){
			mmin = INT_MAX;
			mmax = INT_MIN;
			memset(vis, false, sizeof(vis));
			if (dfs(0))
				break;
			else
				ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
