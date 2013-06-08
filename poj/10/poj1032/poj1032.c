#include <stdio.h>
int main()
{
	int n,shu[1000];
	while(~scanf("%d",&n))
	{
		int sum=0,i,j;
		for(i=2;sum+i<n;i++)
		{
			shu[i-1]=i;
			sum+=i;
		}
		sum+=i;
		shu[i-1]=i;
		shu[0]=i-1;
		if(sum==n)
		{
			for(i=1;i<=shu[0];i++)
				printf("%d ",shu[i]);
			printf("\n");
		}
		if(sum-n==1)
		{
			for(i=2;i<shu[0];i++)
				printf("%d ",shu[i]);
			printf("%d ",shu[i]+1);
			printf("\n");
		}
		if(sum-n>=2)
		{
			for(i=1;i<=shu[0];i++)
			{
				if(sum-n!=shu[i])
				printf("%d ",shu[i]);
			}
			printf("\n");
		}
	}
	return 0;
}
