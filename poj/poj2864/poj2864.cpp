#include <cstdio>
#include <string.h>
int main()
{
	int n,d;
	int x;
	int a[105];
	while (1)
	{
		scanf("%d%d",&n,&d);
		if (n == 0 && d == 0)
			break;
		memset(a,0,sizeof(a));
		for (int i=0;i<d;i++)
		{
			for (int j=0;j<n;j++)
			{
				scanf("%d",&x);
				if (x == 0)
					a[j] = 1;
			}
		}
		bool flag = true;
		for (int i=0;i<n;i++)
		{
			if (a[i] == 0)
			{
				printf("yes\n");
				flag = false;
				break;
			}
		}
		if (flag)
		{
			printf("no\n");
		}
	}
	return 0;
}
