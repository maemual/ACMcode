/*************************************************************************
	> File Name: h.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年05月04日 星期六 09时25分19秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAX_LEN 100005
int main()
{
	int n;
	int arr[MAX_LEN];
	long long brr[MAX_LEN];
	while (1){
		scanf("%d", &n);
		if (n == 0)
			break;
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		sort(arr,arr+n);
		memset(brr,0,sizeof(brr));
		long long sum = 0;
		brr[0] = arr[0];
		for (int i = 1; i < n; i++){
			brr[i] = brr[i-1] + arr[i];
		}
		for (int i = 0; i < n; i++)
			sum += brr[i];
		double ans = sum * 1.0 / n;
		printf("%.3lf\n",ans);
	}
	return 0;
}
