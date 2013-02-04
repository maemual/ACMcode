#include <stdio.h>

#define MAX_LEN 500005

int a[MAX_LEN],b[MAX_LEN];
long long ans;
void merge_sort(int left,int right)
{
	if (left >= right) return;
	int mid = (left+right) / 2;
	merge_sort(left,mid);
	merge_sort(mid+1,right);
	int i = left,j = mid + 1,k = 0;
	while (i <= mid && j <= right)
	{
		if (a[j] < a[i])
		{
			b[k++] = a[j++];
			ans += mid - i + 1;
		}else
			b[k++] = a[i++];
	}
	while (i <= mid) b[k++] = a[i++];
	while (j <= right) b[k++] = a[j++];
	
	for (i = left,k = 0; i <= right; i++,k++)
	  a[i] = b[k];
}
int main()
{
	int n;
	int i;
	while (1)
	{
		scanf("%d",&n);
		if (n == 0)
		  break;
		for (i = 0; i < n; i++)
		  scanf("%d",&a[i]);
		ans = 0;
		merge_sort(0,n-1);
		printf("%lld\n",ans);
	}
	return 0;
}
