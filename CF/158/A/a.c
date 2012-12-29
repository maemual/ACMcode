#include <stdio.h>

int main()
{
	int a,b,n;
	scanf("%d %d %d",&a,&b,&n);
	int flag = 0;
	int temp = a;
	a *= 10;
	int i;
	for (i = 0; i <= 9; i++)
	{
		if ((a+i) % b == 0)
		{
			flag = 1;
			break;
		}
	}
	if (flag)
	{
		printf("%d%d",temp,i);
		for (i = 0; i < n-1; i++)
		  printf("0");
		printf("\n");
	}else
	  printf("-1\n");
	return 0;
}
