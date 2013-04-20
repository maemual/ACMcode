/*************************************************************************
	> File Name: g.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年04月20日 星期六 12时33分18秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll f[50];
int main()
{
	int i,j,k;
	f[0] = 1;f[1] = 1;
	for(i = 2;i<=30;i++)
		f[i]=f[i-1]+f[i-2];
	int T,a,c;
	ll b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %lld %d",&a,&b,&c);
		if(b <=0)
		{
			printf("-1\n");
			continue;
		}
		if (a == 1)
		{
			if(c == 1)
				printf("%lld\n",b);
			else if(c == 2)
				printf("%lld\n",b+1);
			else
				printf("%lld\n",b*f[c-1]+f[c-2]);
			continue;/**/
		}
		
		if ((b - f[a-2]) % f[a-1] != 0){
			printf("-1\n");
			continue;
		}
		ll a1 = (b-f[a-2])/f[a-1];
		if (a1 < 1){
			printf("-1\n");
			continue;
		}
		if (c == 1){
			printf("%lld\n", a1);
			continue;
		}
		printf("%lld\n",a1*f[c-1]+f[c-2]);
	}
	return 0;
}
