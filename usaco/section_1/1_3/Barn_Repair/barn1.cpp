/*
ID: maemual
PROB: barn1
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

#define MAX_LEN 205
int arr[MAX_LEN];
int m, s, c;
int main()
{
	freopen("barn1.in", "r", stdin);
	freopen("barn1.out", "w", stdout);
	scanf("%d %d %d", &m, &s, &c);
	for (int i = 0; i < c; i++)
		scanf("%d", &arr[i]);
	if (m >= c){
		printf("%d\n", c);
		return 0;
	}
	sort(arr, arr + c);
	int ans = arr[c - 1] - arr[0] + 1;
	for (int i = 0; i < c - 1; i++){
		arr[i] = arr[i + 1] - arr[i] - 1;
	}
	sort(arr, arr + c - 1, greater<int>());
	for (int i = 0; i < m - 1; i++)
		ans -= arr[i];
	printf("%d\n", ans);
	return 0;
}
