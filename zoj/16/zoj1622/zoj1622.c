#include <stdio.h>

#define MAX_LEN 10005

int a[MAX_LEN];
int main()
{
	int n;
	int cnt1,cnt2;
	int i;
	while (scanf("%d",&n) != EOF)
	{
		for (i = 0; i < n; i++)
		  scanf("%d",&a[i]);

		i = 0;
		cnt1 = cnt2 = 0;
		while (1)
		{
			if (a[i])
			  cnt1++;
			else 
			  cnt2++;
			i++;
			if (i >= n)
			  break;
			if (a[i])
			  cnt2++;
			else
			  cnt1++;
			i++;
			if (i>=n)
			  break;
		}
		printf("%d\n",cnt1>cnt2?cnt2:cnt1);
	}
	return 0;
}
