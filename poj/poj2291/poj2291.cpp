#include <cstdio>
#include <algorithm>
const int MAX_LEN = 1000;
int a[MAX_LEN+5];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	int cas;
	int n;
	scanf("%d",&cas);
	while (cas--)
	{
		scanf("%d",&n);
		for (int i=0;i<n;i++)
		  scanf("%d",&a[i]);
		std::sort(a,a+n,cmp);
		//printf("%d",a[0]);
		int max = -1;
		int sum = 0;
		for (int i=0;i<n;i++)
		{
			sum = a[i]*(i+1);
			if (sum > max)
			  max = sum;
		}
		printf("%d\n",max);
	}
	return 0;
}
