#include <cstdio>
int a[]={2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881,13482720};
int main()
{
	int n;
	while (scanf("%d",&n) != EOF)
	{
		if (n == 0)
		  break;
		printf("%d\n",a[n-1]);
	}
	return 0;
}
