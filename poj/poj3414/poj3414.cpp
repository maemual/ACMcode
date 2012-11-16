/***************************************
 *	Problem: 3414
 *	Memory: 412K		Time: 0MS
 *	Language: G++		Result: Accepted
 *	2012-07-19 09:08:51
 ***************************************/ 
#include <cstdio>
#include <cstring>
const int MAX_LEN = 100;
const int MAX_SIZE = 1000000;
bool vis[MAX_LEN+5][MAX_LEN+5];
int path[1000];
int A,B,C;
int head,tail;
struct node{
	int a,b,step,pre,ope;//a表示A中的数量，b表示B中数量，step表示步数，pre表示前一个节点，ope表示何种操作
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
		//当满足条件时，返回
		if (a == C || b == C)
		{
			flag = false;
			return step;
		}
		//当A中没满，尝试向A中进行FILL操作
		if (a!=A && !vis[A][b])
		{
			push(A,b,step+1,head,1);
			vis[A][b] = true;
		}
		//当B中没满，尝试向B中进行FILL操作
		if (b!=B && !vis[a][B])
		{
			push(a,B,step+1,head,2);
			vis[a][B] = true;
		}
		//当A中非空，尝试对A进行DROP操作
		if (a!=0 && !vis[0][b])
		{
			push(0,b,step+1,head,3);
			vis[0][b] = true;
		}
		//当B非空，尝试对B进行DROP操作
		if (b!=0 && !vis[a][0])
		{
			push(a,0,step+1,head,4);
			vis[a][0] = true;
		}
		//当A非空，并且B未满，尝试进行POUR（A，B）操作
		if (a!=0 && b<B)
		{
			//当将A可以全部倒入B中
			if (a+b<=B && !vis[0][a+b])
			{
				push(0,a+b,step+1,head,5);
				vis[0][a+b] = true;
			}
			//当A只能一部分倒入B中
			if (a+b>B && !vis[a+b-B][B])
			{
				push(a+b-B,B,step+1,head,5);
				vis[a+b-B][B] = true;
			}
		}
		//当B非空，并且A未满，尝试进行POUR（B，A）操作
		if (b!=0 && a<A)
		{
			//当将B可以全部倒入A中
			if (a+b<=A && !vis[a+b][0])
			{
				push(a+b,0,step+1,head,6);
				vis[a+b][0] = true;
			}
			//当B只能一部分倒入A中
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
		memset(vis,0,sizeof(0));
		head = tail = 0;
		push(0,0,0,0,0);
		vis[A][B] = true;
		cnt = bfs();
		if (cnt == -1)
		{
			printf("impossible\n");
			continue;
		}
		int k=0;
		//生成操作的路径
		while (queue[head].step != 0)
		{
			path[k++] = queue[head].ope;
			head = queue[head].pre;
		}
		printf("%d\n",cnt);
		for (int i=cnt-1;i>=0;i--)
		{
			switch (path[i])
			{
				case 1:printf("FILL(1)\n");break;
				case 2:printf("FILL(2)\n");break;
				case 3:printf("DROP(1)\n");break;
				case 4:printf("DROP(2)\n");break;
				case 5:printf("POUR(1,2)\n");break;
				case 6:printf("POUR(2,1)\n");break;
			}
		}
	}
	return 0;
}
