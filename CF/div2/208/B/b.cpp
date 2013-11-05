#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string str = "<3";
    string tmp;
    for (int i = 0; i < n; i++){
        cin >> tmp;
        str += tmp + "<3";
    }
    cin >> tmp;
    int len1 = str.length();
    int len2 = tmp.length();

    int p = len1 - 1, q = len2 - 1;
    while (p >= 0 && q >= 0){
        if (str[p] == tmp[q]){
            p--;
        }
        q--;
    }
    if (p > 0)
        printf("no\n");
    else
        printf("yes\n");
    return 0;
}
