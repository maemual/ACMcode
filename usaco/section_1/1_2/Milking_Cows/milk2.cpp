/*
 ID: maemual
PROB: milk2
LANG: C++
*/

#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;

#define MAX_LEN 1000000
bool t[MAX_LEN + 5];

int main()
{
	freopen("milk2.in", "r", stdin);
	freopen("milk2.out", "w", stdout);
	int n;
	scanf("%d", &n);
	int s, e;
	memset(t, false, sizeof(t));
	int maxe = 0, mins = 9999999;
	for (int i = 0; i < n; i++){
		scanf("%d %d", &s, &e);
		if (mins > s) mins = s;
		if (maxe < e) maxe = e;
		for (int j = s; j < e; j++)
			t[j] = true;
	}
	int mmax1 = 0;
	int mmax2 = 0;
	int left = mins, right = mins;
	while (left < maxe){
		if (t[left] == true){
			while (right <= maxe && t[right] == t[left]) right++;
			//if (right > maxe) right--;
			if (mmax1 < right - left) mmax1 = right - left;
			left = right;
		}else{
			while (right <= maxe && t[right] == t[left]) right++;
			//if (right > maxe) right--;
			if (mmax2 < right - left) mmax2 = right - left;
			left = right;
		}
	}
	printf("%d %d\n", mmax1, mmax2);
	return 0;
}
