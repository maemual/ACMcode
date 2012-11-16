#include <cstdio>
long long abs(long long a)
{
	if (a>0)
	  return a;
	else
	  return -a;
}
int main()
{
	int n;
	int x;
	long long total,res;
	while (1)
	{
		scanf("%d",&n);
		if (n == 0)
		  break;
		res = 0;
		total = 0;
		for (int i=0;i<n;i++)
		{
			scanf("%d",&x);
			x+=res;
			res=x;
			total+=abs(res);
		}
		printf("%lld\n",total);
	}
	return 0;
}
