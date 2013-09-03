#include<cstdio>
#include<string.h>
#include<math.h>

#define MAX_LEN 1000005
char str[MAX_LEN];

unsigned long long biao[70];
int main()
{
    int T;
    int len;
    bool flag;
    int cnt = 0;
    unsigned long long x = 1;
    while (cnt <= 63){
        biao[cnt] = x;
        x *= 2;
        cnt++;
    }
    scanf("%d", &T);
    while (T--){
        scanf("%s", str);
        len = strlen(str);
        if (len == 1 && str[0] == 'M'){
            printf("No\n");
            continue;
        }
        if (len == 2 && str[0] == 'M' && str[1] == 'I'){
            printf("Yes\n");
            continue;
        }
        if (str[0] != 'M'){
            printf("No\n");
            continue;
        }
        flag = false;
        for (int i = 1; i < len; i++){
            if (str[i] == 'M'){
                flag = true;
                break;
            }
        }//if it has 'M'
        if (flag){
            printf("No\n");
            continue;
        }
        int I = 0, U = 0;
        for (int i = 1; i < len; i++){
            if (str[i] == 'I')
                I++;
            else
                U++;
        }
        flag = false;
        unsigned long long x = I + 3 * U;
        for (int i = 0; i <= 63; i++){
            if (biao[i] >= x){
                if ((biao[i] - x) % 6 == 0){
                    flag = true;
                    break;
                }
            }
        }
        if (flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
