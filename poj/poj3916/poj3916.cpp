#include <cstdio>
const int MAX_LEN = 25;
int a[MAX_LEN+5];

int main()
{
	int n;
	while (scanf("%d",&n) != EOF)
	{
		if (n == 0)
		  break;
		for (int i=0;i<n;i++)
		  scanf("%d",&a[i]);
		printf("%d ",a[0]);
		for (int i=1;i<n;i++)
		{
			if (a[i]!=a[i-1])
			  printf("%d ",a[i]);
		}
		printf("$\n");
	}
	return 0;
}
