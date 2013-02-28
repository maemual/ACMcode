#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

const int MAX_LEN = 200005;
int arr[MAX_LEN];
int p[MAX_LEN];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    for (int i = 0; i < n; i++)
        scanf("%d",&arr[i]);

    sort(arr,arr+n,cmp);
    int x,y;
    memset(p,0,sizeof(p));
    for (int i = 0; i < k; i++)
    {
        scanf("%d %d",&x,&y);
        for (int j = x-1; j < y; j++)
            p[j]++;
    }
    sort(p,p+n,cmp);
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i] * p[i];
    }
    cout << sum << endl;
    return 0;
}
