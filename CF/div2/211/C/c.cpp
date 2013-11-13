#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    string str;
    cin >> str;
    string s = "";
    int len = str.length();
    for (int i = 0; i < len; ){
        if (i < len - 2 && str[i] == str[i+1] && str[i] == str[i+2]){
            i++;
        }else{
            s += str[i];
            i++;
        }
    }

    str = "";
    len = s.length();
    for (int i = 0; i < len; ){
        if (i < len - 3 && s[i] == s[i+1] && s[i+2] == s[i+3]){
            str += s[i];
            str += s[i+1];
            str += s[i+2];
            i += 4;
        }else{
            str += s[i];
            i++;
        }
    }
    cout << str << endl;
    return 0;
}
