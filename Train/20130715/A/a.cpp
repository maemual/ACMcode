/*************************************************************************
	> File Name: a2.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年07月15日 星期一 16时52分17秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

#define MAX_LEN 50000
#define eps 1e-8
#define zero(x) (((x>0)?(x):-(x)) < eps)
#define delt(a) fabs(a)<eps?0:a>0?1:-1

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
point lis[MAX_LEN], add[MAX_LEN], cov[MAX_LEN], st;
line aline[MAX_LEN];
int n, m, k, top;
double xmult(point p1, point p2, point p0){
	return (p1.x - p0.x)*(p2.y - p0.y)-(p2.x - p0.x)*(p1.y - p0.y);
}
double dist(point p1, point p2){
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
int opposite_side(point p1, point p2, line l){
	return xmult(l.a, p1, l.b)*xmult(l.a, p2, l.b) < -eps;
}
int intersect_ex(line u, line v){
	return opposite_side(u.a, u.b, v) && opposite_side(v.a, v.b, u);
}
point intersection(line u, line v){
	point ret = u.a;
	double t = ((u.a.x-v.a.x)*(v.a.y-v.b.y)-(u.a.y-v.a.y)*(v.a.x-v.b.x))
			/ ((u.a.x-u.b.x)*(v.a.y-v.b.y)-(u.a.y-u.b.y)*(v.a.x-v.b.x));
	ret.x += (u.b.x-u.a.x)*t;
	ret.y += (u.b.y-u.a.y)*t;
	return ret;
}
double area_polygon(int n, point p[]){
	double s1 = 0, s2 = 0;
	for (int i = 0; i < n; i++){
		s1 += p[(i+1)%n].y*p[i].x;
		s2 += p[(i+1)%n].y*p[(i+2)%n].x;
	}
	return fabs(s1-s2) / 2;
}
bool ncmp(const point &a, const point &b){
	int d1 = delt(xmult(a, b, st));
	return d1 > 0 || (d1 == 0 && dist(st, a) < dist(st, b));
}
bool cmpx(const point &a, const point &b){
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}
void graham(){
	int i;
	sort(cov, cov + n, cmpx);
	st = cov[0];
	sort(cov, cov + n, ncmp);
	for (i = 2, top = 2; i < n; i++){
		while (top > 1 && xmult(cov[top-1], cov[i], cov[top-2]) <= 0) top--;
		cov[top++] = cov[i];
	}
	cov[top] = cov[0];
}
bool not_in(point px){
	for (int i = 0; i < n; i++){
		if (zero(lis[i].x - px.x) && zero(lis[i].y - px.y))
			return false;
	}
	for (int i = 0; i < m; i++){
		if (zero(add[i].x - px.x) && zero(add[i].y - px.y))
			return false;
	}
	return true;
}
int main()
{
	while (scanf("%d", &n) != EOF){
		for (int i = 0; i < n; i++){
			scanf("%lf %lf", &lis[i].x, &lis[i].y);
			cov[i] = lis[i];
		}
		if (n < 3){
			printf("0 0\n");
			continue;
		}
		k = 0;
		for (int i = 0; i < n; i++){
			for (int j = i + 1; j < n; j++){
				aline[k].a = lis[i];
				aline[k++].b = lis[j];
			}
		}
		m = 0;
		for (int i = 0; i < k; i++){
			for (int j = i + 1; j < k; j++){
				if (intersect_ex(aline[i], aline[j])){
					point tmp = intersection(aline[i], aline[j]);
					if (not_in(tmp)){
						add[m++] = tmp;
					}
				}
			}
		}
		printf("%d ", m);
		graham();
		double ans = area_polygon(top + 1, cov);
		long long ans2 = (long long)ans;
		if (zero(ans - ans2)){
			printf("%lld\n", ans2);
		}else{
			printf("%lld\n", ans2 * 2 + 1);
		}
	}
	return 0;
}
