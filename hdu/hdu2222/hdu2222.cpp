/*************************************************************************
	> File Name: hdu2222.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年05月11日 星期六 20时36分55秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

struct Node{
	Node *next[26], *fail;
	int cnt;
	void init(){
		memset(next, 0, sizeof(next));
		fail = NULL;
		cnt = 0;
	}
}mem[510005];
int tot;

void insert(Node *root, char s[]){
	Node *u = root;
	for (int i = 0; s[i]; i++){
		int id = s[i] - 'a';
		if (u->next[id] == NULL){
			mem[tot].init();
			u->next[id] = &mem[tot++];
		}
		u = u->next[id];
	}
	u->cnt++;
}
queue<Node *> Q;
void getFail(Node *root){
	root->fail = NULL;
	while (!Q.empty()) Q.pop();
	Q.push(root);
	while (!Q.empty()){
		Node *u = Q.front(), *v;
		Q.pop();
		for (int i = 0; i < 26; i++){
			if (u->next[i] == NULL) continue;
			for (v = u->fail; v != NULL; v = v->fail){
				if (v->next[i] == NULL) continue;
				u->next[i]->fail = v->next[i];
				break;
			}
			if (v == NULL) u->next[i]->fail = root;
			Q.push(u->next[i]);
		}
	}
}
int find(Node *root, char s[]){
	int sum = 0;
	Node *u = root, *v;
	for (int i = 0; s[i]; i++){
		int id = s[i] - 'a';
		while (u->next[id] == NULL && u != root) u = u->fail;
		u = u->next[id] == NULL ?root:u->next[id];
		for (v = u; v != root && v->cnt != -1; v = v->fail){
			sum += v->cnt;
			v->cnt = -1;
		}
	}
	return sum;
}
char str[1000005];
int n;
int main()
{
	int T;
	scanf("%d", &T);
	while (T--){
		mem[0].init();
		tot = 0;
		Node *root = &mem[tot++];
		scanf("%d", &n);
		for (int i = 0; i < n; i++){
			scanf("%s", str);
			insert(root, str);
		}
		getFail(root);
		scanf("%s", str);
		printf("%d\n", find(root, str));
	}
	return 0;
}
