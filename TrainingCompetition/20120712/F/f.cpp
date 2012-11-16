#include <cstdio>
#include <cstdlib>
using namespace std;
struct ss
{
	int num;
	int k;
}queue[10000000];
int main()
{
	int n;
	while (scanf("%d",&n) != EOF)
	{
		int head = 0,tail = 0;
		queue[tail].num = 0;
		queue[tail].k = 0;
		while (queue[tail].num != n)
		{
			tail++;
			if (tail>10000000)
			  tail = 0;
			queue[tail].num = queue[head].num+queue[head].k+1;
			queue[tail].k = queue[head].k+1;
			if (queue[tail].num == n)
			  break;

			tail++;
			if (tail>10000000)
				tail=0;
			queue[tail].num = queue[head].num-queue[head].k-1;
			queue[tail].k = queue[head].k+1;
		
			head++;
			if (head>10000000)
			  head = 0;
		}
		printf("%d\n",queue[tail].k);
	}
	return 0;
}
