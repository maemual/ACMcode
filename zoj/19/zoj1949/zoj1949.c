#include <stdio.h>
#include <string.h>

#define MAX_LEN 105
int main()
{
	int n;
	int i,j;
	int arr[MAX_LEN][MAX_LEN];
	while (1)
	{
		scanf("%d",&n);
		if (n == 0)
		  break;
		memset(arr,0,sizeof(arr));
		int row = 0,col = 0;
		int pr,pc;
		int flag = 0;
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				scanf("%d",&arr[i][j]);
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			  arr[i][n] += arr[i][j];
			if (arr[i][n] % 2 == 1)
			{
				if (row == 0) {
				  row++;
				  pr = i;
				}else {
					flag = 1;
					break;
				}
			}
		}
		if (flag)
		{
			printf("Corrupt\n");
			continue;
		}
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			  arr[n][i] += arr[j][i];
			if (arr[n][i] % 2 == 1)
			{
				if (col == 0){
				  col++;
				  pc = i;
				}else {
					flag = 1;
					break;
				}
			}
		}
		if (flag)
		{
			printf("Corrupt\n");
			continue;
		}
		if (row == 0 && col == 0)
		  printf("OK\n");
		else
		  printf("Change bit (%d,%d)\n",pr+1,pc+1);
	}
	return 0;
}
