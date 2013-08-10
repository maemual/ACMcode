#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;
#define llg long long
template<typename T> inline void checkMin(T& a, T b) { if (a > b) a = b; }
template<typename T> inline void checkMax(T& a, T b) { if (a < b) a = b; }
template<class T> inline T Min(T x,T y){return (x>y?y:x);} 
template<class T> inline T Max(T x,T y){return (x<y?y:x);}
int n;
int a[100010];
int b[100010];
int c[100010];
int k;
int get(int x)
{
    int i = 0;
    while(x)
    {
        x = x >> 1;
        i++;
    }
    return i;
}
bool check(int num,int i)
{
    if((num>>i)&1)	return true;
    return false;
}
int main()
{
    scanf("%d",&n);
    int maxn = -1;
    for(int i = 0;i < n;i++)
    {
        scanf("%d",&a[i]);
        c[i] = get(a[i]);
        //printf("%d c = %d\n",a[i],c[i]);
        maxn = Max(maxn,c[i]);
    }
    maxn++;
    int flag = 1;
    while(flag)
    {
        maxn--;
        int count = (1<<(maxn-1))-1;
        int tmp = (1<<(maxn-1));
        k = 0;
        for(int i = 0;i < n;i++)
        {
            if(c[i] >= maxn && check(a[i],maxn-1))
            {
                count=count&a[i];
                b[k++] = a[i];
            }
        }
        if(count == 0)	flag = 0;
    }

    printf("%d\n",k);
    printf("%d",b[0]);
    for(int i = 1;i < k;i++)
    {
        printf(" %d",b[i]);
    }
    return 0;
}
