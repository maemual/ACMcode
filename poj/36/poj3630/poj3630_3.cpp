#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;

const int branchNum = 10;
bool flag;
int nodeNum;
struct Trie_node{
    bool isStr;
    Trie_node* next[branchNum];
    void init(){
        isStr = false;
        memset(next, NULL, sizeof(next));
    }
}Node[100005];

struct Trie{
    Trie_node root;
    Trie(){
        root = Node[0];
    }
    bool insert(char word[]){
        Trie_node *cur = &root;
        int i = 0;
        int len = strlen(word);
        while (word[i]){
            if (i == len - 1 && cur->next[word[i] - '0'] != NULL){
                return true;
            }
            if (cur->next[word[i] - '0'] == NULL){
                cur->next[word[i] - '0'] = &Node[nodeNum];
                Node[nodeNum].init();
                nodeNum++;
            }
            if (cur->next[word[i] - '0']->isStr == true){
                return true;
            }
            cur = cur->next[word[i] - '0'];
            i++;
        }
        cur->isStr = true;
        return false;
    }
};

int main()
{
    int T;
    scanf("%d", &T);
    int n;
    char str[100];
    while (T--){
        scanf("%d", &n);
        nodeNum = 1;
        getchar();
        flag = false;
        Trie t;
        for (int i = 0; i < n; i++){
            scanf("%s", str);
            if (t.insert(str)){
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
