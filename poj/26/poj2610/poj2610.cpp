#include <cstdio>
double dis(double x1,double y1,double x2,double y2)
{
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
int main()
{
	double x1,y1,x2,y2;
	scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
	double xh,yh;
	double ansx,ansy;
	bool flag = true;
	while (scanf("%lf%lf",&xh,&yh) != EOF)
	{
		if (flag && dis(x1,y1,xh,yh)*4 < dis(x2,y2,xh,yh))
		{
			ansx = xh;
			ansy = yh;
			flag = false;
		}
	}
	//printf("OK\n");
	if (flag)
	  printf("The gopher cannot escape.\n");
	else 
	  printf("The gopher can escape through the hole at (%.3f,%.3f).\n",ansx,ansy);

	return 0;
}
