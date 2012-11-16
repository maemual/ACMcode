#include <cstdio>
#include <algorithm>
const int MAX_LEN = 1000;
int a[MAX_LEN+5];
bool cmp(int m,int n)
{
	return m>n;
}
int main()
{
	int cas;
	scanf("%d",&cas);
	for (int k=1;k<=cas;k++)
	{
		int needs,num;
		scanf("%d%d",&needs,&num);
		for (int i=0;i<num;i++)
		  scanf("%d",&a[i]);
		std::sort(a,a+num,cmp);
		int ans = 0;
		bool flag = true;
		for (int i=0;i<num;i++)
		{
			needs -= a[i];
			if (needs<=0)
			{
				flag = false;
				ans = i+1;
				break;
			}
		}
		if (flag)
		  printf("Scenario #%d:\nimpossible\n\n",k);
		else 
		  printf("Scenario #%d:\n%d\n\n",k,ans);
		//printf("%d\n",a[0]);
	}
	return 0;
}
