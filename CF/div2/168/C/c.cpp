#include <cstdio>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

#define MAX_LEN 100005
typedef long long ll;
set<ll> ans;
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int i;
    ll a[MAX_LEN];
    for (i = 0; i < n; i++)
        cin >> a[i];
    sort(a,a+n);
    for (i = n-1; i >= 0; i--)
    {
        if (ans.count((ll)a[i]*k) == 0)
            ans.insert(a[i]);
    }
    cout << ans.size() << endl;
    return 0;
}
