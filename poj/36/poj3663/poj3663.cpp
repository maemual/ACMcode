#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAX_LEN 20005
int main()
{
	int n,s;
	scanf("%d %d",&n,&s);
	int arr[MAX_LEN];
	for (int i = 0; i < n; i++)
	  scanf("%d",&arr[i]);

	sort(arr,arr+n);
	int ans = 0;
	int head = 0,tail = n-1;
	while (head < n)
	{
		if (head != tail && arr[head] + arr[tail] <= s)
		{
			ans += tail-head;
			head++;
			tail = n-1;
		}else {
			tail--;
			if (head >= tail)
			{
				head++;
				tail = n-1;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
