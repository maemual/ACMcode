#include <cstdio>
double x[1000];
double y[1000];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
			scanf("%lf %lf",&x[i],&y[i]);
		printf("%d",n);
		for(int i=0;i<n-1;i++)
		{
			printf(" %.6f %.6f",(x[i]+x[i+1])/2,(y[i]+y[i+1])/2);
		}
		printf(" %.6f %.6f\n",(x[0]+x[n-1])/2,(y[0]+y[n-1])/2);
	}
	return 0;
}
