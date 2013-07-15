/*************************************************************************
	> File Name: test.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年07月14日 星期日 14时56分08秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int arr[100];
	for (int i = 1; i <= 10; i++)
		arr[i] = i;
	int left = 1, right = 10;
	int mid;
	int x = 1;
	while (left < right){
		mid = (left + right) / 2;
		if (arr[mid] - arr[left] > x)
			right = mid;
		else if (arr[mid] - arr[left] < x)
			left = mid + 1;
		else{
			printf("%d\n", mid + 1);
			return 0;
		}
	}
	mid = (left + right) / 2;
	printf("%d\n", left);
	return 0;
}
