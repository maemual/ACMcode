#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double Vs, R, C, w, Vr;
    int n;
    cin >> Vs >> R >> C >> n;
    while (n--)
    {
        cin >> w;
        Vr = Vs * R * C * w / sqrt(1 + C * w * w);
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(3);
        cout << Vr << endl;
    }
    return 0;
}
