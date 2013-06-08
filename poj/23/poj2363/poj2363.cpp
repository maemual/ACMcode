#include <cstdio>
#include <climits>

int main()
{
	int cas,n;
	scanf("%d",&cas);
	while (cas--)
	{
		scanf("%d",&n);
		int min = INT_MAX;
		int a,b,c;
		int area;
		for (a=1;a<=n;a++)
		{
			for (b=1;a*b<=n;b++)
			{
				c = n/(a*b);
				if (a*b*c == n)
				{
					area = 2*(a*b+a*c+b*c);
					if (min > area)
					  min = area;
				}
			}
		}
		printf("%d\n",min);
	}
	return 0;
}
