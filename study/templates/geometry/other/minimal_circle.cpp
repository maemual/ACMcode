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

const int MAX = 110;
struct point{ double x,y;};
point p[MAX];
const double eps = 1e-6;
bool dy(double x,double y)	{	return x > y + eps;}	// x > y
bool xy(double x,double y)	{	return x < y - eps;}	// x < y
bool dyd(double x,double y)	{ 	return x > y - eps;}	// x >= y
bool xyd(double x,double y)	{	return x < y + eps;} 	// x <= y
bool dd(double x,double y) 	{	return fabs( x - y ) < eps;}  // x == y
double disp2p(point a,point b)
{
    return sqrt( ( a.x - b.x ) * ( a.x - b.x ) + ( a.y - b.y ) * ( a.y - b.y ) );
}
point l2l_inst_p(point u1,point u2,point v1,point v2)
{
    point ans = u1;
    double t = ((u1.x - v1.x)*(v1.y - v2.y) - (u1.y - v1.y)*(v1.x - v2.x))/
        ((u1.x - u2.x)*(v1.y - v2.y) - (u1.y - u2.y)*(v1.x - v2.x));
    ans.x += (u2.x - u1.x)*t;
    ans.y += (u2.y - u1.y)*t;
    return ans;
}
point circumcenter(point a,point b,point c)
{
    point ua,ub,va,vb;
    ua.x = ( a.x + b.x )/2;
    ua.y = ( a.y + b.y )/2;
    ub.x = ua.x - a.y + b.y;//根据 垂直判断，两线段点积为0
    ub.y = ua.y + a.x - b.x;
    va.x = ( a.x + c.x )/2;
    va.y = ( a.y + c.y )/2;
    vb.x = va.x - a.y + c.y;
    vb.y = va.y + a.x - c.x;
    return l2l_inst_p(ua,ub,va,vb);
}
void min_circle(point p[],int n,point &c,double &r)
{
    random_shuffle(p,p+n); // 重点
    c = p[0]; r = 0;
    int cnt = 0;
    for(int i=1; i<n; i++){
        if( dy(disp2p(p[i],c),r) ){
            c = p[i]; r = 0;
            for(int k=0; k<i; k++){
                if( dy(disp2p(p[k],c),r) ){
                    c.x = (p[i].x + p[k].x)/2;
                    c.y = (p[i].y + p[k].y)/2;
                    r = disp2p(p[k],c);
                    for(int j=0; j<k; j++){
                        if( dy(disp2p(p[j],c),r) ){
                            // 求外接圆圆心，三点必不共线
                            c = circumcenter(p[i],p[k],p[j]);
                            r = disp2p(p[i],c);
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    int n;

    while( ~scanf("%d",&n) && n )
    {
        for(int i=0; i<n; i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        point c; double r;
        min_circle(p,n,c,r);
        printf("%.2lf %.2lf %.2lf\n",c.x,c.y,r);
    }
    return 0;
}

