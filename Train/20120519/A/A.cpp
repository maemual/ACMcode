#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    int n;
    cin >> n;
    while (n--)
    {
        cin >> s;
        int count=0;
        for (int i=0;i<s.size();i++)
        {
            if (s[i]=='0')
                count++;
        }
        cout<<count<<endl;
    }
    return 0;
}
