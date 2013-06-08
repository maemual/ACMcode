#include <cstdio>
#include <algorithm>
#include <cmath>
const int MAX_LEN = 1000;
double a[MAX_LEN+5];
bool cmp(double p,double q)
{
	return p>q;
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	  scanf("%lf",&a[i]);
	std::sort(a,a+n,cmp);
	for (int i=1;i<n;i++)
	  a[i] = 2*sqrt(a[i-1]*a[i]);
	//printf("%lf\n",a[0]);
	printf("%.3f\n",a[n-1]);
	return 0;
}
