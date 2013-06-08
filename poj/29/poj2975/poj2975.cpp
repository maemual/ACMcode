#include <stdio.h>
const int MAX_LEN=1000;
//博弈 给定一个局面，问有多少种必胜策略 
//首先取所有堆的异或和k，让他与n个石子堆取异或比较
//假设当前剩下第i堆，那么当前局面为a[i]^res=k,res=k^a[i];如果res>a[i]那么拿走res-a[i]就可以使之变成0
//由于现在先手变成了后手，当异或和为0为必胜，统计个数即可 
int n;
int a[MAX_LEN+5]; 
int main()
{
	int i,j,k,c,res;
	while(scanf("%d",&n)!=EOF)
	{
		if (n==0)
		  break;                    
		for(i=0;i<n;i++)
		  scanf("%d",&a[i]);
		k=0;
		for(i=0;i<n;i++)
		  k^=a[i];
		if(k==0)
		{
			printf("%d\n",k);
			continue;
		}
		c=0;
		for(i=0;i<n;i++)
		{
			res=(k^a[i]);
			if(res<a[i])
			  c++;            
		}               
		printf("%d\n",c);         
	}
	return 0;
}
