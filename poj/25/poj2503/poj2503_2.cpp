/*************************************************************************
	> File Name: poj2503_2.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年05月05日 星期日 20时19分04秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

#define MAX_NODE 150010
#define BASE 'a'
int tot;
struct Trie{
	int flag;
	char node[15];
	int child[26];
}trie[MAX_NODE];
void insert(char a[], char b[]){
	int now = 0;
	int len = strlen(b);
	for (int i = 0; i < len; i++){
		if (trie[now].child[b[i] - BASE] == -1){
			tot++;
			for (int j = 0; j < 26; j++)
				trie[tot].child[j] = -1;
			trie[now].child[b[i] - BASE] = tot;
		}
		now = trie[now].child[b[i] - BASE];
	}
	memcpy(trie[now].node, a, sizeof(trie[now].node));
	trie[now].flag = 1;
}
int find(char tmp[]){
	int now = 0;
	int len = strlen(tmp);
	for (int i = 0; i < len; i++){
		now = trie[now].child[tmp[i] - BASE];
		if (now == -1)
			return 0;
	}
	if (trie[now].flag){
		return now;
	}
	return 0;
}
int main()
{
	for (int i = 0; i < 26; i++)
		trie[0].child[i] = -1;
	char str[105];
	char str1[50],str2[50];
	while (gets(str) && str[0] != '\0'){
		sscanf(str, "%s %s", str1, str2);
		insert(str1, str2);
	}
	int f;
	while (scanf("%s", str) != EOF){
		f = find(str);
		if (f)
			printf("%s\n", trie[f].node);
		else
			printf("eh\n");
	}
	return 0;
}
