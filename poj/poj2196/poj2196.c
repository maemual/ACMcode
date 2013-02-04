#include <stdio.h>

int sum(int n,int d)
{
	if (n / d)
	  return n % d + sum(n / d,d);
	else
	  return n;
}

int main()
{
	int i;
	for (i = 2992; i <= 9999; i++)
	{
		if (sum(i,10) == sum(i,12) && sum(i,10) == sum(i,16))
		  printf("%d\n",i);
	}
	return 0;
}
