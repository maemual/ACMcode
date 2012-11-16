#include <cstdio>
#include <cstring>
int main()
{
	int a[1005];
	int t,n;
	char ch;
	int t1,t2;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		for (int i=0;i<n;i++)
		{
			getchar();
			scanf("%c%d%d",&ch,&t1,&t2);
			for (int j=t1;j<t2;j++)
				a[j]++;
		}
		for (int i=0;i<1005;i++)
		{
			if (a[i] != 0)
			{
				printf("%c",'A'+a[i]-1);
			}
		}
		printf("\n");
	}
	return 0;
}
