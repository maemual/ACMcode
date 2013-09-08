#include<cstdio>
#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int arr[8];
    memset(arr, 0, sizeof(arr));
    int x;
    for (int i = 0; i < n; i++){
        cin >> x;
        arr[x]++;
    }
    if (arr[5] > 0 || arr[7] > 0){
        cout << -1 << endl;
        return 0;
    }
    int r1 = arr[1] - arr[4] - arr[3];
    int r2 = arr[2] - arr[4];
    int r6 = arr[6] - arr[3];
    if (r1 != r2 || r2 != r6){
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < arr[4]; i++){
        cout << 1 << " " << 2 << " " << 4 << endl;
    }
    for (int i = 0; i < arr[3]; i++){
        cout << 1 << " " << 3 << " " << 6 << endl;
    }
    for (int i = 0; i < r2; i++){
        cout << 1 << " " << 2 << " " << 6 << endl;
    }
    return 0;
}
