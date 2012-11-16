#include <cstdio>
struct jobs
{
	int priority;
	bool flag;
}queue[100000];
int check(int left,int right)
{
	int max = -1;
	int maxid = left;
	for (int i=left;i<right;i++)
	{
		if (max < queue[i].priority)
		{
			max = queue[i].priority;
			maxid = i;
		}
	}
	return maxid;
}
int main()
{
	int cas;
	scanf("%d",&cas);
	while (cas--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		int head = 0,tail = 0;
		for (tail=0;tail<n;tail++)
		{
			scanf("%d",&queue[tail].priority);
			queue[tail].flag = false;
		}
		queue[m].flag = true;
		while (1)
		{
			int pos = check(head,tail);
			int k=pos-head;
			for (int i=0;i<k;i++)
			{
				queue[tail++] = queue[head++];
			}
			if (queue[head].flag)
			  break;
			head++;
		}
		printf("%d\n",n-tail+head+1);
	}
	return 0;
}
