#include <queue>
#include <stack>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <limits.h>
#include <string.h>
#include <string>
#include <algorithm>

using namespace std;

const int MAX = 1510;
struct point{ double x,y;};
point p[MAX],s[MAX];
const double eps = 1e-6;
bool dy(double x,double y)	{	return x > y + eps;}	// x > y 
bool xy(double x,double y)	{	return x < y - eps;}	// x < y 
bool dyd(double x,double y)	{ 	return x > y - eps;}	// x >= y 
bool xyd(double x,double y)	{	return x < y + eps;} 	// x <= y 
bool dd(double x,double y) 	{	return fabs( x - y ) < eps;}  // x == y
double xmult(point a,point b,point c)//向量 ac 在 ab 的方向
{
	return (c.x - a.x)*(b.y - a.y) - (b.x - a.x)*(c.y - a.y);
}
point intersection(point u1,point u2,point v1,point v2)
{
	point ans = u1;
	double t = ((u1.x - v1.x)*(v1.y - v2.y) - (u1.y - v1.y)*(v1.x - v2.x))/
				((u1.x - u2.x)*(v1.y - v2.y) - (u1.y - u2.y)*(v1.x - v2.x));
	ans.x += (u2.x - u1.x)*t;
	ans.y += (u2.y - u1.y)*t;
	return ans;
}
void change_wise(point p[],int n)
{
	for(int i=0; i<n/2; i++)
		swap(p[i],p[n-i-1]);
}
void inst_hp(point p[],int n,point s[],int &len)
{
	point tp[MAX];
	p[n] = p[0];
	for(int i=0; i<=n; i++)
		tp[i] = p[i];
	int cp = n,tc;
	for(int i=0; i<n; i++)
	{
		tc = 0;
		for(int k=0; k<cp; k++)
		{
			if( xyd(xmult(p[i],p[i+1],tp[k]),0.0) )// 顺时针的话是dyd
				s[tc++] = tp[k];
			if( xy(xmult(p[i],p[i+1],tp[k])*
					xmult(p[i],p[i+1],tp[k+1]),0.0) )
				s[tc++] = intersection(p[i],p[i+1],tp[k],tp[k+1]);
		}
		s[tc] = s[0];
		for(int k=0; k<=tc; k++)
			tp[k] = s[k];
		cp = tc;
	}
	len = cp;
}
double area_polygon(point p[],int n)
{
	double s = 0.0;
	for(int i=0; i<n; i++)
		s += p[(i+1)%n].y * p[i].x - p[(i+1)%n].x * p[i].y;
	return s/2.0;
}
int main()
{
	int len,T,n;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=0; i<n; i++)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		double area = area_polygon(p,n);
		if(xyd(area,0.0)) change_wise(p,n);
		inst_hp(p,n,s,len);
		double ans = area_polygon(s,len);
		printf("%.2lf\n",fabs(ans));
	}
    return 0;
}
