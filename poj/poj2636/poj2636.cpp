#include <cstdio>

int main()
{
	int Case;
	int n;
	int sum;
	int x;
	scanf("%d",&Case);
	while (Case--)
	{
		scanf("%d",&n);
		sum = 0;
		for (int i=0;i<n;i++)
		{
			scanf("%d",&x);
			sum += x;
		}
		printf("%d\n",sum - n + 1);
	}
	return 0;
}
