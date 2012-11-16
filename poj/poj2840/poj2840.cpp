#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int a[]={12,13,14,15,16,17,18,19,20,21,22,23,24,1,2,3,4,5,6,7,8,9,10,11};
    while (t--)
    {
        int hour,minite;
        char ch;
        cin >> hour >> ch >> minite;
        if (minite != 0)
        {
            cout << '0' << endl;
            continue;
        }
        else
            cout << a[hour] << endl;
    }
    return 0;
}
