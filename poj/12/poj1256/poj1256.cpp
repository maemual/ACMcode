#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int val(char c)
{
    if( c >= 'A' && c <= 'Z')
    {
        return 2 * (c - 'A');
    }
    else
    {
        return 2 * (c - 'a') + 1;
    }
}

bool cmp(char a, char b)
{
    return val(a) < val(b);
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        sort(s.begin(),s.end(),cmp);
        do
        {
            cout << s << endl;
        }while (next_permutation(s.begin(),s.end(),cmp));
    }
    return 0;
}
