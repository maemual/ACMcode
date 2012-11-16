#include <stdio.h>
#include <string.h>
int k;
int num[14];
int sub[7];
void dfs(int d,int cur)
{
	int i;
	if (d == 6)
	{
		for (i = 0;i < 5; i++)
		  printf("%d ",sub[i]);
		printf("%d\n",sub[5]);
		return ;
	}
	for (i = cur; i < k-(6-d)+1; i++)
	{
		sub[d] = num[i];
		dfs(d+1,i+1);
	}
}
int main()
{
	int i;
	int flag = 0;
	while (1)
	{
		scanf("%d",&k);
		if (k == 0)
		  break;
		
		if (flag == 1)
		  printf("\n");
		for (i = 0;i < k; i++)
		  scanf("%d",&num[i]);
		dfs(0,0);
		flag = 1;
	}
	return 0;
}
