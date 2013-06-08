#include <cstdio>
const int MAX_LEN = 30;
int a[MAX_LEN+5];
int main()
{
	int n;
	while (scanf("%d",&n) != EOF)
	{
		if (n == 0)
		  break;
		int sum = 0;
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sum += a[i];
		}
		int cnt = 0;
		bool flag = true;
		for (int i=1;i<=n;i++)
		{
			cnt+=a[i];
			if (cnt*2==sum)
			{
				flag = false;
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
