/*************************************************************************
	> File Name: c.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年07月14日 星期日 12时41分26秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

const int MAX_LEN = 10005;
#define PI acos(-1.0)
#define eps 1e-6
typedef struct TPoint{
	double x, y;
	double angle;
	TPoint operator-(TPoint &a){
		TPoint p1;
		p1.x = x - a.x;
		p1.y = y - a.y;
		return p1;
	}
}TPoint;
struct TCircle{
	double r;
	TPoint centre;
};
struct TTriangle{
	TPoint t[3];
};
TCircle c;
TPoint a[2 * MAX_LEN];
double dis(TPoint p1, TPoint p2){
	TPoint p3;
	p3.x = p2.x - p1.x;
	p3.y = p2.y - p1.y;
	return sqrt(p3.x * p3.x + p3.y * p3.y);
}
double triangleArea(TTriangle t){
	TPoint p1, p2;
	p1 = t.t[1] - t.t[0];
	p2 = t.t[2] - t.t[0];
	return fabs(p1.x * p2.y - p1.y * p2.x) / 2;
}
TCircle circumcircleOfTriangle(TTriangle t){
	TCircle tmp;
	double a, b, c, c1, c2;
	double xA, yA, xB, yB, xC, yC;
	a = dis(t.t[0], t.t[1]);
	b = dis(t.t[1], t.t[2]);
	c = dis(t.t[2], t.t[0]);
	tmp.r = a * b * c / triangleArea(t) / 4;

	xA = t.t[0].x; yA = t.t[0].y;
	xB = t.t[1].x; yB = t.t[1].y;
	xC = t.t[2].x; yC = t.t[2].y;
	c1 = (xA * xA + yA * yA - xB * xB - yB * yB) / 2;
	c2 = (xA * xA + yA * yA - xC * xC - yC * yC) / 2;

	tmp.centre.x = (c1 * (yA - yC) - c2 * (yA - yB)) / 
				((xA - xB) * (yA - yC) - (xA - xC) * (yA - yB));
	tmp.centre.y = (c1 * (xA - xC) - c2 * (xA - xB)) / 
				((yA - yB) * (xA - xC) - (yA - yC) * (xA - xB));
	return tmp;
}
TCircle MinCircle2(int tce, TTriangle ce){
	TCircle tmp;
	if (tce == 0) 
		tmp.r = -2;
	else if (tce == 1){
		tmp.centre = ce.t[0];
		tmp.r = 0;
	}else if (tce == 2){
		tmp.r = dis(ce.t[0], ce.t[1]) / 2;
		tmp.centre.x = (ce.t[0].x + ce.t[1].x) / 2;
		tmp.centre.y = (ce.t[0].y + ce.t[1].y) / 2;
	}else if (tce == 3)
		tmp = circumcircleOfTriangle(ce);
	return tmp;
}
void MinCircle(int t, int tce, TTriangle ce){
	int i, j;
	TPoint tmp;
	c = MinCircle2(tce, ce);
	if (tce == 3) return ;
	for (i = 1; i <= t; i++){
		if (dis(a[i], c.centre) > c.r){
			ce.t[tce] = a[i];
			MinCircle(i - 1, tce + 1, ce);
			tmp = a[i];
			for (j = i; j >= 2; j--){
				a[j] = a[j - 1];
			}
			a[1] = tmp;
		}
	}
}
void run(int n){
	TTriangle ce;
	MinCircle(n, 0, ce);
	return ; 
}
bool cmp(const TPoint &p1, const TPoint &p2){
	if (p1.angle < p2.angle)
		return true;
	return false;
}
int main()
{
	int n, m;
	double angle;
	while (scanf("%d", &n) != EOF){
		for (int i = 1; i <= n; i++)
			scanf("%lf%lf", &a[i].x, &a[i].y);
		run(n);
		for (int i = 1; i <= n; i++){
			a[i].angle = atan2(a[i].y - c.centre.y, a[i].x - c.centre.x);
			//a[n + i] = a[i];
		}
		sort(a + 1, a + n + 1, cmp);
		for (int i = 1; i <= n; i++){
			//a[n + i] = a[i];
			a[n + i].angle = a[i].angle + 2 * PI;
		}
		//printf("%lf %lf %lf\n", c.centre.x, c.centre.y, c.r);
		scanf("%d", &m);
		for (int i = 0; i < m; i++){
			scanf("%lf", &angle);
			double x = angle * 1.0 / 180 * PI;
			int mmax = -1;
			int left = 1, right = 2;
			while (left <= n){
				while (right <= 2 * n && a[right].angle - a[left].angle < x + eps)
					right++;
				mmax = max(mmax, right - left);
				while (left < right && a[right].angle - a[left].angle > x - eps)
					left++;
				mmax = max(mmax, right - left);
			}
			printf("%d\n", mmax);
		}
	}
	return 0;
}
