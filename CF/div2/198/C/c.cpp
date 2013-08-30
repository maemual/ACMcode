#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;
#define llg long long
template<typename T> inline void checkMin(T& a, T b) { if (a > b) a = b; }
template<typename T> inline void checkMax(T& a, T b) { if (a < b) a = b; }
template<class T> inline T Min(T x,T y){return (x>y?y:x);} 
template<class T> inline T Max(T x,T y){return (x<y?y:x);}
llg n,m;
llg a[100010];
llg gcd(llg a,llg b)
{
    if(a < b)	{llg t=a;a=b;b=t;}
    if(a%b == 0)	return b;
    else	return gcd(b,a%b);
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for(llg i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort(a + 1,a + 1 + n);
    llg sum1 = 0,sum2 = 0;
    for(llg i = 1;i <= n;i++)
    {
        sum2 += a[i];
        sum1 += ((i-1) - (n - i))*a[i];
    }
    llg ans = sum1*2 + sum2;
    llg tmp = gcd(ans,n);
    cout<<ans/tmp<<" "<<n/tmp<<endl;
    return 0;
}
