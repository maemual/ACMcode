#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<iostream>
using namespace std;

int main()
{
    long long m, R;
    cin >> m >> R;
    if (m == 1){
        printf("%.10lf\n", 2.0 * R);
        return 0;
    }
    double ans = 0;
    for (int i = 1; i < m; i++){
       //ans += 1;
       ans += (1 + 2 * (m - i) - 1) * (m - i) / 2;
    }
    cout << ans << endl;
    ans *= 2;
    cout << ans << endl;
    ans += 2 * m;
    cout << ans << endl;
    ans += m * m;
    ans += m * (m - 1) * sqrt(2);
    printf("%.10lf\n", ans * R / m / m);
    /*
    long long num = 0;
    //num += m == 2?0:(((m-2)*(m-2)+2)*(m-2));
    //num += ((m - 1) * (m - 1) + 1) * 2;
    for (int i = m - 1; i >= m / 2; i--){
        num += (m - i) + (1 + 2 * i - 1) * i / 2;
    }
    num *= 2;
    if (m % 2 == 1){
        for (int i = 1; i < m / 2; i++){
            num += (2 * i + 1) * 2;
        }
        num += 3;
    }
    num += m * m;
    printf("%.10lf\n", (num * 1.0 + sqrt(2) * (m - 1) * m) * R / (m * m));
    */
    return 0;
}
