#include<cstdio>
#include<string.h>
using namespace std;

#define MAX_NODE 100000
#define BASE 'a'
struct Trie_Node{
    bool isWord;
    Trie_Node* next[26];
};
struct Trie{
    Trie_Node* head;
    Trie_Node node[MAX_NODE];
    int tot;

    void init(){
        tot = 0;
        memset(node, 0, sizeof(node));
        head = &node[tot++];
    }
    void add(char str[]){
        printf("%s\n", str);
        Trie_Node* cur = head;
        int len = strlen(str);
        for (int i = 0; i < len; i++){
           if (cur->next[str[i] - BASE] == NULL){
               cur->next[str[i] - BASE] = &node[tot++];
           }
           cur = cur->next[str[i] - BASE];
        }
        cur->isWord = true;
    }
    bool find(char str[]){
        Trie_Node* cur = head;
        printf("%s\n", str);
        int len = strlen(str);
        for (int i = 0; i < len; i++){
            cur = cur->next[str[i] - BASE];
            if (cur == NULL)
                break;
        }
        return (cur != NULL && cur->isWord);
    }
}trie;
int main()
{
    return 0;
}
