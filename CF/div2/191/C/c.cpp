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
int main()
{
	/*
	ll x;
	cin >> x;
	cout << modexp(2, x, MOD) << endl;
	*/
	string str;
	int n;
	cin >> str;
	cin >> n;
	int len = str.length();
	ll ans1 = 0;
	ll ans = 0;
	for (int i = 0; i < len; i++){
		if (str[i] == '0' || str[i] == '5'){
			//ans1 += modexp(2, i, MOD);
			ll tmp1 = modexp(2, i, MOD);
			ll tmp2 = modexp(2, len, MOD);
			ll tmp3 = modexp(tmp2, n, MOD);
			ans1 += tmp1 * ((tmp3 - 1) % MOD) / ((tmp2 - 1) % MOD);
			ans += ans1 % MOD;
		}
	}
	cout << ans << endl;
	/*
	ans1 %= MOD;
	long long ans2 = modexp(2, (n - 1) * len, MOD);
	ans2 %= MOD;
	long long ans = (ans1 * ans2) % MOD;
	//cout << ans1 << endl;
	//cout << ans2 << endl;
	//cout << ans << endl;
	*/
	return 0;
}
