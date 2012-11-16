#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a[100000];
        int n,s,w;
        int sum = 0;
        cin >> n >> s >> w;
        int g = s;
        for (int i=0; i<n; i++)
        {
            a[i] = g;
            if( a[i] == 0 )
                a[i] = g = w;
            if( g%2 == 0 )
                g = g / 2 ;
            else
                g = pow(g/2,w);
        }

        sum = n;
        for (int i =0;i< n-1;i++)
        {
            int temp=a[i];
            for (int j=i+1;j<n;j++)
            {
                temp = temp ^ a[j];
                if (temp != 0)
                    sum++;
            }
        }
        cout << sum << endl;
    }
}
