/*************************************************************************
	> File Name: a.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年03月21日 星期四 23时23分30秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;

const int MAX_LEN = 100005;
int arr[MAX_LEN];
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	/*
	int p = 0;
	for (p = 1; p <= n - 2 * k; p++)
		printf("%d ",p);
	for (int i = p; i < n; i += 2){
		printf("%d %d ",i+1,i);
	}
	printf("\n");
	*/
	for (int i = 1; i <= n; i++)
		arr[i] = i;
	int tmp;
	for (int i = n - k,j = n; i <= j; i++,j--){
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
	for (int i = 1; i < n; i++)
		printf("%d ",arr[i]);
	printf("%d\n",arr[n]);
	return 0;
}
