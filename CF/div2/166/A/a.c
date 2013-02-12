#include <stdio.h>

int main()
{
	int year;
	scanf("%d",&year);
	int a,b,c,d;
	int ans;
	for (;;)
	{
		year++;
		d = year % 10;
		c = (year / 10 ) % 10;
		b = (year / 100 ) % 10;
		a = year / 1000;
		if (a != b && a != c && a != d
			&& b != c && b != d
			&& c != d)
		{
			printf("%d\n",year);
			break;
		}
	}
	return 0;
}
