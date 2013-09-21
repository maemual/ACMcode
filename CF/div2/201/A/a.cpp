#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int arr[105];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    cout << arr[n-1];
    for (int i = 1; i < n-1; i++)
        cout << " " << arr[i];
    cout << " " << arr[0] << endl;
    return 0;
}
