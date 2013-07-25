/*************************************************************************
	> File Name: poj1696.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年07月25日 星期四 19时31分37秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;

#define eps 1e-8
#define MAX_LEN 55
#define delt(a) fabs(a)<eps?0:(a)>0?1:-1

struct point{
	double x, y;
	int index;
	point(){}
	point(double _x, double _y):x(_x), y(_y){}
}p[MAX_LEN], st, tmp;
int n;
int top;
int ans[MAX_LEN];
bool flag[MAX_LEN];

int xmult(const point &p1, const point &p2, const point &p0){
	return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}
double dist(const point &p1, const point &p2){
	return sqrt((p1.x - p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
bool ncmp(const point &a, const point &b){
	int d1 = delt(xmult(a, b, st));
	return d1 > 0 || (d1 == 0 && dist(st, a) > dist(st, b));
}
bool cmpx(const point &a, const point &b){
	return a.y < b.y;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%d", &n);
		for (int i = 0; i < n; i++){
			scanf("%d %lf %lf", &p[i].index, &p[i].x, &p[i].y);
		}
		sort(p, p + n, cmpx);
		st = p[0];
		printf("%d %d", n, p[0].index);
		for (int i = 1; i < n; i++){
			sort(p + i, p + n, ncmp);
			st = p[i];
			printf(" %d", p[i].index);
		}
		printf("\n");
	}
	return 0;
}
