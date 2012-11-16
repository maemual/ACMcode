#include <cstdio>
const int MAX_LEN = 100000;
int stack[MAX_LEN+5];
int main()
{
	int n;
	while (scanf("%d",&n) != EOF)
	{
		int top = 0;
		stack[top] = -1;
		int temp;
		for (int i=0;i<n;i++)
		{
			scanf("%d",&temp);
			if (temp > stack[top])
			{
				stack[++top] = temp;
			}else {
				int left=0,right=top;
				while (left<=right)
				{
					int mid = (left+right)/2;
					if (temp>stack[mid])
					  left = mid+1;
					else 
					  right = mid-1;
				}
				stack[left] = temp;
			}
		}
		printf("%d\n",top);
	}
	return 0;
}
