/*************************************************************************
	> File Name: c.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年03月22日 星期五 00时12分54秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int MAX_LEN = 3*100000+5;
int arr[MAX_LEN];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++)
		scanf("%d",&arr[i]);
	sort(arr+1,arr+n+1);
	long long sum = 0;
	for (int i = 1; i <= n; i++){
		if (arr[i] > i)
			sum += arr[i] - i;
		else
			sum += (long long)(i - arr[i]);
	}
	cout << sum << endl;
	return 0;
}
