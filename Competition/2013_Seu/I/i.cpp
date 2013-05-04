#include <string.h>
#include <stdio.h>
#define	maxn 101
long long N;
struct Matrix
{
	long long m[maxn][maxn];
	public:
	Matrix(long long x,long long y)
	{
		long long i,j;
		for(i=0;i<x;i++)
			for(j=0;j<y;j++)
			{
				if(i==j)	m[i][j]=1;
				else	m[i][j]=0;
			}
	}
	Matrix()
	{
		for(long long i=0;i<N;i++)
			for(long long j=0;j<N;j++)
			{
				if(i==j)	m[i][j]=1;
				else	m[i][j]=0;
			}
	}

	friend Matrix mul(Matrix &m1,Matrix &m2)
	{
		long long i,j,k;
		Matrix temp;
		memset(temp.m,0,sizeof(temp.m));
		for(i=0;i<N;i++)
			for(j=0;j<N;j++)
				if(m1.m[i][j])
				{
					for(k=0;k<N;k++)
						temp.m[i][k]+=m1.m[i][j]*m2.m[j][k];
				}
		return temp;
	}
	friend Matrix cheng(Matrix &m1,Matrix &m2)
	{
		long long i,j,k;
		Matrix temp;
		memset(temp.m,0,sizeof(temp.m));
		for(i=0;i<1;i++)
			for(j=0;j<N;j++)
				if(m1.m[i][j])
				{
					for(k=0;k<N;k++)
						temp.m[i][k]+=m1.m[i][j]*m2.m[j][k];
				}
		return temp;
	}

	friend Matrix quickpow(Matrix &M,long long n)
	{
		Matrix temp,t=M;
		while(n)
		{
			if(n&1)	temp=mul(temp,t);
			n=n>>1;
			t=mul(t,t);
		}
		return temp;
	}
};

int main()
{
	long long i,j,k,kk,t;
	long long n,m;
	char s[2];
	while(scanf("%lld %lld %lld",&n,&k,&m)!=EOF)
	{
		if(n==0 && k==0 && m==0)	break;
		N=n+1;
		Matrix a(N,N),temp(N,N);
		while(m--)
		{
			scanf("%s",s);
			if(s[0]=='a')
			{
				scanf("%lld",&i);
				temp.m[0][i]++;
			}
			if(s[0]=='b')
			{
				scanf("%lld",&i);
				for(j=0;j<N;j++)
					temp.m[j][i]=0;
			}
			if(s[0]=='c')
			{
				scanf("%lld %lld",&i,&j);
				for(kk=0;kk<N;kk++)
				{
					t=temp.m[kk][i];
					temp.m[kk][i]=temp.m[kk][j];
					temp.m[kk][j]=t;
				}
			}
		}
		temp=quickpow(temp,k);
		a=cheng(a,temp);
		for(i = 1;i <= n;i++)
		{
			if(i == 1 )printf("%lld",a.m[0][i]);
			else  printf(" %lld",a.m[0][i]);
		}
		printf("\n");
	}
	return 0;
}

