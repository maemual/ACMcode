#include <stdio.h>
int pow(int m,int n)
{
	int i;
	int sum = 1;
	for (i = 0;i < n;i++)
		sum *= m;
	return sum;
}
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	int a = pow(10,n-1);
	int b = pow(10,n-1)*10;
	for (i = a; i < b; i++)
	{
		int x = i;
		int sum = 0;
		int j;
		for (j = 0; j < n; j++)
		{
			sum += pow(x % 10,n);
			x /= 10;
		}
		if (sum == i)
		  printf("%d\n",sum);
	}
	return 0;
}
