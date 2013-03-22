/*************************************************************************
	> File Name: zoj3765.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年03月22日 星期五 14时25分45秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

struct Node{
	int nail;//指甲状态，1表示没剪过，0表示剪过
	int step;
}now,tmp;

bool vis[1050000];
int n,m,cut1,cut2;
int bfs(){
	queue<struct Node> que;
	now.nail = (1 << m) - 1;
	now.step = 0;
	que.push(now);
	vis[now.nail] = true;

	while (!que.empty()){
		now = que.front();
		que.pop();
		if (!now.nail)
			return now.step;
		//正剪
		tmp = now;
		tmp.nail &= cut1;
		while (tmp.nail && ((tmp.nail & 1) == 0))
			tmp.nail >>= 1;

		if (!vis[tmp.nail]){
			tmp.step++;
			que.push(tmp);
			vis[tmp.nail] = true;
		}
		//反剪
		tmp = now;
		tmp.nail &= cut2;
		while (tmp.nail && ((tmp.nail & 1) == 0))
			tmp.nail >>= 1;

		if (!vis[tmp.nail]){
			tmp.step++;
			que.push(tmp);
			vis[tmp.nail] = true;
		}
	}
	return -1;
}
int main()
{
	int i;
	while (scanf("%d",&n) != EOF){
		char clipper[15];
		scanf("%s",clipper);
		scanf("%d",&m);
		cut1 = cut2 = (1 << 21) - 1;

		for (i = 0; i < n; i++){
			if (clipper[i] == '*'){
				cut1 &= ~(1 << i);
				cut2 &= ~(1 << (n-i-1));
			}
		}//指甲刀，完整部分为0，豁口部分为1

		if (cut1 == (1 << 21)-1){
			printf("-1\n");
			continue;
		}

		while (cut1 & 1)
			cut1 = (cut1 >> 1) | 0x100000;
		while (cut2 & 1)
			cut2 = (cut2 >> 1) | 0x100000;

		memset(vis,0,sizeof(vis));
		printf("%d\n",bfs());
	}
	return 0;
}
