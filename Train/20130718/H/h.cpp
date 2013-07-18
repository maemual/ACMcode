/*************************************************************************
	> File Name: h.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年07月18日 星期四 09时27分01秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int T;
	int a, b, c;
	scanf("%d", &T);
	while (T--){
		scanf("%d %d %d", &a, &b, &c);
		int total = a + b + c;
		int mmax = 0;
		int mmin = 0;
		int k = 0;
		for (int i = 0; i < a; i++){
			mmin += 300 * (k * 2 + 1);
			k++;
		}
		for (int i = 0; i < b; i++){
			mmin += 100 * (k * 2 + 1);
			k++;
		}
		for (int i = 0; i < c; i++){
			mmin += 50 * (k * 2 + 1);
			k++;
		}
		k = 0;
		for (int i = 0; i < c; i++){
			mmax += 50 * (k * 2 + 1);
			k++;
		}
		for (int i = 0; i < b; i++){
			mmax += 100 * (k * 2 + 1);
			k++;
		}
		for (int i = 0; i < a; i++){
			mmax += 300 * (k * 2 + 1);
			k++;
		}
		printf("%d %d\n", mmin, mmax);
	}
	return 0;
}
