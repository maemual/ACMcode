#include <stdio.h>

int main()
{
	int cas = 1;
	int a[10000];
	int n;
	int i;
	int stack[10000];
	int top;
	while (1)
	{
		n = 0;
		scanf("%d",&a[n++]);
		if (a[0] == -1)
		  break;
		while (1)
		{
			scanf("%d",&a[n++]);
			if (a[n-1] == -1)
			  break;
		}
		stack[0] = 99999999;
		top = 0;
		for (i = 0; i < n-1; i++)
		{
			if (a[i] < stack[top])
			{
				stack[++top] = a[i];
			}else {
				int left = 1, right = top;
				int mid;
				while (left <= right)
				{
					mid = (left + right) / 2;
					if (a[i] < stack[mid])
					  left = mid + 1;
					else
					  right = mid - 1;
				}
				stack[left] = a[i];
			}
		}
		printf("Test #%d:\n  maximum possible interceptions: %d\n\n",cas++,top);
	}
	return 0;
}
