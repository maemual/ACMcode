#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAX_LEN 55
bool cmp(int a,int b)
{
	return a > b;
}
int main()
{
	int a[MAX_LEN];
	int n,k;
	scanf("%d %d",&n,&k);
	int i,j;
	for (i = 0; i < n; i++)
	  scanf("%d",&a[i]);
	sort(a,a+n,cmp);
	
	if (k > n)
	  printf("-1\n");
	else
	  printf("%d %d\n",a[k-1],a[k-1]);
	return 0;
}
