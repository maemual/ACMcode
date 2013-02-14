#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX_LEN 100005
#define MY_MAX(a,b) (((a)>(b))?(a):(b))
long long hei[MAX_LEN];
int main()
{
	int n,m;
	int i;
	scanf("%d",&n);
	for (i = 1; i <= n; i++)
	  cin >> hei[i];
	scanf("%d",&m);
	int w,h;
	long long min = 1;
	long long next;
	for (i = 0; i < m; i++)
	{
		scanf("%d %d",&w,&h);
		next = MY_MAX(min,hei[w]);
		cout << next << endl;
		min = next + h;
	}
	return 0;
}
