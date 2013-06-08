/*************************************************************************
	> File Name: zoj1915.c
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年03月02日 星期六 16时53分08秒
 ************************************************************************/

#include<stdio.h>

#define MAX_LEN 1005
int a[MAX_LEN];
int main()
{
	int cas;
	int n;
	int i;
	double avg,sum,cnt;
	scanf("%d",&cas);
	while (cas--)
	{
		scanf("%d",&n);
		sum = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%d",&a[i]);
			sum += a[i];
		}
		avg = sum / n;
		cnt = 0;
		for (i = 0; i < n; i++)
		{
			if (a[i] > avg)
				cnt++;
		}
		printf("%.3lf%%\n", cnt * 1.0 / n * 100);
	}
	return 0;
}
