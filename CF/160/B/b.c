#include <stdio.h>

#define MAX_LEN 100005
int main()
{
	int n,k;
	int a[MAX_LEN];
	scanf("%d %d",&n,&k);
	int i;
	for (i = 0; i < n; i++)
	  scanf("%d",&a[i]);
	int cnt = 0;
	for (i = 0; i < k && i < n; i++)
	{
		if (a[i] < 0)
		{
			a[i] *= -1;
			cnt++;
		}
		else break;
	}
//	if (cnt < k)
//	{
		k -= cnt;
		if (k % 2 != 0)
		  k = 1;
		else 
		  k = 0;
//	}
	if (k > 0)
	{
		if (i > 0 && a[i] > a[i-1])
		  a[i-1] *= -1;
		else if (i < n)
		  a[i] *= -1;
		else 
		  a[i-1] *= -1;
	}
	int sum = 0;
	for (i = 0; i < n; i++)
	  sum += a[i];
	printf("%d\n",sum);
	return 0;
}
