#include<iostream>
#include<algorithm>

using namespace std;

#define MAX_LEN 50000

int arr[MAX_LEN * 2 + 5];
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= 2 * n; i++)
        arr[i] = 2 * n - i + 1;
    for (int i = 1; i <= 2 * k - 1; i += 2)
        swap(arr[i], arr[i+1]);
    for (int i = 1; i <= 2 * n - 1; i++)
        cout << arr[i] << " ";
    cout << arr[2 * n] << endl;
    return 0;
}
