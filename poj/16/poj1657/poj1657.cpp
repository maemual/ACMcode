#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int t;cin>>t;
    while (t--)
    {
        string str1,str2;
        cin>>str1>>str2;
        int x = abs(str1[0]-str2[0]);
        int y = abs(str1[1]-str2[1]);
        if (x+y==0)
        {
            cout<<"0 0 0 0"<<endl;
            continue;
        }

        if (x>y)
            cout<<x<<" ";
        else
            cout<<y<<" ";

        if (x==0||y==0||x==y)
            cout<<1<<" ";
        else
            cout<<2<<" ";

        if (x==0||y==0)
            cout<<1<<" ";
        else
            cout<<2<<" ";

        if (x==y)
            cout<<1<<endl;
        else
        {
            if (abs(x-y)%2==0)
                cout<<2<<endl;
            else
                cout<<"Inf"<<endl;
        }
    }
    return 0;
}

