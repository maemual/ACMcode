#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int arr[55][55];
    memset(arr, 0, sizeof(arr));
    bool onEdge = false;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];
            if (arr[i][j] && (i == 0 || j == 0 || i == n - 1 || j == m - 1))
                onEdge = true;
        }
    }
    if (onEdge)
        cout << 2 << endl;
    else
        cout << 4 << endl;
    return 0;
}
