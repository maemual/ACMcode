#include<iostream>
#include<cstdio>
using namespace std;

typedef long long ll;
ll gcd(ll a, ll b){
    return b==0?a:gcd(b, a % b);
}
ll lca(ll a, ll b){
    return a / gcd(a, b) * b;
}
int main()
{
    ios::sync_with_stdio(false);
    ll x, y, a, b;
    cin >> x >> y >> a >> b;
    ll lm = lca(x, y);
    while (a % lm != 0) a++;
    while (b % lm != 0) b--;
    cout << b / lm - a / lm + 1 << endl;
    return 0;
}
