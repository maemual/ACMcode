#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

struct Trie_Node{
    Trie_Node* next[26], *fail;
    int cnt;
    void init(){
        memset(next, 0, sizeof(next));
        fail = NULL;
        cnt = 0;
    }
}mem[510005];
struct ACautomation{
    int tot;
    queue<Trie_Node *> que;
    Trie_Node* root;
    void init(){
        mem[0].init();
        tot = 0;
        root = &mem[tot++];
    }
    void insert(char str[]){
       Trie_Node* cur = root;
       for (int i = 0; str[i]; i++){
           int idx = str[i] - 'a';
           if (cur->next[idx] == NULL){
               mem[tot].init();
               cur->next[idx] = &mem[tot++];
           }
           cur = cur->next[idx];
       }
       cur->cnt++;
    }
    void build(){
        root->fail = NULL;
        while (!que.empty()) que.pop();
        que.push(root);
        Trie_Node *cur, *v;
        while (!que.empty()){
            cur = que.front();
            que.pop();
            for (int i = 0; i < 26; i++){
                if (cur->next[i] == NULL) continue;
                for (v = cur->fail; v != NULL; v = v->fail){
                    if (v->next[i] == NULL) continue;
                    cur->next[i]->fail = v->next[i];
                    break;
                }
                if (v == NULL)
                    cur->next[i]->fail = root;
                que.push(cur->next[i]);
            }
        }
    }
    int query(char str[]){
        int sum = 0;
        Trie_Node* cur = root, *v;
        for (int i = 0; str[i]; i++){
            int idx = str[i] - 'a';
            while (cur->next[idx] == NULL && cur != root)
                cur = cur->fail;
            cur = cur->next[idx] == NULL ? root : cur->next[idx];
            for (v = cur; v != root && v->cnt != -1; v = v->fail){
                sum += v->cnt;
                v->cnt = -1;
            }
        }
        return sum;
    }
}ac;
char s[1000005];
int n;
int main()
{
    int T;
    scanf("%d", &T);
    while (T--){
        ac.init();
        scanf("%d", &n);
        for (int i = 0; i < n; i++){
            scanf("%s", s);
            ac.insert(s);
        }
        ac.build();
        scanf("%s", s);
        printf("%d\n", ac.query(s));
    }
    return 0;
}
