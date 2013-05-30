/*************************************************************************
	> File Name: k.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年05月30日 星期四 10时21分04秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

#define MAX_LEN 1000
int X[MAX_LEN + 5], Y[MAX_LEN + 5], Z[MAX_LEN + 5];
int gcd(int a, int b){
	return !b?a:gcd(b, a % b);
}
bool check2(int d, int l, int r){
	if (l % d == 0 || r % d == 0)
		return true;
	if (r - l + 1 >= d) 
		return true;
	int tmp1 = l / d;
	int tmp2 = r / d;
	if (tmp1 != tmp2) 
		return true;
	else 
		return false;
}
bool check(int i, int j){
	if (Y[i] > Z[j] || Y[j] > Z[i]){
		if (Z[i] < Y[j]) swap(i, j);
		int d = gcd(X[i], X[j]);
		if (check2(d, Y[i] - Z[j], Z[i] - Y[j])) 
			return true;
		else
			return false;
	}
	return true;
}
int main()
{
	int n;
	while (scanf("%d", &n) != EOF){
		for (int i = 0; i < n; i++)
			scanf("%d %d %d", &X[i], &Y[i], &Z[i]);

		bool flag = true;
		for (int i = 0; i < n; i++){
			for (int j = i+1; j < n; j++){
				if (check(i, j)){
					flag = false;
					break;
				}
			}
		}
		if (flag)
			printf("Can Take off\n");
		else
			printf("Cannot Take off\n");
	}
	return 0;
}
