#include <cstdio>
const int MAX_LEN = 1000;
int grade[MAX_LEN+5];
int main()
{
	int cas,n;
	scanf("%d",&cas);
	while (cas--)
	{
		scanf("%d",&n);
		int sum = 0;
		for (int i=0;i<n;i++)
		{
			scanf("%d",&grade[i]);
			sum += grade[i];
		}
		double aver = sum*1.0/n;
		int num = 0;
		for (int i=0;i<n;i++)
		{
			if (grade[i]>aver)
			  num++;
		}
		double percent = num*100.0/n;
		printf("%.3f\%\n",percent);
	}
	return 0;
}
