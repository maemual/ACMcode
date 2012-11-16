#include <cstdio>
const int MAX_LEN = 100000;
int a[MAX_LEN+5],b[MAX_LEN+5];
int main()
{
	int n;
	while (1)
	{
		scanf("%d",&n);
		if (n == 0)
		  break;
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			b[a[i]] = i;
		}
		bool flag = true;
		for (int i=1;i<=n;i++)
		{
			if (a[i] != b[i])
			{
				flag = false;
				break;
			}
		}
		if (flag)
		  printf("ambiguous\n");
		else 
		  printf("not ambiguous\n");
	}
	return 0;
}
