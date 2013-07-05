#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
typedef long long ll;
#define MOD 1000000007
//计算a^bmodn     
ll modexp(ll a,ll b,ll n)     
{    
	ll ret = 1;
	ll tmp = a;
	while(b){
		if (b & 0x1) ret = ret * tmp % n;
		tmp = tmp * tmp % n;
		b >>= 1;
	}
	return ret;
} 
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
	string str;
	int n;
	cin >> str;
	cin >> n;
	int len = str.length();
	ll ans1 = 0;
	ll ans = 0;
	for (int i = 0; i < len; i++){
		if (str[i] == '0' || str[i] == '5'){
			ll tmp1 = modexp(2, i, MOD);
			ll tmp2 = modexp(2, n * len, MOD) - 1;
			ll tmp3 = modexp(2, len, MOD) - 1;
			ll x, y;
			ExGCD(tmp3, MOD, x, y);
			ll tmp4 = tmp2 * (x + MOD) % MOD;
			ans += (tmp1 % MOD) * (tmp4 % MOD) % MOD;
		}
	}
	cout << ans << endl;
	return 0;
}
