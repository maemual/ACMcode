#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;
const int MAXN=220;
int a[MAXN],b[MAXN];
int main()
{
	int n,m;
	while(scanf("%d",&n)==1)
	{
		int sum=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		scanf("%d",&m);
		for(int i=0;i<m;i++)
			scanf("%d",&b[i]);
		if(sum==0)
		{
			printf("0.00\n");
			continue;
		}
		if(n==m)
		{
			printf("inf\n");
			continue;
		}
		printf("%.2lf\n",(double)sum/(n-m));
	}
	return 0;
}
