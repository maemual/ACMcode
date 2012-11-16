#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_LEN = 10;
int front[MAX_LEN+5];
int rear[MAX_LEN+5];
double d[MAX_LEN*MAX_LEN+5];
int main()
{
	int n,m;
	while (1)
	{
		scanf("%d",&n);
		if (n == 0)
		  break;
		scanf("%d",&m);
		for (int i=0;i<n;i++)
		  scanf("%d",&front[i]);
		for (int i=0;i<m;i++)
		  scanf("%d",&rear[i]);
		int k=0;
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<m;j++)
			{
				d[k++] = front[i]*1.0/rear[j]; 
			}
		}
		sort(d,d+k);
		double max = -1;
		for (int i=0;i<k-1;i++)
		{
			if (max < d[i+1]/d[i])
			  max = d[i+1]/d[i];
		}
		printf("%.2f\n",max);
	}
	return 0;
}
