/*************************************************************************
	> File Name: c.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年03月31日 星期日 14时00分24秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;
#define llg long long
#define MOD 1000000007
long long arr[100005];
llg m[100005];
llg pow(llg a)
{
	llg b = MOD-2;
	llg p = MOD;
	llg res = 1;
	a = a%p;
	while(b)
	{
		if(b&1) res = (res*a)%p;
		a = a*a%p;
		b = b>>1;
	}
	return res;
}
int main()
{
	arr[1] = 0;
	arr[2] = 0;
	arr[3] = 1;
	arr[4] = 2;
	arr[5] = 13;
	for (llg n = 6; n <= 100000; n++){
		m[n] = pow(n-2);
		if (n % 2 == 0)
			arr[n] = ((((n*n-2*n) % MOD)*arr[n-1] % MOD + n*arr[n-2] % MOD-4)*m[n]) % MOD;
		else
			arr[n] = ((((n*n-2*n) % MOD)*arr[n-1] % MOD + n*arr[n-2] % MOD+4)*m[n]) % MOD;
	}
	int x;
	while (scanf("%d",&x) != EOF){
		cout << arr[x] << endl;
	}
	return 0;
}
