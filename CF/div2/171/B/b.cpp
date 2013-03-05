/*************************************************************************
	> File Name: b.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年03月05日 星期二 00时20分17秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

const int MAX_LEN = 100005;
long long arr[MAX_LEN*2],asum[MAX_LEN*2];
int main()
{
	int n,t;
	cin >> n >> t;
	long long sum = 0;
	arr[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		sum += arr[i];
		asum[i] = sum;
	}
	int left,right,mid;
	int max = 0;
	for (int i = 1; i <= n; i++)
	{
		if (arr[i] > t)
			continue;
	
		left = i + 1;
		right = n;
		while (left <= right)
		{
			mid = (left + right) / 2;
			if (asum[mid] - asum[i-1] == t)
			{
				left = mid + 1;
				break;
			}
			if (asum[mid] - asum[i-1] > t)
				right = mid - 1;
			else
				left = mid + 1;
		}
		if (left - i > max)
			max = left - i;
		//arr[i+n] = arr[i];
		//asum[i+n] = asum[i+n-1] + arr[i];
	}
	cout << max << endl;
	return 0;	
}
