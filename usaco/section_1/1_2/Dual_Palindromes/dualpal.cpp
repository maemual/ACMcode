/*
ID: maemual
PROB: dualpal
LANG: C++
*/

#include<iostream>
#include<cstdio>
using namespace std;

#define MAX_LEN 200
int arr[MAX_LEN];
int split(int x, int base){
	int num = 0;
	while (1){
		arr[num++] = x % base;
		if ((x / base) == 0)
			break;
		x /= base;
	}
	return num;
}
bool isPal(int n){
	for (int i = 0; i < n; i++){
		if (arr[i] != arr[n - i - 1])
			return false;
	}
	return true;
}
bool isOk(int x){
	int tmp = x;
	int n;
	int cnt = 0;
	for (int base = 2; base <= 10; base++){
		n = split(x, base);
		if (isPal(n)){
			cnt++;
		}
		if (cnt == 2){
			return true;
		}
	}
	return false;
}
int main()
{
	freopen("dualpal.in", "r", stdin);
	freopen("dualpal.out", "w", stdout);
	int n, s;
	scanf("%d %d", &n, &s);
	while (n){
		s++;
		if (isOk(s)){
			printf("%d\n", s);
			n--;
		}
	}
	return 0;
}
