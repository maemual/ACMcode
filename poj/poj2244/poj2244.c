#include <stdio.h>
#include <string.h>
#define MAX_LEN 155

int a[MAX_LEN];
int main()
{
	int n,m;
	int p,q;
	int cnt;
	int flag;
	while (1)
	{
		scanf("%d",&n);
		if (n == 0)
		  break;
		for (m = 1; ; m++)
		{
			memset(a,1,sizeof(a));
			a[1] = 0;
			p = 1;q = 0;
			cnt = 1;
			flag = 0;
			while (cnt < n-1)
			{
				q = 0;
				while (q < m)
				{
					p++;
					if (p > n)
					  p = 1;
					if (a[p])
					  q++;
				}
				a[p] = 0;
				cnt++;
				if (a[2] == 0)
				{
					flag = 1;
					break;
				}
			}
			if (flag)
			  continue;
			else{
			  printf("%d\n",m);
			  break;
			}
		}
	}
	return 0;
}
