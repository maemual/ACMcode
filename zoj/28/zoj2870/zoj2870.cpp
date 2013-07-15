/*************************************************************************
	> File Name: zoj2870.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年07月15日 星期一 21时05分59秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x)) < eps)

#define MAX_LEN 105
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
int n;
line aline[MAX_LEN];
double xmult(point p1, point p2, point p0){
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
int intersect_l(line u, line v){
	return zero(xmult(u.a, v.b, v.a) * xmult(v.b, u.b, v.a));
}
double dis(point p1, point p2){
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
bool check(line l){
	if (zero(l.a.x - l.b.x) && zero(l.a.y - l.b.y)) 
		return false;
	for (int k = 0; k < n; k++){
		if (xmult(l.a, l.b, aline[k].a) * xmult(l.a, l.b, aline[k].b) > eps){
			return false;
		}
	}
	return true;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%d", &n);
		for (int i = 0; i < n; i++){
			scanf("%lf %lf %lf %lf", &aline[i].a.x, &aline[i].a.y, &aline[i].b.x, &aline[i].b.y);
		}
		if (n == 1){
			printf("Yes!\n");
			continue;
		}
		bool flag = false;
		line l1;
		for (int i = 0; i < n; i++){
			for (int j = i + 1; j < n; j++){
				l1.a = aline[i].a; l1.b = aline[j].a;
				if (dis(l1.a, l1.b) > eps && check(l1)){
					flag = true;
					break;
				}
				l1.a = aline[i].a; l1.b = aline[j].b;
				if (dis(l1.a, l1.b) > eps && check(l1)){
					flag = true;
					break;
				}
				l1.a = aline[i].b; l1.b = aline[j].a;
				if (dis(l1.a, l1.b) > eps && check(l1)){
					flag = true;
					break;
				}
				l1.a = aline[i].b; l1.b = aline[j].b;
				if (dis(l1.a, l1.b) > eps && check(l1)){
					flag = true;
					break;
				}
			}
			if (flag)
				break;
		}
		if (flag)
			printf("Yes!\n");
		else
			printf("No!\n");
	}
	return 0;
}
