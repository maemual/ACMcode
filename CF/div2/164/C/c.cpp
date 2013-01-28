#include <cstdio>

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int min = n>m?m:n;
	printf("%d\n",min+1);
	int x = 0,y = m;
	while (x <=n && y>=0)
	{
		printf("%d %d\n",x++,y--);
	}
	return 0;
}
