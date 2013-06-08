/*************************************************************************
	> File Name: poj1753.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年03月21日 星期四 19时28分18秒
 ************************************************************************/

#include<cstdio>
#include<string.h>

#define MAX_LEN 65536

const int Sta[] ={0,51200,58368,29184,12544,35968,20032,10016,4880,2248,
1252,626,305,140,78,39,19};
struct Node{
	int state;
	int step;
}Queue[MAX_LEN];

bool vis[MAX_LEN];
int head,tail;
int bfs(){
	vis[Queue[tail].state] = true;
	Queue[tail++].step = 0;

	int now;
	while (head < tail){

		for (int i = 1; i <= 16; i++){
			now = Queue[head].state ^ Sta[i];
			if (!vis[now]){
				Queue[tail].state = now;
				Queue[tail++].step = Queue[head].step + 1;
				vis[now] = true;

				if (now == 0x0000 || now == 0xffff)
					return Queue[head].step + 1;
			}
		}
		head++;
	}
	return -1;
}
int main()
{
	memset(Queue,0,sizeof(Queue));
	memset(vis,0,sizeof(vis));
	char ch;
	head = tail = 0;
	for (int i = 15; i >= 0; i--){
		ch = getchar();
		if (ch == 'b')
			Queue[tail].state |= (1 << i);
		if (i % 4 == 0)
			getchar();
	}

	if (Queue[tail].state == 0x0000 || Queue[tail].state == 0xffff){
		printf("0\n");
		return 0;
	}

	int ans = bfs();
	if (ans != -1)
		printf("%d\n",ans);
	else
		printf("Impossible\n");

	return 0;
}
