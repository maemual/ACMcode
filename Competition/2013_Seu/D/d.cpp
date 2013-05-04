#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
#define llg long long
const llg mod = 1000000007;
llg f[40010][110];
int main()
{
	int i,j;
	int n,k;
	memset(f,0,sizeof(f));
	for(i = 0;i<=100;i++)
		f[0][i]=1;
	for(i = 1;i<=40000;i++)
	{
		f[i][1] = 1;
		for(j = 2;j <= 100;j++)
		{
			if(j>i)	f[i][j] = f[i][j-1];
			else
			{
				f[i][j] = f[i][j-1] + f[i-j][j];
				f[i][j] = f[i][j]%mod;
			}
		}
	}
	while(scanf("%d %d",&n,&k) !=EOF)
	{
		printf("%lld\n",f[n][k]);
	}
	return 0;
}
