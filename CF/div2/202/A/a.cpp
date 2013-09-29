#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int m25, m50, m100;
    m25 = m50 = m100 = 0;
    int x;
    bool flag = true;
    for (int i = 0; i < n; i++){
        cin >> x;
        if (!flag) continue;
        if (x == 25){
            m25++;
        }else if (x == 50){
            if (m25 > 0){
                m25--;
                m50++;
            }else
                flag = false;
        }else{
            if (m25 > 0 && m50 > 0){
                m100++;
                m25--;
                m50--;
            }else if (m25 >= 3){
                m100++;
                m25-=3;
            }else
                flag = false;
        }
    }
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
