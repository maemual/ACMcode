#include <stdio.h>
#include <string.h>
const int MAX_LEN = 20;
int matrix[MAX_LEN+5][MAX_LEN+5];
int main()
{
	int n,s;
	while (scanf("%d %d",&n,&s) != EOF)
	{
		memset(matrix,0,sizeof(matrix));
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<=i;j++)
			{
				matrix[j][i] = s % 9;
				if (matrix[j][i] == 0)
				  matrix[j][i] = 9;
				s++;
			}
		}
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n-1;j++)
			{
				if (matrix[i][j] != 0)
				  printf("%d ",matrix[i][j]);
				else 
				  printf("  ");
			}
			printf("%d\n",matrix[i][n-1]);
		}
	}
	return 0;
}
