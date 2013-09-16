#include<cstdio>
#include<iostream>
#include<string.h>
#include<string>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    char str[105];
    for (int k = 1; k <= T; k++){
        scanf("%s", str);
        int len = strlen(str);
        if (len < 4){
            printf("Case #%d: %s", k, str);
            printf("nanodesu\n");
            continue;
        }
        if (str[len-1] == 'u' && str[len-2] == 's'
            && str[len-3] == 'e' && str[len-4] == 'd'){
            printf("Case #%d: ", k);
            for (int j = 0; j < len-4; j++){
                printf("%c", str[j]);
            }
            printf("nanodesu\n");
            continue;
        }
        printf("Case #%d: %s", k, str);
        printf("nanodesu\n");
    }
    return 0;
}
