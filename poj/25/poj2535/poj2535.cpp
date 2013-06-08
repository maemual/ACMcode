#include <cstdio>
#include <string.h>
#define MY_INT_MAX 0x7fffffff
int main()
{
	int n,p;
	int max[101],min[101],score[101][101];
	while (scanf("%d%d",&n,&p) != EOF)
	{
		memset(max,0,sizeof(max));
		memset(min,9999,sizeof(min));
		//printf("%d\n%d",min[0],MY_INT_MAX);
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<p;j++)
			{
				scanf("%d",&score[i][j]);
				if (max[i] < score[i][j])
					max[i] = score[i][j];
				if (min[i] > score[i][j])
					min[i] = score[i][j];
			}
		}
		bool flag = true;
		for (int i=0;i<p;i++)
		{
			int a=0;
			for (int j=0;j<n;j++)
			{
				if (max[j]==score[j][i])
				{
					a = -1;
					break;
				}
				if (min[j]==score[j][i])
					a++;
			}
			if (a>n/2)
			{
				flag = false;
				printf("%d ",i+1);
			}
		}
		if (flag)
			printf("0\n");
		else 
			printf("\n");
	}
}
