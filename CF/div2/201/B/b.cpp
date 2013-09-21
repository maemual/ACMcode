#include<iostream>
using namespace std;

#define MAX_LEN 100005
int arr[MAX_LEN], brr[MAX_LEN];
int main()
{
    int n;
    ios::sync_with_stdio(false);
    cin >> n;
    bool flag = false;
    int cnt = 0;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        brr[i] = arr[i];
        if (arr[i] != i) flag = true;
        if (arr[i] == i) cnt++;
    }
    if (flag){
        bool flag2 = false;
        for (int i = 0; i < n; i++){
            if (arr[i] == i) continue;
            if (brr[arr[brr[i]]] == arr[i]){
                flag2 = true;
                break;
            }
        }
        if (flag2)
            cout << cnt + 2 << endl;
        else
            cout << cnt + 1 << endl;
    }else{
        cout << n << endl;
    }
    return 0;
}
