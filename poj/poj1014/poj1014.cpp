/*************************************************************************
	> File Name: poj1014.c
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年04月24日 星期三 18时08分33秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define MAX_INT 0x3f3f3f3f
int f[120000];
int a[10];
int sum;
void zeroOnePack(int cw){
	int v;
	for (v = sum; v >= cw; v--)
		f[v] = max(f[v], f[v-cw]+cw);
}
void completePack(int cw){
	int v;
	for (v = cw; v <= sum; v++)
		f[v] = max(f[v], f[v-cw]+cw);
}
void multiplePack(int cw, int amount){
	if (cw*amount > sum){
		completePack(cw);
		return ;
	}
	int k = 1;
	while (k < amount){
		zeroOnePack(k*cw);
		amount -= k;
		k *= 2;
	}
	zeroOnePack(amount*cw);
}
int main()
{
	int i,v;
	int k;
	for (k = 1; ;k++){
		sum = 0;
		for (i = 1; i <= 6; i++){
			scanf("%d", &a[i]);
			sum += i*a[i];
		}
		if (sum == 0)
			break;
		printf("Collection #%d:\n",k);
		if (sum % 2 == 1){
			printf("Can't be divided.\n\n");
			continue;
		}
		sum /= 2;
		f[0] = 0;
		for (i = 1; i <= sum; i++)
			f[i] = -MAX_INT;
		for (i = 1; i < 7; i++)
			multiplePack(i,a[i]);
		if (f[sum] != sum)
			printf("Can't be divided.\n\n");
		else
			printf("Can be divided.\n\n");
	}
	return 0;
}
