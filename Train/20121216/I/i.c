#include <stdio.h>
#include <string.h>
#define MAX 1073741825
#define MAX_LEN 100005
int flag1[MAX],flag2[MAX];
int check()
{
	int i;
	int f = 1;
	for (i = 0; i < MAX; i++)
	{
		if (flag2[i] == 1)
		{
			f = 0;
			break;
		}
	}
	if (f == 0)
	  return 0;
	return 1;
}
int main()
{
	int n;
	int A[MAX_LEN],B[MAX_LEN];
	int i,j,k;
	while (scanf("%d",&n) != EOF)
	{
		for (i = 0; i < n; i++)
		  scanf("%d",&A[i]);
		for (i = 0; i < n; i++)
		  scanf("%d",&B[i]);
		memset(flag1,0,sizeof(flag1));

		for (i = 0; i < n; i++)
		  flag1[B[i]] = 1;
		
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < MAX; j++)
			  flag2[j] = flag1[j];
			for (j = 0; j < n; j++)
			  if (A[j] ^ i < MAX)
				flag2[A[j] ^ i] = 0;
			if (check())
			{
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}
