/*************************************************************************
	> File Name: g.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年07月16日 星期二 09时51分12秒
 ************************************************************************/

//成功找到模版。。。。
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

#define PI acos(-1.0)
#define eps 1e-10
template<class _Ty> _Ty sqr(const _Ty &a){
	return a * a;
}
template<class _Ty> _Ty abs(const _Ty &a){
	return a >= 0 ? a : -a;
}
double dist(double x, double y){
	return sqr(x) + sqr(y);
}
double ArcArea(double lx, double ly, double x, double y, double r){
	double ang = abs(atan2(lx, ly) - atan2(x, y));
	if (ang > PI) ang = 2 * PI - ang;
	return r * r * ang / 2;
}
double Addition(double lx, double ly, double x, double y, double r){
	double area = 0;
	bool sign;
	if (x * ly - y * lx < 0)
		sign = false;
	else
		sign = true;
	if (dist(x, y) > dist(lx, ly)){
		double tx = x, ty = y;
		x = lx, y = ly;
		lx = tx, ly = ty;
	}
	double dx = lx - x, dy = ly - y;
	double a = sqr(dx) + sqr(dy), b = 2 * (x * dx + y * dy), c = sqr(x) + sqr(y) - sqr(r);
	double dt = b * b - 4 * a * c;
	if (dt <= 0)
		area += ArcArea(lx, ly, x, y, r);
	else{
		dt = sqrt(dt);
		double k1 = (-b - dt) / (a * 2), k2 = (-b + dt) / (a * 2);
		if (k2 <= 0 || k1 >= 1)
			area += ArcArea(lx, ly, x, y, r);
		else if (k1 <= 0 && k2 >= 1)
			area += abs(x * ly - y * lx) / 2;
		else if (k1 <= 0){
			double mx = x + dx * k2, my = y + dy * k2;
			area += abs(x * my - y * mx) / 2;
			area += ArcArea(mx, my, lx, ly, r);
		}else{
			double x1 = x + dx * k1, y1 = y + dy * k1, x2 = x + dx * k2, y2 = y + dy * k2;
			area += ArcArea(x, y, x1, y1, r);
			area += ArcArea(x2, y2, lx, ly, r);
			area += abs(x1 * y2 - x2 * y1) / 2;
		}
	}
	if (!sign) return -area;
	else return area;
}
int main()
{
	double r1, r2;
	int n;
	while (scanf("%d%lf", &n, &r1) != EOF){
		double area1 = 0;
		double pos[105][2];
		for (int i = 0; i < n; i++){
			scanf("%lf%lf", &pos[i][0], &pos[i][1]);
		}
		for (int i = 1; i < n; i++)
			area1 += Addition(pos[i-1][0], pos[i-1][1], pos[i][0], pos[i][1], r1);
		area1 += Addition(pos[n-1][0], pos[n-1][1], pos[0][0], pos[0][1], r1);
		printf("%.9lf\n", abs(area1));
	}
}
