#include <stdio.h>
#include <math.h>
#include <string.h>
#define N 100005
#define inf  1<<30
#define MOD 9973
#define LL long long
bool flag[100005];
int prime[100005],cnt=0;
//先打出sqrt(上界)的素数表
void Prime(){
	for(int i=2;i<=47000;i++){
		if(flag[i])
			continue;
		prime[cnt++]=i;
		for(int j=2;j*i<=47000;j++)
			flag[i*j]=true;
	}
}
bool isprime[1000005];
int a[1000005],c;
int main(){
	int l,r;
	Prime();
	while(scanf("%d%d",&l,&r)!=EOF){
		memset(isprime,true,sizeof(isprime));
		if(l==1) l=2;
		//利用之前的素数，进行二次筛选，注意防溢出
		for(int i=0;i<cnt&&(LL)prime[i]*prime[i]<=r;i++)
		{
			int s=l/prime[i]+(l%prime[i]>0);
			if(s==1)
				s=2;
			//不能从1开始，不然就把素数给判成合数了
			for(int j=s;(LL)j*prime[i]<=r;j++)
				if((LL)j*prime[i]>=l)
			    	isprime[j*prime[i]-l]=false;
		}
		c=0;
		for(int i=0;i<=r-l;i++)
			if(isprime[i])
				a[c++]=i+l;
		//少于两个素数
		if(c<2){
			puts("There are no adjacent primes.");
			continue;
		}
		int x1=0,x2=0,y1=0,y2=inf;
		for(int i=1;i<c;i++)
		{
			if(a[i]-a[i-1]>x2-x1){
				x1=a[i-1];
				x2=a[i];
			}
			if(a[i]-a[i-1]<y2-y1){
				y1=a[i-1];
				y2=a[i];
			}
		}
		printf("%d,%d are closest, %d,%d are most distant.\n",y1,y2,x1,x2);
	}
	return 0;
}
