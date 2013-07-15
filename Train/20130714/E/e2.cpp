#include <iostream>
#include <cstdio>
#include <cstring> 
//#include <time.h>
#define LL long long
using namespace std;
const int maxn=502;
const int mod=1e8+7;
int n;
LL tmp[maxn][maxn],e[maxn][maxn],c[maxn][maxn];
void mul(LL a[][maxn],LL b[][maxn])
{
	memset(c,0,sizeof(c));

	for(int k=0;k<n;++k)
	{
		if(a[0][k])
		for(int j=0;j<n;++j)
		{
			c[0][j]+=a[0][k]*b[k][j];
			if(c[0][j]>=mod){c[0][j]%=mod;}
		}
	}
	for(int i=1;i<n;++i)
	{
		for(int j=0;j<n;++j) 
		{
			c[i][j]=c[i-1][(j-1+n)%n];
		}
	}
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			b[i][j]=c[i][j];
		}
	}

}

void expo(LL a[][maxn],LL k)
{
	if(k==1){
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				e[i][j]=a[i][j];
			}
		}
		return;
	}
	memset(e,0,sizeof(e));
	for(int i=0;i<n;++i){e[i][i]=1;}
	while(k)
	{
		if(k&1){mul(a,e);}
		mul(a,a);
		k>>=1;
	}
}
int main()
{

	LL m;
	LL dat[maxn];
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	//double st = clock();
	while(~scanf("%lld%lld",&n,&m))
	{
		memset(tmp,0,sizeof(tmp));
		for(int i=0;i<n;++i)
		{
			scanf("%lld",&dat[i]);
		}
		if(m<=n)
		{
			printf("%lld\n",dat[m-1]);continue;
		}
		int l,r;
		for(int i=0;i<n;++i)
		{
			l=(i-1)<0?(n-1):(i-1);
			r=(i+1)>(n-1)?0:(i+1);
			tmp[i][l]=tmp[i][r]=1;
		}
		int k,t;

		if(m%n!=0)
		{
			k=m%n-1;
			expo(tmp,(LL)m/n);
		}
		else
		{
			k=n-1;
			expo(tmp,(LL)m/n-1);
		}
		LL ans[maxn];
		memset(ans,0,sizeof(ans));
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				ans[i]+=e[i][j]*dat[j];
				if(ans[i]>=mod){ans[i]%=mod;}
			}
		}
		printf("%lld\n",ans[k]);
	}
	//cerr<<(clock()-st)/CLOCKS_PER_SEC<<endl;
	return 0;
}
