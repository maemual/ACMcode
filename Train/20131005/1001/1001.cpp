#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str;
    while (1){
        cin >> str;
        if (str == "0")
            break;
        int len = str.length();
        cout << str << ": ";
        for (int i = 0; i < len; i++){
            if (str[i] > '3' && str[i] < '9')
                str[i]--;
            else if (str[i] == '9')
                str[i] -= 2;
        }
        int ans = 0;
        for (int i = 0; i < len; i++){
            ans *= 8;
            ans += str[i] - '0';
        }
        cout << ans << endl;
    }
    return 0;
}
