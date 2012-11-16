#include <cstdio>
#include <cmath>
const double PI = 3.1415926535;
int main()
{
	int cas;
	scanf("%d",&cas);
	for (int i=1;i<=cas;i++)
	{
		double R;
		int n;
		scanf("%lf %d",&R,&n);
		double a = PI / n;
		printf("Scenario #%d:\n%.3f\n\n",i,R*sin(a)/(1+sin(a)));
	}
	return 0;
}
