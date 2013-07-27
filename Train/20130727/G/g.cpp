/*************************************************************************
	> File Name: g.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年07月27日 星期六 11时56分15秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

#define eps 1e-8
#define zero(x) (((x)>0?(x):(-x))<eps)
#define MAX_LEN 30
struct point3{
	double x, y, z;
	point3(){}
	point3(double _x, double _y, double _z):x(_x), y(_y), z(_z){}
};
struct line3{
	point3 a, b;
	line3(){}
	line3(point3 _a, point3 _b):a(_a), b(_b){}
};
struct plane3{
	point3 a, b, c;
	plane3(){}
	plane3(point3 _a, point3 _b, point3 _c):a(_a), b(_b), c(_c){}
};
struct node{
	point3 c, a, b;
	line3 l;
	double r;
}arr[MAX_LEN+5];
int n;

point3 xmult(point3 u, point3 v){
	point3 ret;
	ret.x = u.y * v.z - v.y * u.z;
	ret.y = u.z * v.x - u.x * v.z;
	ret.z = u.x * v.y - u.y * v.x;
	return ret;
}
double dmult(point3 u, point3 v){
	return u.x * v.x + u.y * v.y + u.z * v.z;
}
double dist(point3 p1, point3 p2){
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)+(p1.z-p2.z)*(p1.z-p2.z));
}
point3 subt(point3 u, point3 v){
	point3 ret;
	ret.x = u.x - v.x;
	ret.y = u.y - v.y;
	ret.z = u.z - v.z;
	return ret;
}
point3 pvec(plane3 s){
	return xmult(subt(s.a, s.b), subt(s.b, s.c));
}
double vlen(point3 p){
	return sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
}
double linetoline(line3 u, line3 v){
	point3 n = xmult(subt(u.a, u.b), subt(v.a, v.b));
	return fabs(dmult(subt(u.a, v.a), n)) / vlen(n);
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%d", &n);
		point3 nc;
		for (int i = 0; i < n; i++){
			scanf("%lf %lf %lf", &arr[i].c.x, &arr[i].c.y, &arr[i].c.z);
			scanf("%lf %lf %lf", &arr[i].a.x, &arr[i].a.y, &arr[i].a.z);
			scanf("%lf %lf %lf", &arr[i].b.x, &arr[i].b.y, &arr[i].b.z);
			arr[i].r = dist(arr[i].c, arr[i].a);
			plane3 stmp(arr[i].c, arr[i].a, arr[i].b);
			nc = pvec(stmp);
			line3 ltmp(arr[i].c, subt(arr[i].c, nc));
			arr[i].l = ltmp;
		}
		bool flag = false;
		double mmin = 1e20;
		for (int i = 0; i < n; i++){
			for (int j = i + 1; j < n; j++){
				double d = linetoline(arr[i].l, arr[j].l);
				if (zero(d - arr[i].r - arr[j].r)){
					flag = true;
					break;
				}else{
					double dtmp = d - arr[i].r - arr[j].r;
					if (dtmp < mmin)
						mmin = dtmp;
				}
			}
			if (flag)
				break;
		}
		if (flag)
			printf("Lucky\n");
		else
			printf("%.2lf\n", mmin);
	}
	return 0;
}
