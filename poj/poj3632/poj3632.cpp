#include <cstdio>
#include <climits>

int main()
{
	int cas;
	scanf("%d",&cas);
	while (cas--)
	{
		int num;
		int x;
		int max=INT_MIN;
		int min=INT_MAX;
		scanf("%d",&num);
		for (int i=0;i<num;i++)
		{
			scanf("%d",&x);
			if (max < x)
				max = x;
			if (min > x)
				min = x;
		}
		printf("%d\n",2*(max-min));
	}
	return 0;
}
