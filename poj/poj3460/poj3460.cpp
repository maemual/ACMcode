/*************************************************************************
	> File Name: poj3460.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年03月24日 星期日 15时40分04秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

int n,step;
int book[20];

int h(int arr[]){
	int num = 0;
	for (int i = 0; i < n-1; i++){
		if (arr[i+1] != arr[i]+1)
			num++;
	}
	if (arr[n-1] != n)
		num++;
	return num;
}
void move(int arr[], int left, int mid, int right){
	int temp[20],j = 0;
	for (int i = mid+1; i <= right; i++)
		temp[j++] = arr[i];
	for (int i = left; i <= mid; i++)
		temp[j++] = arr[i];
	for (int i = left, j = 0; i <= right; i++)
		arr[i] = temp[j++];
}
bool dfs(int k){
	int hh = (h(book) + 2) / 3;
	if (hh == 0)
		return true;
	if (k + hh > step)
		return false;
	for (int left = 0; left < n-1; left++){
		for (int mid = left; mid < n-1; mid++){
			for (int right = mid + 1; right < n; right++){
				move(book, left, mid, right);
				if (dfs(k+1))
					return true;
				move(book, left, left+right-mid-1, right);
			}
		}
	}
	return false;
}
int main()
{
	int cas;
	scanf("%d",&cas);

	while (cas--){
		scanf("%d",&n);
		for (int i = 0; i < n; i++)
			scanf("%d", &book[i]);
		
		step = (h(book) + 2) / 3;
		while (step < 5 && !dfs(0)){
			step++;
		}
		if (step > 4)
			printf("5 or more\n");
		else
			printf("%d\n", step);
	}
	return 0;
}
