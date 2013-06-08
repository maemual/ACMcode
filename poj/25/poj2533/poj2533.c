#include <stdio.h>

#define MAX_LEN 1005
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	int a[MAX_LEN];
	int stack[MAX_LEN];
	for (i = 0; i < n; i++)
	  scanf("%d",&a[i]);

	int top = 0;
	stack[top] = -1;
	for (i = 0; i < n; i++)
	{
		if (a[i] > stack[top])
		{
			stack[++top] = a[i];
		}else{
			int left = 1,right = top;
			int mid;
			while (left <= right)
			{
				mid = (left + right) / 2;
				if (a[i] > stack[mid])
				  left = mid + 1;
				else
				  right = mid - 1;
			}
			stack[left] = a[i];
		}
	}
	printf("%d\n",top);
	return 0;
}
