#include <cstdio>
#include <algorithm>
using namespace std;

bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	int a[50];
	for (int i = 0; i < n; i++)
	  scanf("%d",&a[i]);
	sort(a,a+n,cmp);
	int use = 0;
	int	i = 0;
	int flag = 0;
	while (i < n)
	{
		if (k >= m)
		{
		//	flag = 1;
			break;
		}
		k += a[i] - 1;
		i++;
		use++;
	}
//	printf("%d\n",use);
	if (k >= m)
		printf("%d\n",use);
	else
	  printf("-1\n");
//	printf("%d",a[0]);
	return 0;
}
