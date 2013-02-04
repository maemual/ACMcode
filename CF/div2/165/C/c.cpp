#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

#define MAX_LEN 100005
struct node{
	int k,num;
}arr[MAX_LEN];
bool cmp(node a,node b)
{
	return a.k < b.k;
}
int main()
{
	int n;
	scanf("%d",&n);
	memset(arr,0,sizeof(arr));
	for (int i = 0; i < n; i++)
	  scanf("%d %d",&arr[i].k,&arr[i].num);
	sort(arr,arr+n,cmp);
	for (int i = 0; i < n; i++)
	{

	}
	return 0;
}
