#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 55
int a[MAX_LEN];
int main()
{
	int n;
	int i;
	int sum,avg;
	int k = 0;
	while (1)
	{
		scanf("%d",&n);
		if (n == 0)
		  break;
		k++;
		sum = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%d",&a[i]);
			sum += a[i];
		}
		avg = sum / n;
		int x = 0;
		for (i = 0; i < n; i++)
			x += abs(a[i] - avg);

		printf("Set #%d\nThe minimum number of moves is %d.\n\n",k,x/2);
	}
	return 0;
}
