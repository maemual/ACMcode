#include <cstdio>
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int n,length;
	while (scanf("%d%d",&n,&length) != EOF)
	{
		int height,ans=0;
		for (int i=0;i<n;i++)
		{
			scanf("%d",&height);
			if (height % length !=0)
			  ans = max(ans,length - height%length);
		}
		printf("%d\n",ans);
	}
	return 0;
}
