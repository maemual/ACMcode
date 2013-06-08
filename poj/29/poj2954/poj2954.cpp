#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct point
{ 
	int x,y; 
};
point a,b,c;
int gcd(int n,int m)
{
	return m == 0 ? n : gcd(m,n%m);
}
int intp_insegment(point a, point b)
{
	int aa = abs(b.y - a.y), bb = abs(b.x - a.x);
	if(aa == 0 && bb == 0)	return 0;
	if(aa == 0)	return bb - 1;
	if(bb == 0)	return aa - 1;
	return gcd(aa, bb) - 1;
}
double crossProduct(point a,point b,point c)//向量 ac 在 ab 的方向 
{
	return (c.x - a.x)*(b.y - a.y) - (b.x - a.x)*(c.y - a.y);
}
double area_triangle(point a,point b,point c)
{
	return fabs( crossProduct(a,b,c) )/2.0;
} 
int main()
{
	while( scanf("%d %d %d %d %d %d",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y)!= EOF )
	{
		if( !(a.x || a.y || b.x || b.y || c.x || c.y) )
			break;
		int pinedge = 3;
		pinedge += intp_insegment(a,b);
		pinedge += intp_insegment(c,b);
		pinedge += intp_insegment(a,c);
		double area = area_triangle(a,b,c);
		int ans = (int)area - pinedge/2 + 1;
		printf("%d\n",ans);
	}
	return 0;
}
