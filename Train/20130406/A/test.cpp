/*************************************************************************
	> File Name: test.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年04月04日 星期四 20时02分43秒
 ************************************************************************/ 
#include<iostream>
#include<string.h>
#include<cstdio>
using namespace std;

struct node{
	int step;
	int state;
}que[10000000];
int n;
bool vis[66666667];
char resu[10];
int ans;
int pp2[] = {0,11};
int pp3[] = {0,11,111,110};
int pp4[] = {0,11,111,1110,1100};
int pp5[] = {0,11,111,1110,11100,11000};
int pp6[] = {0,11,111,1110,11100,111000,110000};
int pp7[] = {0,11,111,1110,11100,111000,1110000,1100000};
int pp8[] = {0,11,111,1110,11100,111000,1110000,11100000,11000000};
int pp[10];
int bfs()
{
	int head,tail;
	head = tail = 0;
	int state;
	tail++;
	int tmp[10];
	int k;
	if (n == 2)
		k = 1;
	else 
		k = n;
	while (head < tail){
		for (int i = k; i >= 1; i--){
			state = que[head].state + pp[i];
			for (int j = n; j >= 1; j--){
				tmp[j] = state % 10;
				state /= 10;
				if (tmp[j] > 6)
					tmp[j] = 1;
			}
			state = 0;
			for (int j = 1; j <= n; j++)
				state = state * 10 + tmp[j];
			if (state == ans){
				int ans = que[head].step + 1;
				return ans;
			}
			if (!vis[state]){
				vis[state] = true;
				que[tail].step = que[head].step + 1;
				que[tail++].state = state;
			}
		}
		head++;
	}
	return -1;
}
int main()
{
	int cas;
	scanf("%d",&cas);
	char str[10];
	int x;
	while (cas--){
		scanf("%d",&n);
		int start = 0;
		for (int i = 0; i < n; i++){
			scanf("%d",&x);
			start = start * 10 + x;
		}
		ans = 0;
		for (int i = 0; i < n; i++){
			scanf("%d",&x);
			ans = ans * 10 + x;
		}
		que[0].step = 0;
		que[0].state = start;
		memset(vis,false,sizeof(vis));
		vis[start] = true;
		if (n == 2)
			for (int i = 1; i <= n-1; i++)
				pp[i] = pp2[i];
		else if (n == 3)
			for (int i = 1; i <= n; i++)
				pp[i] = pp3[i];
		else if (n == 4)
			for (int i = 1; i <= n; i++)
				pp[i] = pp4[i];
		else if (n == 5)
			for (int i = 1; i <= n; i++)
				pp[i] = pp5[i];
		else if (n == 6)
			for (int i = 1; i <= n; i++)
				pp[i] = pp6[i];
		else if (n == 7)
			for (int i = 1; i <= n; i++)
				pp[i] = pp7[i];
		else if (n == 8)
			for (int i = 1; i <= n; i++)
				pp[i] = pp8[i];
		printf("%d\n",bfs());
	}
	return 0;
}
