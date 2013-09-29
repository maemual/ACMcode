#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct subnet{
    unsigned int ip;
    int bits;
}sub;
struct enable{
    vector<subnet> vec;
    int id;
    bool able;
}enb;
vector<enable> e;
unsigned int mask[] = {0,0,0,0,0,0,0,0,4278190080LL,4286578688LL,4290772992LL,4292870144LL,4293918720LL,4294443008LL,4294705152LL,
            4294836224LL,4294901760LL,4294934528LL,4294950912LL,4294959104LL,4294963200LL,4294965248LL,4294966272LL,4294966784LL,
            4294967040LL,4294967168LL};
bool in_sub(unsigned int ip, unsigned int s, int cnt){
    if((ip&mask[cnt]) == (s&mask[cnt]))
        return true;
    else
        return false;
}
int main()
{
    char ch;
    e.clear();
    int id, n;
    int x1, x2, x3, x4, x5;
    while (scanf("%c", &ch) != EOF){
        if (ch == 'E'){
            scanf("%d %d", &id, &n);
            enb.vec.clear();
            enb.id = id;
            enb.able = true;
            for (int i = 0; i < n; i++){
                scanf("%d.%d.%d.%d/%d", &x1, &x2, &x3, &x4, &x5);
                sub.bits = x5;
                sub.ip = (x1 << 24) + (x2 << 16) + (x3 << 8) + x4;
                enb.vec.push_back(sub);
            }
            e.push_back(enb);
        }else if (ch == 'F'){
            vector<int> vec1, vec2;
            vec1.clear();
            vec2.clear();
            bool flag = false, flag2 = false;
            bool flag3 = false;
            scanf("%d.%d.%d.%d", &x1, &x2, &x3, &x4);
            unsigned int ip = (x1 << 24) + (x2 << 16) + (x3 << 8) + x4;
            scanf("%d.%d.%d.%d", &x1, &x2, &x3, &x4);
            unsigned int ip2 = (x1 << 24) + (x2 << 16) + (x3 << 8) + x4;
            int len = e.size();
            for (int i = 0; i < len; i++){
                if (e[i].able){
                    int llen = e[i].vec.size();
                    for (int j = 0; j < llen; j++){
                        if (in_sub(ip, e[i].vec[j].ip, e[i].vec[j].bits)){
                            flag = true;
                            break;
                        }
                    }
                    for (int j = 0; j < llen; j++){
                        if (in_sub(ip2, e[i].vec[j].ip, e[i].vec[j].bits)){
                            flag2 = true;
                            break;
                        }
                    }
                    if (flag && flag2){
                       flag3 = true;
                       break;
                    }
                }
            }
            /*
            bool flag2 = false;
            len = e.size();
            for (int i = 0; i < len; i++){
                if (e[i].able){
                    int llen = e[i].vec.size();
                    for (int j = 0; j < llen; j++){
                        if (in_sub(ip, e[i].vec[j].ip, e[i].vec[j].bits)){
                            vec2.push_back(e[i].id);
                            break;
                        }
                    }
                }
            }
            flag = false;
            for (int i = 0; i < vec1.size(); i++){
                for (int j = 0; j < vec2.size(); j++){
                    if (vec1[i] == vec2[j]){
                        flag = true;
                        break;
                    }
                }
                if (flag)
                    break;
            }
            */
            if (flag3)
                printf("F\n");
            else
                printf("D\n");
        }else if (ch == 'D'){
            scanf("%d", &x1);
            int len = e.size();
            for (int i = 0; i < len; i++){
                if (e[i].id == x1){
                    e[i].able = false;
                }
            }
        }
    }
    return 0;
}
