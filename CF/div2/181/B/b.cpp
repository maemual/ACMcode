/*************************************************************************
	> File Name: b.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年04月25日 星期四 23时58分14秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
int arr[50];
int getpar(int x){
	if (arr[x] != x)
		return getpar(arr[x]);
	return arr[x];
}
int main()
{
	int n,m;
	int a,b;
	int para,parb;
	bool flag[50];
	int sum[50];
	memset(flag, true,sizeof(flag));
	memset(sum, 0, sizeof(sum));
	scanf("%d %d", &n, &m);
	for (int i = 0; i < 50; i++)
		arr[i] = i;

	for (int i = 0; i < m; i++){
		scanf("%d %d", &a, &b);
		para = getpar(a);
		//parb = getpar(b);
		arr[b] = para;
		//arr[parb] = para;
	}
	for (int i = 1; i <= n; i++){
		sum[arr[i]]++;
		if (sum[arr[i]] > 3){
			printf("-1\n");
			return 0;
		}
	}
	for (int i = 1; i <= n; i++){
		if (sum[arr[i]] == 1){
			//sum[arr[i]] = 0;
			arr[i] = 0;
		}
	}
	int ans[50][3];
	for (int i = 1; i <= n/3; i++){
		int a = -1;
		for (int j = 1; j <= n; j++){
			if (flag[j] && arr[j] != 0){
				a = j;
				break;
			}
		}
		if (a == -1){
			for (int j = 1; j <= n; j++){
				if (flag[j]){
					a = j;
					break;
				}
			}
			if (a == -1){
				printf("-1\n");
				break;
			}
		}
		int b,c;
		flag[a] = false;
		b = -1;
		c = -1;
		for (int k = 1; k <= n; k++){
			if (flag[k] && arr[k] == arr[a]){
				b = k;
				flag[b] = false;
				break;
			}
		}
		if (b != -1){
			for (int k = 1; k <= n; k++){
				if (flag[k] && arr[k] == arr[a]){
					c = k;
					flag[c] = false;
					break;
				}
			}
			if (c == -1){
				for (int k = 1; k <= n; k++){
					if (flag[k] && arr[k] == 0){
						c = k;
						flag[c] = false;
						break;
					}
				}
			}
		}else{
			for (int k = 1; k <= n; k++){
				if (flag[k] && arr[k] == 0){
					b = k;
					flag[b] = false;
					break;
				}
			}
			for (int k = 1; k <= n; k++){
				if (flag[k] && arr[k] == 0){
					c = k;
					flag[c] = false;
					break;
				}
			}
		}
		if (a == -1 || b == -1 || c == -1){
			printf("-1\n");
			return 0;
		}
		ans[i][0] = a;
		ans[i][1] = b;
		ans[i][2] = c;
		//printf("%d %d %d\n",a,b,c);
	}
	for (int i = 1; i <= n/3; i++){
		printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
	}
	return 0;
}
