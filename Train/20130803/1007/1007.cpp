/*************************************************************************
	> File Name: 1007.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年08月03日 星期六 13时19分22秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

typedef long long ll;
ll gcd(ll a, ll b){
	return b==0?a:gcd(b, a % b);
}
int main()
{
	int T;
	int n;
	cin >> T;
	while (T--){
		cin >> n;
		if (n == 2){
			printf("1\n");
			continue;
		}
		if (n % 2 == 0){
			ll a = n / 2;
			ll b = a;
			if (a % 2 == 0){
				cout << (a - 1) * (b + 1) << endl;
				continue;
			}else{
				cout << (a - 2) * (b + 2) << endl;
				continue;
			}
		}else{
			ll a = (int)n / 2;
			ll b = a + 1;
			cout << a * b << endl;
		}
	}
	return 0;
}
