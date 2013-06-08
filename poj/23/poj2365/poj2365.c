#include <stdio.h>
#include <math.h>
#define PI 3.1415926
struct node{
	double x,y;
}a[105];
int main()
{
	int n;
	double radius;
	scanf("%d %lf",&n,&radius);
	int i;
	for (i = 0; i < n; i++)
	  scanf("%lf %lf",&a[i].x,&a[i].y);
	double ans = 0;
	for (i = 0; i < n-1; i++)
	{
		ans += sqrt((a[i].x-a[i+1].x)*(a[i].x-a[i+1].x)
					+(a[i].y-a[i+1].y)*(a[i].y-a[i+1].y));
	}
	ans += sqrt((a[n-1].x-a[0].x)*(a[n-1].x-a[0].x)
				+(a[n-1].y-a[0].y)*(a[n-1].y-a[0].y));
	ans += 2*PI*radius;
	printf("%.2lf\n",ans);
	return 0;
}
