/*************************************************************************
	> File Name: a.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年07月04日 星期四 20时31分50秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int arr[105];
	int sum11 = 0;
	for (int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
		if (arr[i] == 1)
			sum11++;
	}
	if (sum11 == n){
		printf("%d\n", n - 1);
		return 0;
	}
	int mmax = -99999999;
	for (int i = 0; i < n; i++){
		int sum0 = 0;
		int sum1 = 0;
		int max = -999999;
		if (arr[i] == 0){
			for (int j = i; j < n; j++){
				if (arr[j] == 0)
					sum0++;
				else
					sum1++;
				if (sum0 - sum1 > max)
					max = sum0 - sum1;
			}
		}
		if (max > mmax)
			mmax = max;
	}
	printf("%d\n", sum11 + mmax);
	return 0;
}
