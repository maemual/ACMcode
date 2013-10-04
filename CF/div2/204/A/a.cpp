#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

#define MAX_LEN 1005
int arr[MAX_LEN];

int main()
{
    int n;
    cin >> n;
    int cnt5 = 0, cnt0 = 0;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        if (arr[i] == 0)
            cnt0++;
        else
            cnt5++;
    }
    if (cnt0 == 0){
        cout << -1 << endl;
        return 0;
    }
    if (cnt5 < 9){
        cout << 0 << endl;
        return 0;
    }
    //sort(arr, arr + n, greater<int>());
    cnt5 /= 9;
    cnt5 *= 9;
    for (int i = 0; i < cnt5; i++)
        cout << "5";
    for (int i = 0; i < cnt0; i++)
        cout << "0";
    cout << endl;
    return 0;
}
