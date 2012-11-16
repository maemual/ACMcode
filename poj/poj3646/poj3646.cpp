#include<iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[20000],b[20000];
int cmp(int a,int b)
{
	return a<b;
}

int main()
{
	int n,m,sum,count;
	bool flag;
	while(scanf("%d%d",&n,&m) != EOF)
	{
		if(n==0&&m==0)
		  break;
		for(int i=0;i<n;i++)
		  scanf("%d",&a[i]);
		for(int i=0;i<m;i++)
		  scanf("%d",&b[i]);
		sort(a,a+n,cmp);
		sort(b,b+m,cmp);
		sum=0;
		count=0;
		flag=true;
		if(n>m)
		{
			printf("Loowater is doomed!\n");
			continue;
		}
		else
		  for(int i=n-1;i>=0;i--)
		  {
			  for(int j=0;j<m;j++)
			  {
				  if(flag==true)
				  {
					  if(b[j]>=a[i])
					  {
						  sum+=b[j];
						  b[j]=-1;
						  count++;
						  flag=false;
					  }
				  }
			  }
			  flag=true;
		  }
		if(count==n)
		  printf("%d\n",sum);
        else
		  printf("Loowater is doomed!\n");
   }




    return 0;
}
