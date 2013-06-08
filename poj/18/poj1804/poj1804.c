#include <stdio.h>

#define MAX_LEN 1005

int arr[MAX_LEN];

int main()
{
	int cas;
	int i,j,k,n;
	int ans;
	int temp;
	scanf("%d",&cas);
	for (k = 1; k <= cas; k++)
	{
		scanf("%d",&n);
		for (i = 0; i < n; i++)
		  scanf("%d",&arr[i]);

		ans = 0;
		for (i = 0; i < n-1; i++)
		{
			for (j = 0; j < n-1; j++)
			{
				if (arr[j] > arr[j+1])
				{
					temp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = temp;
					ans++;
				}
			}
		}
		printf("Scenario #%d:\n",k);
		printf("%d\n\n",ans);
	}
	return 0;
}
