#include <cstdio>
#include <cmath>
#include <algorithm>
const int MAX_LEN =1024;
int a[MAX_LEN+5];
int pow(int m,int n)
{
	int sum = 1;
	for (int i=0;i<n;i++)
	  sum*=m;
	return sum;
}
int main()
{
	int n,k,num;
	while (scanf("%d%d",&n,&k) != EOF)
	{
		int pp = pow(2,n);
		for (int i=0;i<pp;i++)
		  scanf("%d",&a[i]);
		num = a[k];
		std::sort(a,a+pp);
		if (num == a[pp-1])
		{
			printf("%d %d\n",n,n);
		}else {
			int pos = 0;
			for (int i=0;i<pp;i++)
			{
				if (a[i] == num)
				{
					pos = i;
					break;
				}
			}
			printf("%d %d\n",0,(int)(log(pos+1)/log(2)));
		}
	}
	return 0;
}
