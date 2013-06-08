#include <cstdio>
const int MAX_LEN = 50005;
int a[MAX_LEN];
int main()
{
	int n;
	scanf("%d",&n);
	//int a[50005];
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if (a[1]>=a[2])
		printf("%d\n",1);
	for (int i=2;i<=n;i++)
	{
		if (i == n)
		{
			if (a[i]>=a[i-1])
				printf("%d\n",i);
		}else{
			if (a[i]>=a[i-1] && a[i]>=a[i+1])
			{
				printf("%d\n",i);
			}
		}
	}
	return 0;
}
