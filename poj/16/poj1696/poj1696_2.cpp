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
int main()
{
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%d", &n);
		double mmin = 999999999;
		int miny = 0;
		for (int i = 0; i < n; i++){
			scanf("%d %lf %lf", &p[i].index, &p[i].x, &p[i].y);
			flag[i] = true;
			if (p[i].y < mmin){
				mmin = p[i].y;
				miny = i;
			}
		}
		int top = 0;
		st.x = 0;
		st.y = p[miny].y;
		int k;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (flag[j]){
					k = j;
					break;
				}
			}
			for (int j = 0; j < n; j++){
				if (!flag[j] || j == k) continue;
				double ang = xmult(p[k], p[j], st);
				if (ang < 0 || (ang == 0 && dist(st, p[j]) < dist(st, p[k]))){
					k = j;
				}
			}
			flag[k] = false;
			st = p[k];
			ans[top++] = p[k].index;
		}
		printf("%d", top);
		for (int i = 0; i < top; i++)
			printf(" %d", ans[i]);
		printf("\n");
	}
	return 0;
}
