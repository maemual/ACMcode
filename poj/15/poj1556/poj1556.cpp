/*************************************************************************
	> File Name: poj1556.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年07月16日 星期二 17时44分50秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

#define eps 1e-8
#define MAX_LEN 1005
int n;
struct point{
	double x, y;
	point(){}
	point(double _x, double _y):x(_x), y(_y){}
};
struct line{
	point a, b;
	line(){}
	line(point p1, point p2):a(p1), b(p2){}
};
point p[MAX_LEN];
line aline[MAX_LEN];
int main()
{
	double x, a, b, c, d;
	int k, m;
	while (1){
		scanf("%d", &n);
		if (n == -1)
			break;
		k = 0;
		m = 0;
		point pt;
		for (int i = 0; i < n; i++){
			scanf("%lf%lf%lf%lf%lf", &x, &a, &b, &c, &d);
			p[k].x = p[k+1].x = p[k+2].x = p[k+3].x = x;
			p[k].y = a;
			p[k+1].y = b;
			p[k+2].y = c;
			p[k+3].y = d;
			pt.x = x; pt.y = 0;
			aline[m].a = pt; aline[m++].b = p[k];
			aline[m].a = p[k+1]; aline[m++].b = p[k+2];
			pt.y = 10;
			aline[m].a = p[k+3]; aline[m++].b = pt;
		}

	}
	return 0;
}
