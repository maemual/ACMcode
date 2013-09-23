#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

string w[10] =  {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
int main()
{
    ios::sync_with_stdio(false);
    int L;
    double speed;
    string start;
    while (cin >> start >> L >> speed){
        double hours = L / speed;
        if (start == w[0])
            hours += 0;
        else if (start == w[1])
            hours += 8;
        else if (start == w[2])
            hours += 16;
        else if (start == w[3])
            hours += 24;
        else if (start == w[4])
            hours += 32;
        else if (start == w[5])
            hours += 40;
        else if (start == w[6])
            hours += 44;
        int hh = (int) hours;
        double h = (hours - hh) + (hh % 48);
        //cout << h << endl;
        if (h >= 0 && h <= 8)
            cout << w[0] << endl;
        else if (h > 8 && h <= 16)
            cout << w[1] << endl;
        else if (h > 16 && h <= 24)
            cout << w[2] << endl;
        else if (h > 24 && h <= 32)
            cout << w[3] << endl;
        else if (h > 32 && h <= 40)
            cout << w[4] << endl;
        else if (h > 40 && h <= 44)
            cout << w[5] << endl;
        else if (h > 44 && h <= 48)
            cout << w[6] << endl;
    }
    return 0;
}
