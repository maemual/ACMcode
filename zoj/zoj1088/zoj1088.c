#include <stdio.h>
#include <string.h>
#define MAX_LEN 155
int arr[MAX_LEN];
int main()
{
	int n,m;
	int p,q;
	int cnt;
	int i;
	while (1)
	{
		scanf("%d",&n);
		if (n == 0)
		  break;
		for (m = 2; ;m++)
		{
			for (i = 0; i < MAX_LEN; i++)
			  arr[i] = 1;
			arr[1] = 0;
			p = 1;
			cnt = 1;
			while (cnt < n-1)
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
				if (arr[2] == 0)
				  break;
			}
			if (arr[2] == 1)
			{
				printf("%d\n",m);
				break;
			}
		}
	}
	return 0;
}
