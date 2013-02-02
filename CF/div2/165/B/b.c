#include <stdio.h>

#define MAX_LEN 100005
int main()
{
	int a[MAX_LEN];
	int n;
	scanf("%d",&n);
	int i;
	for (i = 1; i <= n; i++)
	{
		scanf("%d",&a[i]);
	}
	for (i = n-1; i >= 1; i--)
	{
		if (a[i] > a[i+1])
		  break;
	}
	printf("%d\n",i);
	return 0;
}
