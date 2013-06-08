#include <cstdio>
#include <cstdlib>
#include <climits>
int a,b,n;
int pow(int m,int k)
{
	int sum = 1;
	for (int i=0;i<k;i++)
	  sum *= m;
	return sum;
}
int main()
{
	while (scanf("%d%d",&b,&n) != EOF)
	{
		if (b == 0 && n == 0)
		  break;
		a = 1;
		int k = INT_MAX;
		int min = -1;
		while (1)
		{	
			if (k > abs(b - pow(a,n)))		  
			{	
				k = abs(b-pow(a,n));
				min = a;
			}
			if (b - pow(a,n) < 0)
			  break;
			a++;
		}
		printf("%d\n",min);
	}
	return 0;
}
