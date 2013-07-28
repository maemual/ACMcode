#include<cstdio>
#include<algorithm>
using namespace std;
int arr[1000005], n, k;
int main()
{
	int maxn;
	while (scanf("%d %d", &n, &k) != EOF){
		maxn = 0;
		for (int i = 0; i < 2 * n * k; i++)
		{
			scanf("%d", &arr[i]);
			maxn = max(maxn,arr[i]);
		}
		std::sort(arr, arr + 2 * n * k);
		int k = 0, ans = 0;
//		for (int i = 0; i < 2 * n; i += 2)
//			ans = std::max(ans, arr[i+1] - arr[i]);
		int high = maxn,low = 0;
		while(high > low)
		{
			int mid = (high + low)/2;
			int count = 0;
			for(int i = 0;i < 2*n ;i+=2)
			{
				if((arr[i+1] - arr[i]) <= mid)	count++;
			}
			if(count == n)	{printf("count = %d %d \n",count,n);low = mid;break;}
			if(count > n)	{high = mid - 1;}
			else			{low = mid + 1;}
		}
		printf("high = %d low = %d\n",high,low);
		int count = 0;
		for(int i = 0;i < 2*n ;i+=2)
		{
			if((arr[i+1] - arr[i]) <= low)	count++;
		}
		printf("%d\n", count);
	}
	return 0;
}
