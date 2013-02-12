#include <stdio.h>
#define MAX_LEN 505
#define MAX 1000000

int prime[MAX];
int ans[MAX_LEN][MAX_LEN]={0};
int mat[MAX_LEN][MAX_LEN];
int main()
{
	int row,col;
	scanf("%d %d",&row,&col);
	int i,j;
	for (i = 0; i < row; i++)
	  for (j = 0; j < col; j++)
		scanf("%d",&mat[i][j]);

	for (i = 2; i < MAX; i++)
	  prime[i] = 1;
	for (i = 2; i < MAX; i++)
	{
		if (prime[i])
		{
			for (j = 2; i*j < MAX; j++)
			  prime[i*j] = 0;
		}
	}
	int x;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			x = mat[i][j];
			while (!prime[x]) x++;
			ans[i][j] = x - mat[i][j];
		}
	}

	int sum = 0,min = 999999999;
	for (i = 0; i < row; i++)
	{
		sum = 0;
		for (j = 0; j < col; j++)
		  sum += ans[i][j];
		if (sum < min)
		  min = sum;
	}
	for (i = 0; i < col; i++)
	{
		sum = 0;
		for (j = 0; j < row; j++)
		  sum += ans[j][i];
		if (sum < min)
		  min = sum;
	}
	printf("%d\n",min);
	return 0;
}
