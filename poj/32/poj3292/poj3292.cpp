#include <cstdio>
#include <string.h>
const int nMax = 1000010;
const int mMax = 90000;
 
bool p[nMax];
int cnt, H_pri[mMax];
int H_se_pri[nMax];
 
void H_priList(){        //  筛选法求出H-primes。
    int i, j, k;
    for(i = 1; i < nMax; i += 4)
        p[i] = true;
    for(i = 5; i * i < nMax; i += 4)
        if(p[i]){
            k = i << 1;
            for(j = i + k; j < nMax; j += k)
                p[j] = false;
        }
    for(cnt = 0, i = 5; i < nMax; i += 4)
        if(p[i]) H_pri[cnt ++] = i;
}
 
void H_se_priList(){    //  枚举每两个H_primes构造出H_semi_prime。
    int i, j, w;
    memset(p, false, sizeof(p));
    for(i = 0; H_pri[i] * H_pri[i] < nMax; i ++)     //  注意用H_pri[i] * H_pri[i] < nMax。
        for(j = i; j < cnt; j ++){
            w = H_pri[i] *  H_pri[j];
            if(w >= nMax) break;
            if((w - 1) % 4 == 0) p[w] = true;
        }
    for(i = 1; i < nMax; i ++){                      //  预处理打表。
        H_se_pri[i] = H_se_pri[i - 1];
        if(p[i]) H_se_pri[i] ++;
    }
}
 
int main(){
    int num;
    H_priList();
    H_se_priList();
    while(scanf("%d", &num) && num)
        printf("%d %d\n", num, H_se_pri[num]);
    return 0;
}
