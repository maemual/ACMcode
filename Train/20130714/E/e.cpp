/*************************************************************************
	> File Name: e.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年07月14日 星期日 20时46分54秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;

#define MAX_N 505
#define MOD 100000007
struct Mat{
	long long mat[MAX_N][MAX_N];
};
int n;
long long m;
Mat tmp;
Mat operator*(const Mat &a, const Mat &b){
	Mat c;
	memset(c.mat, 0, sizeof(c.mat));
	for (int k = 0; k < n; k++){
		if (a.mat[0][k]){
			for (int j = 0; j < n; j++){
				c.mat[0][j] += a.mat[0][k] * b.mat[k][j];
				if (c.mat[0][j] >= MOD)
					c.mat[0][j] %= MOD;
			}
		}
	}
	for (int i = 1; i < n; i++){
		for (int j = 0; j < n; j++){
			c.mat[i][j] = c.mat[i - 1][(j - 1 + n) % n];
		}
	}
	return c;
}
Mat operator^(Mat a, long long k){
	Mat c;
	int i, j;
	if (k == 1){
		return a;
	}
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			c.mat[i][j] = (i == j);

	for (; k; k >>= 1){
		if (k & 1)
			c = c * a;
		a = a * a;
	}
	return c;
}
int main()
{
	long long k;
	long long f[MAX_N];
	while (scanf("%d %lld", &n, &m) != EOF){
		for (int i = 0; i < n; i++)
			scanf("%lld", &f[i]);
		if (m <= n){
			printf("%lld\n", f[m - 1]);
			continue;
		}
		int l, r;
		for (int i = 0; i < n; i++){
			//tmp.mat[i][(i+1) % n] = tmp.mat[i][(i + 4) % n] = 1; 
			l=(i-1)<0?(n-1):(i-1);
			r=(i+1)>(n-1)?0:(i+1);
			tmp.mat[i][l]=tmp.mat[i][r]=1;
		}
		if (m % n == 0){
			k = n - 1;
			tmp = tmp ^ ((long long)m / n - 1);
		}else{
			k = m % n - 1;
			tmp = tmp ^ ((long long)m / n);
		}
		long long ans[MAX_N];
		memset(ans, 0, sizeof(ans));
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				ans[i] += tmp.mat[i][j] * f[j];
				if (ans[i] >= MOD)
					ans[i] %= MOD;
			}
		}
		printf("%lld\n", ans[k]);
	}
	return 0;
}
