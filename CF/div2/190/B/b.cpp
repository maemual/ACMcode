#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr, arr + 3);
    int r = arr[0], g = arr[1], b = arr[2];
    int sum = 0;
    if (r >= 3 && g % 3 == 2 && b % 3  == 2){
        sum++;
        r--;g--;b--;
    }
    if (r % 3 == 2 && g >= 3 && b % 3  == 2){
        sum++;
        r--;g--;b--;
    }
    if (r % 3 == 2 && g % 3 == 2 && b >= 3){
        sum++;
        r--;g--;b--;
    }
    sum += r / 3;
    sum += g / 3;
    sum += b / 3;
    r %= 3;
    g %= 3;
    b %= 3;
    while (r >= 1 && g >= 1 && b >= 1){
        sum++;
        r--;g--;b--;
    }
    cout << sum << endl;
    return 0;
}
