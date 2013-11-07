#include<iostream>
#include<cstdio>
#include<vector>
#include<string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    vector<int> vec;
    vec.clear();
    int len = str.length();
    int sum2 = 0;
    for (int i = 0; i <= len - 5; i++){
        if (str[i] == 'h' && str[i+1] == 'e' && str[i+2] == 'a' && str[i+3] == 'v' && str[i+4] == 'y')
            vec.push_back(1);
        else if (str[i] == 'm' && str[i+1] == 'e' && str[i+2] == 't' && str[i+3] == 'a' && str[i+4] == 'l'){
            vec.push_back(2);
            sum2++;
        }
    }
    len = vec.size();
    long long ans = 0;
    for (int i = 0; i < len; i++){
        if (vec[i] == 1){
           ans += sum2;
        }else
            sum2--;
    }
    cout << ans << endl;
    return 0;
}
