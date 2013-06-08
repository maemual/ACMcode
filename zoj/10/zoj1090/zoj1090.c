#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793

typedef struct{
	double x,y;
}point;
typedef struct{
	point a,b;
}line;
double distance(point p1,point p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
point intersection(line u,line v)//求两直线交点
{
	point ret = u.a;
	double t = ((u.a.x-v.a.x)*(v.a.y-v.b.y)-(u.a.y-v.a.y)*(v.a.x-v.b.x))
			  /((u.a.x-u.b.x)*(v.a.y-v.b.y)-(u.a.y-u.b.y)*(v.a.x-v.b.x));
	ret.x += (u.b.x-u.a.x)*t;
	ret.y += (u.b.y-u.a.y)*t;
	return ret;
}
point circumcenter(point a,point b,point c)//求不共线三点的外心
{
	line u,v;
	u.a.x = (a.x+b.x) / 2;
	u.a.y = (a.y+b.y) / 2;
	u.b.x = u.a.x-a.y+b.y;
	u.b.y = u.a.y+a.x-b.x;
	v.a.x = (a.x+c.x) / 2;
	v.a.y = (a.y+c.y) / 2;
	v.b.x = v.a.x-a.y+c.y;
	v.b.y = v.a.y+a.x-c.x;
	return intersection(u,v);
}
int main()
{
	point a,b,c;
	point center;
	double r;
	while (scanf("%lf %lf %lf %lf %lf %lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y) != EOF)
	{
		center = circumcenter(a,b,c);
		r = distance(center,a);
		printf("%.2lf\n",2*PI*r);
	}
	return 0;
}
