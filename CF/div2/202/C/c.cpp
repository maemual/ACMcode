#include<cstdio>
#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

int arr[100005];
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    long long cnt = arr[0];
    for (int i = 2; i < n; i++){
        arr[i] -= arr[0];
    }
    arr[0] = 0;
    cnt += arr[n-1]>arr[1]?arr[n-1]:arr[1];
    cout << cnt << endl;
    return 0;
}
