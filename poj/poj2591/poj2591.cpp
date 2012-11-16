#include <cstdio>
const int MAX_LEN = 10000000;
int a[MAX_LEN+5];
int min(int a,int b)
{
	if (a>b)
	  return b;
	return a;
}
int main()
{
	a[1] = 1;
	int p2 = 1,p3 = 1;
	for (int i=2;i<=MAX_LEN;i++)
	{
		a[i] = min(a[p2]*2+1,a[p3]*3+1);
		if (a[i] == a[p2]*2+1)
		  p2++;
		if (a[i] == a[p3]*3+1)
		  p3++;
	}
	int n;
	while (scanf("%d",&n) != EOF)
	{
		printf("%d\n",a[n]);
	}
	return 0;
}
