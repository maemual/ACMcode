/*************************************************************************
	> File Name: poj1673.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年07月10日 星期三 14时28分51秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;

#define PI acos(-1.0)
struct Point{
	double x, y;
	double angle, dis;
	Point(){}
	Point(double _x, double _y):x(_x), y(_y){}
};
struct Line{
	Point p1, p2;
	Line() {}
	Line(Point _p1, Point _p2):p1(_p1), p2(_p2){}
};
Point operator+(Point p1, Point p2){
	return Point(p1.x + p2.x, p1.y + p2.y);
}
Point operator-(Point p1, Point p2){
	return Point(p1.x - p2.x, p1.y - p2.y);
}
Point Rotate(Point p, double angle){
	Point res;
	res.x = p.x * cos(angle) - p.y * sin(angle);
	res.y = p.x * sin(angle) + p.y * cos(angle);
	return res;
}
Point intersection(Line u, Line v){
	Point ret = u.p1;
	double t = ((u.p1.x-v.p1.x)*(v.p1.y-v.p2.y)-(u.p1.y-v.p1.y)*(v.p1.x-v.p2.x))
				/ ((u.p1.x-u.p2.x)*(v.p1.y-v.p2.y)-(u.p1.y-u.p2.y)*(v.p1.x-v.p2.x));
	ret.x += (u.p2.x - u.p1.x) * t;
	ret.y += (u.p2.y - u.p1.y) * t;
	return ret;
}
int main()
{
	int T;
	scanf("%d", &T);
	Point a,b,c;
	while (T--){
		scanf("%lf %lf", &a.x, &a.y);
		scanf("%lf %lf", &b.x, &b.y);
		scanf("%lf %lf", &c.x, &c.y);
		Point ab = b - a;
		Point ba = a - b;
		Point ac = c - a;
		Point bc = c - b;
		Point d = Rotate(ab, PI / 2) + a;
		Point e = Rotate(ba, -PI /2) + b;
		Point g = Rotate(ac, -PI /2) + a;
		Point j = Rotate(bc, PI / 2) + b;
		Point l((d.x+g.x)/2, (d.y+g.y)/2);
		Point h((e.x+j.x)/2, (e.y+j.y)/2);
		Line L1(l, a), L2(h, b);
		Point center = intersection(L1, L2);
		printf("%.4f %.4f\n", center.x, center.y);
	}
	return 0;
}
