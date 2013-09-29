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
int n,m;
int a[10000000];
int v;
int min2[100],flagx2[100];
int cntb = 0;

int main()
{
    scanf("%d",&v);
    int minn = 2000000;
    int flag1 = 0,flag2 = 0;
    for(int i = 1;i <= 9;i++)
    {
        scanf("%d",&a[i]);
        if(minn >= a[i])
        {
            minn = a[i];
            flag1 = i;
        }
    }
    if(minn > v)
    {
        printf("-1\n");
        return 0;
    }
    int cnt = 0;
    cnt = v / minn;
    int left = v - cnt*minn;
    for(int i = 9;i > flag1;i--)
    {
        int cha = a[i] - minn;
        if(cha <= 0)	continue;
        while(left >= cha && cnt >= 1)
        {
            printf("%d",i);
            left -= cha;
            cnt--;
        }
    }
    for(int i = 1;i <= cnt;i++)
        printf("%d",flag1);
    printf("\n");
    return 0;
}
