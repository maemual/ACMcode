/*************************************************************************
	> File Name: d.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年03月17日 星期日 12时11分11秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

#define MY_MAX(a, b) ((a) > (b) ? (a) : (b))

typedef long long ll;
int main()
{
	ll x,y,m,n,L;
	double t;
	ll date;
	ll begin,end;
	while (scanf("%lld %lld %lld %lld %lld",&x,&y,&m,&n,&L) != EOF)
	{
		if (m == n){
			printf("Impossible\n");
			continue;
		}
		t = (x-y)*1.0 / (m-n);
		if (t < 0){
			printf("Impossible\n");
			continue;
		}
		date = (ll)(t - 0.5) + 1;
		//printf("%lld\n",date);
		begin = MY_MAX(x,y);
		end = begin - L;
		if ((x - t*m) < end){
			printf("Impossible\n");
			continue;
		}
		printf("%lld\n",date);
	}
	return 0;
}
