#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

typedef long long ll;
ll GCD(ll a, ll b){
	return b==0?a:GCD(b, a % b);
}
ll LCM(ll a, ll b){
	return a / GCD(a, b) * b;
}
int main()
{
	int T;
	scanf("%d", &T);
	ll N, A, B;
	ll lcm;
	while (T--){
		cin >> N >> A >> B;
		lcm = LCM(A, B);
		ll k = 0; 
		ll sum = 0;
		int pa = 0, pb = 0;
		while (k < lcm){
			if (pa < A && pb < B){
				ll mmin = min(A - pa, B - pb);	
				sum += mmin * abs(pa - pb);
				k += mmin;
				pa = (pa + mmin) % A;
				pb = (pb + mmin) % B;
			}else{
				sum += abs(pa - pb);
				k++;
				pa = (pa + 1) % A;
				pb = (pb + 1) % B;
			}
			//cout << k << endl;
		}
		ll x = N / lcm;
		ll y = N % lcm;
		k = 0;
		pa = pb = 0;
		ll sum2 = 0;
		while (k < y){
			if (pa < A && pb < B){
				ll mmin = min(A - pa, B - pb);
				if (k + mmin > y){
					sum2 += (y - k) * abs(pa - pb);
					break;
				}
				k += mmin;
				sum2 += mmin * abs(pa - pb);
				pa = (pa + mmin) % A;
				pb = (pb + mmin) % B;
			}else{
				sum2 += abs(pa - pb);
				k++;
				pa = (pa + 1) % A;
				pb = (pb + 1) % B;
			}
			//cout << k << endl;
		}
		//cout << sum << endl;
		//cout << sum2 << endl;
		cout << sum * x + sum2 << endl;
		//cout << sum << endl;
	}
	return 0;
}
