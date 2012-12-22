#include <stdio.h>

int main()
{
	int a[5][5];
	int i,j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	int x = (a[1][0]+a[1][2])/2;
	a[1][1] = x;
	int sum = x*3;
	if (a[0][0] == 0)
	{
		a[0][0] = sum - a[0][1] - a[0][2];
		a[2][2] = sum - a[2][0] - a[2][1];
	}
	else 
	{
		a[0][2] = sum - a[0][0] - a[0][1];
		a[2][0] = sum - a[2][1] - a[2][2];
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 2; j++)
		  printf("%d ",a[i][j]);
		printf("%d\n",a[i][2]);
	}
	return 0;
}
