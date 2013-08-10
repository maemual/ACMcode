#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

#define MAX_LEN 10086
#define MOD 10007
char str[MAX_LEN + 5];
int fibo[MAX_LEN + 5];
int main()
{
    fibo[1] = 2;
    fibo[2] = 3;
    for (int i = 3; i < MAX_LEN; i++){
        fibo[i] = (fibo[i-1] + fibo[i-2]) % MOD;
    }
    int T;
    scanf("%d", &T);
    for (int k = 1; k <= T; k++){
        scanf("%s", str);
        int len = strlen(str);
        int j = 0;
        long long ans = 1;
        for (int i = 0; i < len - 3; i++){
            if (str[i] == 'h' && str[i+1] == 'e' && str[i+2] == 'h' && str[i+3] == 'e') {
                j = i + 4;
                while (j < len && str[j] == 'h' && str[j+1] == 'e') j += 2;
                int tmp = (j - i) / 2 - 1;
                ans *= fibo[tmp];
                ans %= MOD;
                i = j - 1;
            }
        }
        cout << "Case " << k << ": " << ans << endl;
    }
    return 0;
}
