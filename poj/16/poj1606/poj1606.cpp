#include <cstdio>
#include <cstring>
const int MAX_LEN = 1000;
const int MAX_SIZE = 1000000;
bool vis[MAX_LEN+5][MAX_LEN+5];
int path[1000];
int A,B,C;
int head,tail;
struct node{
	int a,b,step,pre,ope;
}queue[MAX_SIZE];
void push(int a,int b,int step,int pre,int ope)
{
	queue[tail].a = a;
	queue[tail].b = b;
	queue[tail].step = step;
	queue[tail].pre = pre;
	queue[tail++].ope = ope;
}
int bfs()
{
	int a,b,step;
	bool flag = true;
	while (head<=tail)
	{
		a = queue[head].a;
		b = queue[head].b;
		step = queue[head].step;
		if (a==C || b==C)
		{
			flag = false;
			return step;
		}
		if (a!=A && !vis[A][b])
		{
			push(A,b,step+1,head,1);
			vis[A][b] = true;
		}
		if (b!=B && !vis[a][B])
		{
			push(a,B,step+1,head,2);
			vis[a][B] = true;
		}
		if (a!=0 && !vis[0][b])
		{
			push(0,b,step+1,head,3);
			vis[0][b] = true;
		}
		if (b!=0 && !vis[a][0])
		{
			push(a,0,step+1,head,4);
			vis[a][0] = true;
		}
		if (a!=0 && b<B)
		{
			if (a+b<=B && !vis[0][a+b])
			{
				push(0,a+b,step+1,head,5);
				vis[0][a+b] = true;
			}
			if (a+b>B && !vis[a+b-B][B])
			{
				push(a+b-B,B,step+1,head,5);
				vis[a+b-B][B] = true;
			}
		}
		if (b!=0 && a<A)
		{
			if (a+b<=A && !vis[a+b][0])
			{
				push(a+b,0,step+1,head,6);
				vis[a+b][0] = true;
			}
			if (a+b>A && !vis[A][a+b-A])
			{
				push(A,a+b-A,step+1,head,6);
				vis[A][a+b-A] = true;
			}
		}
		head++;
	}
	if (flag)
	  return -1;
}
int main()
{
	int cnt;
	while (scanf("%d %d %d",&A,&B,&C) != EOF)
	{
		memset(vis,0,sizeof(vis));
		head = tail = 0;
		push(0,0,0,0,0);
		vis[0][0] = true;
		cnt = bfs();
		int k=0;
		while (queue[head].step != 0)
		{
			path[k++] = queue[head].ope;
			head = queue[head].pre;
		}
		for (int i=cnt-1;i>=0;i--)
		{
			switch (path[i])
			{
				case 1:printf("fill A\n");break;
				case 2:printf("fill B\n");break;
				case 3:printf("empty A\n");break;
				case 4:printf("empty B\n");break;
				case 5:printf("pour A B\n");break;
				case 6:printf("pour B A\n");break;
			}
		}
		printf("success\n");
	}
	return 0;
}
