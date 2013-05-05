/*************************************************************************
	> File Name: poj3630_2.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年05月05日 星期日 17时05分13秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

#define MAX_NODE 70005
#define BASE '0'
typedef struct Trie{
	int flag;
	Trie *next[10];
}Trie;
Trie *head,node[MAX_NODE];
int tot;
void init(){
	tot = 0;
	memset(node, '\0', sizeof(node));
	head = &node[tot++];
}
bool trieAdd(char *str){
	Trie *p = head;
	int len = strlen(str);
	int i;
	for (i = 0; i < len; i++){
		int ind = str[i] - BASE;
		if (p->next[ind] == NULL)
			p->next[ind] = &node[tot++];
		if (p->next[ind]->flag == 1){
			return true;
		}
		p = p->next[ind];
	}
	for (i = 0; i < 10; i++){
		if (p->next[i] != NULL){
			return true;
		}
	}
	if (p->flag == 1)
		return true;
	else
		p->flag = 1;
	return false;
}
int main()
{
	int cas;
	char str[15];
	scanf("%d", &cas);
	while (cas--){
		int n;
		scanf("%d", &n);
		getchar();
		bool flag = false;
		init();
		for (int i = 0; i < n; i++){
			scanf("%s", str);
			if (!flag && trieAdd(str)){
				flag = true;
			}
		}
		if (flag)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
