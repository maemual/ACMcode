#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int x;
		long long sum = 0;
		for (int i = 0;i<n;++i)
		{
			scanf("%d",&x);
			sum += x;
		}	 
		if (sum % 2 == 0)
		  printf("%lld\n",sum / 2 - 1);
		else 
		  printf("%lld\n",sum / 2);
	}
	return 0;
}
