#include<iostream>
#include<string.h>
using namespace std;


const int N = 4, M = 500, L = 4;

char S[M]; int len;
int s[N][L]; int _l[N], l[N], ll[N];
int n;

const int Normal = -1;

bool C[N]; int st[N];
bool check(){
    RST(C); 

	C[n-1] = true, st[n-1] = 0;

    for (int k=int(n-1);k>=int(1);--k) if (C[k]){
        int p = st[k];
        for (int i=0;i<int(l[k]);++i){
            if (s[k][i] == Normal){
                ++p;
            }
            else {
                if (C[s[k][i]]){
                    for (int ii=0;ii<int(ll[s[k][i]]);++ii){
                        if (S[p+ii] != S[st[s[k][i]]+ii]) return false;
                    }
                }
                else {
                    C[s[k][i]] = true, st[s[k][i]] = p;
                }
                 p += ll[s[k][i]];
            }
        }
    }
    return true;
}

inline bool dfs1(int, int);
inline bool dfs2(int, int, int);
bool dfs2(int i, int k, int max_ll){
    if (i == l[k]){
        ll[k] = 0; 
		for (int i=0;i<int(l[k]);++i) 
			ll[k] += s[k][i] == Normal ? 1 : ll[s[k][i]];
        return dfs1(k + 1, max(max_ll, ll[k]));
    }
    else {
        for (s[k][i]=int(k-1);s[k][i]>=int(-1);--s[k][i]){
            if (dfs2(i+1, k, max_ll)) return true;
        }
    }
    return false;
}


bool dfs1(int k = 0, int max_ll = 1){
    int t = max_ll; 

	for (int i=int(k);i<int(n);++i) 
		t *= _l[i];
    if (t < len) return false;

    if (k == n){
        return ll[k-1] == len && check();
    }
    else {
        for (l[k]=int(_l[k]);l[k]>=int(0);--l[k]){

            if (dfs2(0, k, max_ll)) return true;
        }
    }
    return false;
}
int main(){
    while (scanf("%d", &n) != (-1)){
        for (int i=int(n-1);i>=int(0);--i) 
			RD(_l[i]); 
		RS(S); 
		len = strlen(S); 
		reverse(S, S + len);
        puts(len <= 256 && dfs1() ? "Yes" : "No");
    }
}
