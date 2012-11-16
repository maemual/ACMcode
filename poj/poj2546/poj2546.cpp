//求两圆的公共面积
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define pi 3.141592653
struct point
{
	double x,y,r;
}p[3];

double dis(point a,point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double calc(point a,point b)
{
	double d=dis(a,b);
	if (d>=a.r+b.r) return 0;
	double r=a.r>b.r?b.r:a.r;
	if (d<=fabs(a.r-b.r)) return pi*r*r;
	double t1=acos((a.r*a.r+d*d-b.r*b.r)/2.0/a.r/d);
	double t2=acos((b.r*b.r+d*d-a.r*a.r)/2.0/b.r/d);
	double t=0;
	t-=d*a.r*sin(t1);
	t+=t1*a.r*a.r+t2*b.r*b.r;
	return t;
}

int main()
{
	while(scanf("%lf%lf%lf%lf%lf%lf",&p[1].x,&p[1].y,&p[1].r,&p[2].x,&p[2].y,&p[2].r)!=EOF)  
	{  
		double ans=calc(p[1],p[2]);  
		printf("%.3lf\n",ans); 
	}  
	return 0;
}
