#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int max = -999999999;
    int f,t;
    int joy;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d",&f,&t);
        if (t > k)
            joy = f - (t - k);
        else
            joy = f;
        if (joy > max)
            max = joy;
    }
    printf("%d\n",max);
    return 0;
}
