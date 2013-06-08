#include<stdio.h>
#define MAX 30000
int n;

int value[MAX];///记录原始数组
int opt[MAX+1];///记录长度为k的最长递增序列的结尾元素,下标从1开始
//int len[MAX];///记录以value[k]结尾的最长递增子序列的长度

int LIS(const int value[],const int n)
{
	int i,j;
	int size=1;
	opt[1]=value[0];
	//len[0]=1;
	for(i=1;i<n;i++)
	{
		if(value[i]<opt[1]) j=1;//<=换为<  后者为最长不减子序列
		else if(value[i]>=opt[size]) j=++size;// > 换为: >=  后者为最长不减子序列
		else j=binary_search(opt,size,value[i]);
		opt[j]=value[i];
		//len[i]=j;
	}
	return size;
}
int binary_search(const int opt[],const int size,const int value)
{
	int left=1;
	int right=size;
	int mid;
	while(left<=right)
	{
		mid=(left+right)>>1;
		if(value>=opt[mid] && value<opt[mid+1]) return mid+1;// >&&<= 换为: >= && <  后者为最长不减子序列
		else if(value<opt[mid+1]) right=mid-1;
		else left=mid+1;
	}
}
void reverse(int *value,int n)
{
	int i;
	int cache;
	int cnt=n>>1;
	for(i=0;i<cnt;i++)
	{
		cache=value[n-i-1];
		value[n-i-1]=value[i];
		value[i]=cache;
	}
}
int main()
{
	int i,j;
	int ans;
	int max;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&value[i]);
	}
	ans=LIS(value,n);
	reverse(value,n);

	max=LIS(value,n);
	if(ans<max) ans=max;
	printf("%d",n-ans);
	return 0;
}

