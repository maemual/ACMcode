#include <cstdio>
const int MAX_LEN = 500000;
int a[MAX_LEN+5];
bool hash[10000000]={0};
int main()
{
	a[0] = 0;
	for (int i=1;i<=MAX_LEN;i++)
	{
		if (a[i-1]-i>0 && !hash[a[i-1]-i])
		{
			a[i] = a[i-1]-i;
			hash[a[i-1]-i] = true;
		}else{
			a[i] = a[i-1]+i;
			hash[a[i-1]+i] = true;
		}
	}
	int n;
	while (1)
	{
		scanf("%d",&n);
		if (n==-1)
		  break;
		printf("%d\n",a[n]);
	}
	return 0;
}
