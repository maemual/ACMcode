#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stdlib.h>
#include<cmath>
using namespace std;
#define eps 1e-6
int main()
{
    long long m,r,i;
    cin>>m>>r;
    double s =0,s1=0;
    for(i = 1 ; i <= m ; i++)
    {
        s = 0;
        if(i>2)
        s+=(i-2)*(i-1)*r+(i-2.0)*sqrt(2.0)*2*r+sqrt(2.0)*r+2*r;
        else
            s+=(i-1)*i*r+(i-1)*sqrt(2.0)*r;
        if(m-i>=2)
            s+=(m-i-1)*(m-i)*r+(m-i-1)*sqrt(2.0)*2*r+2*r+sqrt(2.0)*r+2*r;
        else
            s+=(m-i)*(m-i+1)*r+(m-i)*sqrt(2.0)*r+2*r;
        s1+=s/m;
    }
    printf("%.10f\n",s1/m);
    return 0;
}
