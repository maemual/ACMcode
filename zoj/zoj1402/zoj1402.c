#include <stdio.h>
#define MAX_LEN  35
int a[MAX_LEN];
int main()
{
	int n;
	int i;
	while (scanf("%d",&n) != EOF)
	{
		if (n == 0)
		  break;
		int sum = 0;
		for (i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sum += a[i];
		}
		int cnt = 0;
		int flag = 1;
		for (i=1;i<=n;i++)
		{
			cnt+=a[i];
			if (cnt*2==sum)
			{
				flag = 0;
				printf("Sam stops at position %d and Ella stops at position %d.\n",i,i+1);
				break;
			}
		}
		if (flag)
		{
			printf("No equal partitioning.\n");
		}
	}
	return 0;
}
