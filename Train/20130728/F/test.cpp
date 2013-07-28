#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int org[1000010];
bool cmp(int a,int b)
{
	return a<b;
}
int main()
{
	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		for(int i=1;i<=2*n*k;i++)
			scanf("%d",&org[i]);
		sort(org+1,org+1+2*n*k,cmp);
		int cha1=org[2]-org[1];
		int cha2=0;
		//	cout<<cha1<<endl;
		for(int i=4;i<=2*n*k-2*k+2;i += 2)
		{
			if(i==4) cha2=0x3fffffff;
			if(org[i]-org[i-1]<cha2)
			{
				cha2=org[i]-org[i-1];
				//i++;
			}
		}
		printf("%d\n",max(cha1,cha2));
	}
	return 0;
}
