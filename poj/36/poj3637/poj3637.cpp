#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_LEN = 20000;
int a[MAX_LEN+5];
/*bool cmp(int a,int b)
{
	return a>b;
}*/
int main()
{
	int cas;
	scanf("%d",&cas);
	while (cas--)
	{
		int n;
		scanf("%d",&n);
		for (int i=0;i<n;i++)
		  scanf("%d",&a[i]);
		sort(a,a+n);
		int sum = 0;
		for (int i=n%3;i<n;i+=3)
			sum += a[i];
		printf("%d\n",sum);
	}
	return 0;
}
