#include<stdio.h>
#include<cmath>
#define PI acos(-1.0)
int main()
{
	double D,V;
	while(1)
	{
		scanf("%lf %lf",&D,&V);
		if(D==0&&V==0)
		  return 0;
		printf("%.3lf\n",pow((D*D*D-6.0/PI*V),1.0/3));
	}
	return 0;
}
