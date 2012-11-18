#include <stdio.h>
#include <math.h>

int p[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576};

int main()
{
	int cas;
	scanf("%d",&cas);
	int i,j,k;
	int n;
	int flag;
	while (cas--)
	{
		scanf("%d",&n);
		flag = 0;
		for (i = 1; i <= n; i+=2)
		{
			for (j = 0; j <= 20; j++)
			{
				if (i*p[j] == n)
				{
					printf("%d %d\n",i,j);
					flag = 1;
					break;
				}
			}
			if (flag)
			  break;
		}
	}
	return 0;
}
