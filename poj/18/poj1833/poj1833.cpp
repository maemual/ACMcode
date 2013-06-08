#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int cas;
	scanf("%d",&cas);
	int n,cnt;
	int i;
	int arr[1024];
	while (cas--)
	{
		scanf("%d %d",&n,&cnt);
		for (i = 0; i < n; i++)
		  scanf("%d",&arr[i]);

		while (cnt--)
		{
			next_permutation(arr,arr+n);
		}
		for (i = 0; i < n-1; i++)
		  printf("%d ",arr[i]);
		printf("%d\n",arr[n-1]);
	}
	return 0;
}
