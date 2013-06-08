#include <cstdio>
const int MAX_LEN = 100;
int a[MAX_LEN+5];
int pow(int x,int y)
{
	int sum=1;
	for (int i=0;i<y;i++)
	  sum *= x;
	return sum;
}
int main()
{
	int n,e,x;
	while (scanf("%d",&n) != EOF)
	{
		scanf("%d",&e);
		int sum = 0;
		for (int i=0;i<n;i++)
		{
			scanf("%d",&x);
			if (e % 2 == 0)
			  sum += pow(x,e);
			else if (x > 0)
			  sum += pow(x,e);
		}
		printf("%d\n",sum);
	}
	return 0;
}
