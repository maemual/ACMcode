#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
typedef long long ll;
#define MOD 1000000007
ll powermod(ll a,ll b,ll c)
{
	ll ans = 1;
	while(b)
	{
		if(b&1)		//b是奇数，即二进制最后一位为1
		   ans*=(ans*a)%c;
		a=(a*a)%c;      //权值不断开方，同时可以模c无影响
		b=b>>1;		//不断右移除2
	}
	return ans;
}
int main()
{
	string str;
	int n;
	cin >> str;
	cin >> n;
	int len = str.length();
	long long ans1 = 0;
	for (int i = 0; i < len; i++){
		if (str[i] == '0' || str[i] == '5'){
			ans1 += powermod(2, i, MOD);
		}
	}
	ans1 %= MOD;
	long long ans2 = powermod(2, (n - 1) * len - 1, MOD);
	ans2 %= MOD;
	long long ans = (ans1 * ans2) % MOD;
	cout << ans1 << endl;
	cout << ans2 << endl;
	cout << ans << endl;
	return 0;
}
