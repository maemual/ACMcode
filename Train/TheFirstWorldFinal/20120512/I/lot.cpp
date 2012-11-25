#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
int a[10000005];
int main()
{
    int n;
    memset(a,0,sizeof(a));
    a[3]=a[5]=a[7]=a[9]=1;
    a[6]=a[10]=2;
    a[11]=3;
    for (int i=12;i<=10000000;++i)
    {
        if (i % 2 == 0)
        {
            a[i] = a[i/2]*2;
        }else a[i] = a[(i+1)/2]+a[(i-1)/2];
    }
    while (cin >> n)
    {
        printf("%d\n",a[n]);
    }
    return 0;
}
