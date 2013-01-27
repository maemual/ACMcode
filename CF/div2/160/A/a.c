#include <stdio.h>
#include <string.h>

int main()
{
	int n,k;
	int x;
	scanf("%d %d",&n,&k);
	int i;
	int ans = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d",&x);
		int j;
		int sum = 0;
		int y;
		for (j = 0; x != 0; j++)
		{
			y = x % 10;
			x /= 10;
			if (y == 4 || y == 7)
			  sum++;
		}
		if (sum <= k)
		  ans++;
	}
	printf("%d\n",ans);
}
