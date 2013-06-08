#include <cstdio>
#include <cstring>
bool arr[1000005];
int main()
{
	int n;
	int q,a,x;
	while (scanf("%d",&n) != EOF)
	{		
		memset(arr,0,sizeof(arr));
		int sum = 0;
		for (int i=0;i<n;i++)
		{
			scanf("%d%d%d",&q,&a,&x);
			if (a == 1 && x == 1)
			{
				sum += 40;
			}else if (a == 1)
			{
				sum += 20;
			}else 
				sum += 10;

			if (arr[q] && a == 1)
				sum += 10;
			if (a == 1)
				arr[q] = true;
		}
		printf("%d\n",sum);
	}
	return 0;
}
