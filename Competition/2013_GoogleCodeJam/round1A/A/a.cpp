/*************************************************************************
	> File Name: a.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年04月27日 星期六 09时13分10秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

typedef long long ll;
int main()
{
	int cas;
	scanf("%d",&cas);
	ll r,t;
	for (int k = 1; k <= cas; k++){
		scanf("%lld %lld", &r, &t);
		r *= 2;
		ll ans;
		for (int n = 1; n <= t; n++){
			if ((r + 2 * n -1) * n > t){
				ans = n - 1;
				break;
			}
		}
		printf("Case #%d: %lld\n",k,ans);
	}
	return 0;
}
