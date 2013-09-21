#include<iostream>
#include<limits.h>
#include<algorithm>
using namespace std;

#define MAX_LEN 105
int arr[MAX_LEN];
int n;
int gcd(int a, int b){
    return b==0?a:gcd(b, a % b);
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    int g = 0;
    int mmax = 0;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        if (arr[i] > mmax)
            mmax = arr[i];
    }
    g = gcd(arr[0], arr[1]);
    for (int i = 2; i < n; i++){
        g = gcd(g, arr[i]);
    }
    g = mmax / g;
    if ((n - g) % 2 == 0)
        cout << "Bob" << endl;
    else
        cout << "Alice" << endl;
    return 0;
}
