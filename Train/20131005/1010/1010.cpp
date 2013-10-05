#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int mmap[] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
int arr[5005], brr[5005];
int main()
{
    int T;
    int n, m;
    cin >> T;
    string str;
    while (T--){
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int i = 0; i < m; i++){
            cin >> str;
            int len = str.length();
            int tmp = 0;
            for (int j = 0; j < len; j++){
                tmp *= 10;
                tmp += mmap[str[j] - 'a'];
            }
            brr[i] = tmp;
        }
        for (int i = 0; i < n; i++){
            int cnt = 0;
            for (int j = 0; j < m; j++){
                if (arr[i] == brr[j])
                    cnt++;
            }
            cout << cnt << endl;
        }
    }
    return 0;
}
