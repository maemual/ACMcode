/*************************************************************************
	> File Name: h.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年07月27日 星期六 10时03分55秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

#define MAX_LEN 300
int n, m;
int arr[MAX_LEN+5][MAX_LEN+5];
bool isOk(int x, int y, int k){
	int tmp1, tmp2;
	for (int i = x; i <= x + k; i++){
		tmp1 = tmp2 = k;
		for (int j = y; j <= y + k; j++){
			if (arr[i][j] != arr[i][j + (tmp1--)])
				return false;
			if (arr[i][j] != arr[i + (tmp2--)][j])
				return false;
		}
	}
	return true;
}
int main()
{
	freopen("in.in", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				scanf("%d", &arr[i][j]);
			}
		}
		int ans = 0;
		bool flag = false;
		for (int k = n; k >= 1; k--){
			for (int i = 0; i < n; i++){
				if (i + k >= n) break;
				for (int j = 0; j < m; j++){
					if (j + k >= m) break;
					if (isOk(i, j, k)){
						ans = k;
						flag = true;
						break;
					}
				}
				if (flag)
					break;
			}
			if (flag)
				break;
		}
		if (!flag)
			printf("1\n");
		else
			printf("%d\n", ans + 1);
	}
	return 0;
}
	
