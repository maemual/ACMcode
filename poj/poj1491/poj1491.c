#include <stdio.h>
#include <math.h>

#define MAX_LEN 55
int a[MAX_LEN];
int gcd(int x,int y)
{
	return y?gcd(y,x%y):x;
}
int main()
{
	int n;
	int i,j;
	while (scanf("%d",&n) && n)
	{
		for (i = 0; i < n; i++)
		  scanf("%d",&a[i]);
		int ans = 0;
		for (i = 0; i < n; i++)
		{
			for (j = i + 1; j < n; j++)
			{
				if (gcd(a[i],a[j]) == 1)
				  ans++;
			}
		}
		if (ans == 0)
		  printf("No estimate for this data set.\n");
		else
		  printf("%.6lf\n",sqrt(3.0*n*(n-1)/ans));
	}
	return 0;
}
