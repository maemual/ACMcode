#include <stdio.h>

#define MAX_LEN 1000005
int arr[MAX_LEN] = {0};
int n,k;
int main()
{
	scanf("%d %d",&n,&k);
	if (k * 3 > n)
	{
		printf("-1\n");
		return 0;
	}
	int i;
	int p = 1;
	for (i = 0; i < 2 * k; i += 2)
	{
		arr[i] = p;
		arr[i+1] = p++;
	}
	p = 1;
	for (i = 2 * k ; i < 3 * k; i++)
	  arr[i] = p++;
	for (i = 3*k ; i < n; i++)
	  arr[i] = 1;
	for (i = 0; i < n-1; i++)
	  printf("%d ",arr[i]);
	printf("%d\n",arr[n-1]);
	return 0;
}
