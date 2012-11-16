#include <cstdio>
#include <climits>
const int MAX_LEN = 1000000;
int a[MAX_LEN+5];
int q[1000000]={0};
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=0;i<2*MAX_LEN+5;i++)
	  a[i] = INT_MAX;
	int head = 0;
	int tail = 0;
	q[tail] = n;
	a[q[tail]] = 0;
	while (q[tail] != k)
	{
		if (q[head]+1<MAX_LEN)
		{
			if (a[q[head]+1] > a[q[head]]+1)
			{
				tail++;
				q[tail] = q[head]+1;
				a[q[tail]]=a[q[head]]+1;
				if (q[tail] == k)
				  break;
			}
		}
		if (q[head]-1>=0 && q[head]-1<MAX_LEN)
		{
			if (a[q[head]-1] > a[q[head]]+1 )
			{
				tail++;
				q[tail] = q[head]-1;
				a[q[tail]] = a[q[head]]+1;
				if (q[tail] == k)
				  break;
			}
		}
		if (q[head]*2<MAX_LEN)
		{
			if (a[q[head]*2] > a[q[head]]+1)
			{
				tail++;
				q[tail] = q[head]*2;
				a[q[tail]] = a[q[head]]+1;
				if (q[tail] == k)
				  break;
			}
		}
		head++;
	}
	printf("%d\n",a[q[tail]]);
	return 0;
}
