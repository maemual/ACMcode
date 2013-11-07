#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[105];
    int sumL = 0, sumR = 0;
    for (int i = 1; i <= n; ++i){
        cin >> arr[i];
        sumR += arr[i];
    }
    int x, y;
    cin >> x >> y;
    int left = 1;
    while (left <= n){
        sumL += arr[left];
        sumR -= arr[left];
        if (sumL >= x && sumL <= y && sumR >= x && sumR <= y)
            break;
        ++left;
    }
    if (left > n)
        cout << 0 << endl;
    else
        cout << left + 1 << endl;
    return 0;
}
