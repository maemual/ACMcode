#include <stdio.h>

#define MAX_LEN 105
int arr[MAX_LEN];
int main()
{
	int n,m = 0,x,sum = 0;
	int p,q;
	int cnt;
	int i;
	int ans;
	scanf("%d",&n);
	for (i = 0; i < n; i++)
	{
		scanf("%d",&x);
		sum += x;
	}
	n++;
	int y = 0;
	for (ans = 1; ans <= 5; ans++)
	{
		for (i = 0; i < MAX_LEN; i++)
		  arr[i] = 1;
		m = sum + ans;
		p = 0;
		cnt = 0;
		while (cnt < 1)
		{
			q = 0;
			while (q < m)
			{
				p++;
				if (p > n)
				  p = 1;
				if (arr[p])
				  q++;
			}
			arr[p] = 0;
			cnt++;
			if (arr[1] == 0)
			  break;
		}
		if (arr[1] == 1)
		{
			y++;
		}
	}
	printf("%d\n",y);
	return 0;
}
