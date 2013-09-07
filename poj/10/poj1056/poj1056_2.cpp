/*************************************************************************
	> File Name: poj1056.c
	> Author: maemual
	> Mail: maemual@gmail.com
	> Created Time: 2013年05月05日 星期日 14时25分21秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
using namespace std;

#define MAX_NODE 100000
#define BASE '0'
typedef struct Trie{
	int flag;
	Trie *next[2];
}Trie;
Trie *head,node[MAX_NODE];
int tot;
void init(){
	tot = 0;
	memset(node, 0, sizeof(node));
	head = &node[tot++];
}
int trieAdd(char *str){
	Trie *p = head;
	int len = strlen(str);
	int i;
	for (i = 0; i < len; i++){
		if (p != NULL && p->flag == 1)
			return 0;
		p->flag = -1;
		if (p->next[str[i] - BASE] == NULL)
			p->next[str[i] - BASE] = &node[tot++];
		p = p->next[str[i] - BASE];
	}
	if (p->flag != 0)
		return 0;
	p->flag = 1;
	return 1;
}
int main()
{
	int k = 0;
	char str[100];
	bool flag;
	while (1){
		k++;
		flag = false;
		init();
		if (scanf("%s", str) == EOF)
			break;
		while (1){
			if (str[0] == '9')
				break;
			if (!trieAdd(str)){
				flag = true;
			}
			scanf("%s", str);
		}
		if (!flag)
			printf("Set %d is immediately decodable\n", k);
		else
			printf("Set %d is not immediately decodable\n", k);
	}
	return 0;
}
