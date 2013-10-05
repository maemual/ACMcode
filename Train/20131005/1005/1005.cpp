#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
using namespace std;

long long mypow(int a, int b){
    long long res = 1;
    for (int i = 0; i < b; i++)
        res *= a;
    return res;
}
int main()
{
    int k;
    while (1){
        scanf("%d", &k);
        if (k == 0) break;
        int tmp = floor(sqrt(k));
        long long ans = 0;
        if (tmp * tmp == k){
            ans = (tmp - 1) / 2;
        }
        for (int z = 3; z <= 31; z++){
            if (z > k) break;
            for (long long x = 1; x <= k; x++){
                long long t1 = mypow(x, z);
                if (t1 > k / 2) break;
                for (long long y = x + 1; y <= k; y++){
                    long long t2 = mypow(y, z);
                    if (t1 + t2 > k) break;
                    long long t3 = (long long)x * y * z;
                    if (t3 > k) break;
                    long long tt = t1 + t2 + t3;
                    if (tt > k) break;
                    int temp = (int)tt;
                    if (temp == k)
                        ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
