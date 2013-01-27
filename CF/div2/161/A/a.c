#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i,j,x,y;
	int ans;
	int a[5][5];
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			scanf("%d",&a[i][j]);
			if (a[i][j] == 1)
			{
				ans = abs(i-2)+abs(j-2);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
