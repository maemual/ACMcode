/*************************************************************************
	> File Name: b.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年04月02日 星期二 23时55分51秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

const int MAX_LEN = 100;
int arr[MAX_LEN * MAX_LEN + 5];
int main()
{
	int n,m,d;
	scanf("%d %d %d",&n,&m,&d);
	int num = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d",&arr[num++]);
	sort(arr,arr+num);
	for (int i = 0; i < num-1; i++){
		if ((arr[i+1] - arr[i]) % d != 0){
			printf("-1\n");
			return 0;
		}
	}
	int ans = 0;
	int ans1 = 0;
	int ans2 = 0;
	if (num % 2 == 0){
		for (int i = 0; i < num; i++){
			ans1 += abs(arr[i] - arr[num / 2]) / d;
		}
		for (int i = 0; i < num; i++){
			ans2 += abs(arr[i] - arr[num / 2 - 1]) / d;
		}
		ans = ans1>ans2?ans1:ans2;
	}else{
		for (int i = 0; i < num; i++){
			ans += abs(arr[i] - arr[num / 2]) / d;
		}
	}
	printf("%d\n",ans);
	return 0;
}
