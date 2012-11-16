#include <cstdio>
const int MAX_LEN = 100;
int a[MAX_LEN+5][MAX_LEN+5];

int main()
{
	int n;
	scanf("%d",&n);
	int max=-1;
	int win=0;
	for (int i=0;i<n;i++)
	{
		int sum = 0;
		for (int j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
			if (a[i][j] == 3)
			{
				sum++;
			}
		}
		if (sum > max)
		{
			max = sum;
			win = i;
		}
	}
	printf("%d\n",win+1);
	return 0;
}
