#include <cstdio>
#include <string.h>
int main()
{
	int k,m,c,r,x;
	int a[10000];
	while (1)
	{
		scanf("%d",&k);
		if (k == 0)
		  break;
		scanf("%d",&m);
		memset(a,0,sizeof(a));
		for (int i=0;i<k;i++)
		{
			scanf("%d",&x);
			a[x] = 1;
		}
		int p=0;
		for (int i=0;i<m;i++)
		{
			int count = 0;
			scanf("%d%d",&c,&r);
			for (int j =0;j<c;j++)
			{
				scanf("%d",&x);
				if (a[x] == 1)
					count++;
			}
			if (count >= r)
			{
				p++;
			}
		}
		if (p >= m)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
