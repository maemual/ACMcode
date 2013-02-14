#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#define MAX_LEN 100005
using namespace std;

int a[MAX_LEN];
int p[100000];
int q[30];
int f(int x)
{
	if (x == 0)
	  return 0;
	if (x < 100000 && p[x] != 0)
	  return p[x];
	if (x % 2 == 0)
	  return f(x / 2);
	else
	  return f(x / 2) + 1;
}
int main()
{
	int n;
	scanf("%d",&n);
	int i,j;
	memset(p,0,sizeof(p));
	memset(q,0,sizeof(q));
	for (i = 0; i < n; i++)
	  scanf("%d",&a[i]);
	for (i = 0; i < 100000; i++)
	  p[i] = f(i);
	for (i = 0; i < n; i++)
	  q[f(a[i])]++;

	long long ans = 0;
	long long temp;
	for (i = 0; i < 30; i++)
	{
		ans += (long long)(q[i] - 1)*q[i] / 2;
	}
	cout << ans << endl;
	return 0;
}
