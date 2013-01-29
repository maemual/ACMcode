#include <cstdio>

int main()
{
	int n;
	scanf("%d",&n);
	int a[35],b[35];
	for (int i = 0; i < n ; i++)
	  scanf("%d %d",&a[i],&b[i]);
	int cnt = 0; 
	for (int i = 0; i < n; i++)
	{
		for (int j = 0 ; j < n; j++)
		{
			if (a[j] == b[i])
			  cnt++;
		}
	}
	printf("%d\n",cnt);
	return 0;
}
