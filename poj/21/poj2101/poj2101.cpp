#include <cstdio>
#include <cmath>
int main()
{
	int n,e;
	scanf("%d%d",&n,&e);
	int temp;
	int sum1=0,sum2=0;
	for (int i=0;i<n-1;i++)
	{
		scanf("%d",&temp);
		sum1+=temp;
	}
	for (int i=0;i<e-1;i++)
	{
		scanf("%d",&temp);
		sum2+=temp;
	}
	int ans = ceil(sqrt(sum1*sum1+sum2*sum2));
	printf("%d\n",ans);
	return 0;
}
