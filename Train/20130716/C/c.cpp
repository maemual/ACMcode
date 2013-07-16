/*************************************************************************
	> File Name: c.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年07月16日 星期二 09时08分13秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

#define MAX_LEN 100000
int arr[MAX_LEN];
int main()
{
	int T;
	int a, b;
	scanf("%d", &T);
	int k;
	while (T--){
		scanf("%d %d", &a, &b);
		if (a == b){
			printf("0\n");
			continue;
		}
		k = 0;
		bool flag = true;
		while (a){
			if (flag){
				if (a / 3 * 3 > a)
					a = a / 3 - 1;
				else
					a /= 3;
				arr[k++] = 3;
				flag = false;
			}else{
				a *= -2;
				arr[k++] = 1;
				flag = true;
			}
		}
		int ans[MAX_LEN];
		int p = 0;
		while (b){
			if (b % (-2) == 0){
				b /= -2;
				ans[p++] = 1;
			}else{
				b = (b - 1) / (-2);
				ans[p++] = 2;
			}
		}
		for (int i = p - 1; i >= 0; i--)
			arr[k++] = ans[i];
		printf("%d\n", k);
		for (int i = 0; i < k; i++)
			printf("%d\n", arr[i]);
	}
	return 0;
}
