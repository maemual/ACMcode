/*************************************************************************
	> File Name: j.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年07月18日 星期四 09时13分04秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

#define MAX_LEN 200
int n, m;
int arr[MAX_LEN * 2 + 5];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++){
			scanf("%d", &arr[i]);
			arr[i + n] = arr[i];
		}
		int sum = 0;
		int mmax = -1;
		for (int i = 0; i < m; i++){
			sum += arr[i];
		}
		mmax = sum;
		for (int i = 1; i < n; i++){
			sum -= arr[i-1];
			sum += arr[i - 1 + m];
			if (sum > mmax)
				mmax = sum;
		}
		printf("%d\n", mmax);
	}
	return 0;
}
