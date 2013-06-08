#include <iostream>
#include <string.h>
using namespace std;
int main(void)
{
    int n,m,c,i,maxpower,sumpower,title = 1,y;
    int state[50];
    int power[1000];
    int action;
    while(cin>>n>>m>>c && n && m && c)
    {
        y = 1;
        maxpower = 0; sumpower = 0;
        memset(state,0,sizeof(state));
        for(i=1; i<=n; i++)
            cin>>power[i];
        for(i=0; i<m; i++)
        {
            cin>>action;
            if(state[action] == 0)
            {
                state[action] = 1;
                sumpower += power[action];
                if(sumpower > c)
                {
                    y = 0;
                    continue;
                }
            }
            else
            {
                state[action] = 0;
                sumpower -= power[action];
            }
            if(sumpower > maxpower)
                maxpower = sumpower;
        }
        if( y )
        {
            cout << "Sequence " << title << endl;
            cout << "Fuse was not blown." << endl;
            cout << "Maximal power consumption was " << maxpower << " amperes." << endl;
        }
        else
        {
            cout << "Sequence " << title << endl;
            cout <<"Fuse was blown."<< endl;
        }
        cout<<endl;
        title++;
    }
return 0;
}

