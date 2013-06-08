#include <stdio.h>
int splite(int n)
{
	int sum;
	int i;
	sum = n;
	while (n >= 10)
	{
		sum += n % 10;
		n /= 10;
	}
	sum += n;
	return sum;
}
int main()
{
	int a[10001];
	int i,temp;
	for (i=1;i<=10000;i++)
	  a[i] = 0;
	for (i=1;i<=10000;i++)
	{
		temp = splite(i);
		if (temp <= 10000)
		  a[temp] = 1;
	}
	for (i=1;i<=10000;i++)
	{
		if (a[i] == 0)
		  printf("%d\n",i);
	}
	return 0;
}
