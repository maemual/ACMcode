/*************************************************************************
	> File Name: hdu1576.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年07月05日 星期五 14时35分32秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

#define MOD 9973
typedef long long ll;
void ExGCD(ll a, ll b, ll &x, ll &y){
	if (b == 0){
		x = 1;
		y = 0;
		return ;
	}
	ExGCD(b, a % b, x, y);
	ll t = x;
	x = y;
	y = t - (a / b) * y;
}
int main()
{
	int T;
	scanf("%d", &T);
	ll c, a;
	ll x, y;
	while (T--){
		cin >> c >> a;
		ExGCD(a, MOD, x, y);
		cout << c * (x + MOD) % MOD << endl;
	}
	return 0;
}
