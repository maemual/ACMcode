#include <cstdio>
const int MAX_LEN = 350;
int map[MAX_LEN+5][MAX_LEN+5];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	  for (int j=0;j<i+1;j++)
		scanf("%d",&map[i][j]);

	for (int i=n-2;i>=0;i--)
	{
		for (int j=0;j<i+1;j++)
		{
			if (map[i+1][j] > map[i+1][j+1])
			  map[i][j] += map[i+1][j];
			else
			  map[i][j] += map[i+1][j+1];
		}
	}
	printf("%d\n",map[0][0]);
	return 0;
}
