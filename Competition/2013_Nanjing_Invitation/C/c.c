/*************************************************************************
	> File Name: c.c
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年05月29日 星期三 19时38分23秒
 ************************************************************************/

#include<stdio.h>

#define MAX_LEN 64

int num1[MAX_LEN + 5], num2[MAX_LEN + 5];
void doit(int num[], int x){
	int i;
	int tmp = 1;
	x++;
	for (i = 0; i < 63; i++){
		if (tmp > x) break;
		tmp <<= 1;
		num[i] = (x - x % tmp) >> 1;
		if (x % tmp > tmp / 2) num[i] += x % tmp - tmp / 2;
	}
}
int main()
{
	int a,b;
	int i,j;
	while (scanf("%d %d", &a, &b) != EOF){
		for (i = 0; i < MAX_LEN + 5; i++) num1[i] = num2[i] = 0;
		doit(num1, a-1);
		doit(num2, b);

		for (i = 0; i < 63; i++) num2[i] -= num1[i];
		long long ans = 0;
		for (i = 0; i < 63; i++){
			ans += num2[i] / 2;
			num2[i+1] += num2[i] / 2;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
