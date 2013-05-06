/*************************************************************************
	> File Name: zoj1038.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年05月06日 星期一 09时52分19秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

#define MAX_NODE 55555
int c[1005][105],tot;
char s[1005][105];
char str[105];
char dic[] = "22233344455566677778889999";
struct Trie{
	int next[8];
	int num;
	char s[105];
	void init(){
		memset(next, 0, sizeof(next));
		num = 0;
	}
}trie[MAX_NODE];
void trieBuild(char *str, int id){
	int index, now = 0;
	int len = strlen(str);
	for (int i = 0; i < len; i++){
		index = dic[str[i] - 'a'] - '2';
		if (trie[now].next[index] == 0)
			trie[now].next[index] = ++tot;
		now = trie[now].next[index];
		if (c[id][i] > trie[now].num){
			trie[now].num = c[id][i];
			for (int j = 0; j <= i; j++)
				trie[now].s[j] = s[id][j];
			trie[now].s[i + 1] = '\0';
		}
	}
}
void trieFind(char *str){
	int index, now = 0;
	int flag = 0;
	for (int i = 0; str[i] != '1'; i++){
		index = str[i] - '2';
		now = trie[now].next[index];
		if (trie[now].num == 0 || now == 0 || flag){
			printf("MANUALLY\n");
			flag = 1;
		}else
			printf("%s\n", trie[now].s);
	}
}
int main()
{
	int cas;
	int n,m,p;
	int len;
	scanf("%d", &cas);
	for (int k = 1; k <= cas; k++){
		scanf("%d", &n);
		memset(c, 0, sizeof(c));
		for (int i = 0; i < n; i++){
			scanf("%s %d",s[i], &p);
			len = strlen(s[i]);
			for (int j = 0; j < len; j++)
				c[i][j] = p;
		}
		for (int i = 1; i < n; i++){
			for (int j = 0; s[i][j] && s[i-1][j]; j++){
				if (s[i][j] == s[i-1][j]){
					c[i][j] += c[i-1][j];
					c[i-1][j] = 0;
				}
				else break;
			}
		}
		for (int i = 0; i < MAX_NODE; i++) trie[i].init();
		tot = 0;
		for (int i = 0; i < n; i++)
			trieBuild(s[i], i);
		scanf("%d", &m);
		printf("Scenario #%d:\n", k);
		while (m--){
			scanf("%s", str);
			trieFind(str);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
