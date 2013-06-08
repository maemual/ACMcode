#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
using namespace std;

struct node
{
	int pre,step,dir,f,pos,id;
	char x[10];
	bool operator< (const node &n) const {
		return n.f < f;
	}
	node(){dir = -1;}
	node(int pr,int st,int di,int po,char te[])
	{
		pre = pr;
		step = st;
		dir = di;
		pos = po;
		strcpy(x, te);
	}
}q[400000];
int fac[] = {1,1,2,6,24,120,720,5040,40320};
int dd[] = {-1,-3,1,3};
bool move[][4] = {{0,0,1,1}, {1,0,1,1}, {1,0,0,1}, {0,1,1,1}, {1,1,1,1}, {1,1,0,1}, {0,1,1,0}, {1,1,1,0}, {1,1,0,0}};
bool vis[400000];
int hash(const node &n)
{
	int h = 0;
	for (int i=1; i < 9; i++)
	{
		int cnt = 0;
		for (int j = 0; j < i; j++)
		{
			if (n.x[j] > n.x[i])
			  cnt++;
		}
		h += cnt * fac[i];
	}
	return h;
}
int h(const node &n)
{
	int sum = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int k = i * 3 + j;
			if (n.x[k] == 'x')
			  continue;
			sum += abs(i - (n.x[k] - '1') / 3) + abs(j - (n.x[k] - '1') % 3);
		}
	}
	return sum;
}
void output(const node &n)
{
	char path[5000];
	int cnt = 0;
	node temp = n;
	while (temp.pre != -1)
	{
		switch (temp.dir)
		{
			case 0:path[cnt++] = 'l';break;
			case 1:path[cnt++] = 'u';break;
			case 2:path[cnt++] = 'r';break;
			case 3:path[cnt++] = 'd';break;
			default:break;
		}
		temp = q[temp.pre];
	}
	path[cnt] = '\0';
	reverse(path,path+cnt);
	printf("%s\n",path);
}
bool check(const node &s)
{
	int cnt=0;
	for(int i=0;i<9;i++)
	{
		if(s.x[i]=='x') continue;
		for(int j=i-1;j>=0;j--)
		{
			if(s.x[j]=='x')  continue;
			if( s.x[j]>s.x[i] ) cnt++;
		}
	}
	if(cnt % 2 == 1) 
	  return true;
	else
	  return false;
}
priority_queue<node> que;
int main()
{
	node temp;
	char ch;
	while (scanf("%c", &ch) != EOF)
	{
		temp.x[0] = ch;
		if (ch == 'x')
		{
			temp.pos = 0;
		}
		for (int i = 1; i < 9; i++)
		{
			scanf(" %c",&ch);
			temp.x[i] = ch;
			if (temp.x[i] == 'x')
			  temp.pos = i;
		}
		getchar();	
		temp.x[9] = '\0';
		if (check(temp))
		{
			printf("unsolvable\n");
			continue;
		}
		memset(vis,0,sizeof(vis));
		memset(q,0,sizeof(q));
		while (!que.empty()) que.pop();

		temp.step = 0;
		temp.pre = -1;
		temp.f = temp.step + h(temp);
		temp.id = hash(temp);
		q[temp.id] = temp;
		que.push(temp);
		vis[temp.id] = true;
		node A;
	//	bool flag = true;
		while (!que.empty())
		{
			A = que.top();
			que.pop();
			if (!strcmp(A.x,"12345678x"))
			{
				output(A);
	//			flag = false;
				break;
			}
			for (int i = 0; i < 4; i++)
			{
				if (move[A.pos][i] == 0) 
				  continue;
				int xx = A.pos + dd[i];
				if (xx < 0 || xx >=9)
				  continue;
				char tx[10];
				strcpy(tx, A.x);
				swap(tx[xx], tx[A.pos]);
				node B(A.id, A.step + 1, i, xx, tx);
				B.id = hash(B);
				if (vis[B.id])
				  continue;
				vis[B.id] = true;
				B.f = h(B) + B.step;
				q[B.id] = B;
				que.push(B);
			}
		}
	//	if (flag)
	//	  printf("unsolvable\n");
	}
	return 0;
}
