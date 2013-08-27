#include<iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int arr[100005];
    for (int i = 1; i <= m; i++){
        cin >> arr[i];
    }
    arr[0] = 1;
    long long sum = 0;
    for (int i = 1; i <= m; i++){
        if (arr[i] > arr[i-1]){
            sum += arr[i] - arr[i-1];
        }else if (arr[i] < arr[i-1]){
            sum += n - arr[i-1] + arr[i];
        }
    }
    cout << sum << endl;
    return 0;
}
