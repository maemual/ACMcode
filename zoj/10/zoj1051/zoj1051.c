#include <stdio.h>

#define MAX_LEN 20
int dish[MAX_LEN][MAX_LEN];
int dish1[MAX_LEN][MAX_LEN];

int sum(int x,int y,int arr[MAX_LEN][MAX_LEN])
{
	int sum = arr[x][y];
	if (x-1 >= 0)
	  sum += arr[x-1][y];
	if (x+1 < MAX_LEN)
	  sum += arr[x+1][y];
	if (y-1 >= 0)
	  sum += arr[x][y-1];
	if (y+1 < MAX_LEN)
	  sum += arr[x][y+1];
	return sum;
}
int main()
{
	int cas;
	int i,j,d;
	int DNA[16];
	int (*curr)[20] = dish;
	int (*next)[20] = dish1;
	int (*temp)[20];

	char sign[]={'.','!','X','#'};

	scanf("%d",&cas);
	while (cas--)
	{
		int day;
		scanf("%d",&day);

		for (i = 0;i<16;i++)
		  scanf("%d",&DNA[i]);

		for (i=0;i<MAX_LEN;i++)
		  for (j=0;j<MAX_LEN;j++)
			scanf("%d",&curr[i][j]);

		for (d=0;d<day;d++)
		{
			for (i=0;i<MAX_LEN;i++)
			{
				for (j=0;j<MAX_LEN;j++)
				{
					int k = sum(i,j,curr);
					next[i][j] = curr[i][j] + DNA[k];
					if (next[i][j] > 3)
					  next[i][j] = 3;
					if (next[i][j] < 0)
					  next[i][j] = 0;
				}
			}

			temp = curr;
			curr = next;
			next = temp;
		}
		for (i = 0; i < MAX_LEN; i++)
		{
			for (j = 0; j < MAX_LEN; j++)
			{
				printf("%c",sign[curr[i][j]]);
			}
			printf("\n");
		}
		if (cas != 0)
		  printf("\n");
	}
	return 0;
}
