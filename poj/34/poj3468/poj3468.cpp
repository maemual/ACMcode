#include <cstdio>
const int MAX_LEN = 100000;
int a[MAX_LEN+5];
int main()
{
	int n,q;
	while (scanf("%d%d",&n,&q) != EOF)
	{
		for (int i=1;i<=n;i++)
		  scanf("%d",&a[i]);
		char opera;
		int x,y;
		int z;
		for (int i=0;i<q;i++)
		{
			getchar();
			scanf("%c",&opera);
			getchar();
			if (opera == 'Q')
			{
				scanf("%d%d",&x,&y);
				long long sum = 0;
				for (int j=x;j<=y;j++)
					sum+=a[j];
				printf("%lld\n",sum);
			}else {
				scanf("%d%d%d",&x,&y,&z);
				for (int j=x;j<=y;j++)
				  a[j] += z;
			}
		}
	}
	return 0;
}
