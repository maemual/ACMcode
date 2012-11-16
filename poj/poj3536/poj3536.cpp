#include <cstdio>
#include <climits>
#include <cmath>
int main()
{
	int n;
	while (scanf("%d",&n) != EOF)
	{
		int mina,minb,minc,min = INT_MAX;
		int x = sqrt((double)n);
		for (int a=1;a<=x;a++)
		{
			for (int b=1;b<=x;b++)
			{
				int c = n/(a*b);
				if (a*b*c == n && a*b+a*c+b*c < min)
				{
					min = a*b+a*c+b*c;
					mina = a;
					minb = b;
					minc = c;
				}
			}
		}
		printf("%d %d %d\n",mina,minb,minc);
	}
	return 0;
}
