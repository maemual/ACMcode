#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
    string s1;
    string s2;
    getline(cin,s1);
    getline(cin,s2);
    for (string::size_type i = 0;i != s2.size();++i)
    {
        if (s2[i] == ' ')
        {
            cout << ' ';
        }
        else if (isupper(s2[i]))
        {
            char ch;
            s2[i] = tolower(s2[i]);
            ch = toupper(s1[s2[i]-'a']);
            cout << ch;
        }else cout << s1[s2[i]-'a'];
    }
    return 0;
}
