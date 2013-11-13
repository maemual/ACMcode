#include<cstdio>
#include<string.h>
#include<ctype.h>

using namespace std;

#define MAX_LEN 5000

char str[MAX_LEN + 5];

int main()
{
    while (gets(str)){
        int len = strlen(str);
        int lns = len / 16;
        int pos = 0;
        int line_number = 0;
        int x;
        if (len % 16 == 0)
            x = lns;
        else
            x = lns + 1;
        for (int ln = 0; ln < x; ln++){
            printf("%04x: ", line_number);
            line_number += 16;
            if (ln < lns){
                for (int i = 0; i < 16; i++){
                    printf("%x", str[pos++]);
                    if (i % 2 == 1) printf(" ");
                }
                for (int i = pos - 16; i < pos; i++){
                    if (isupper(str[i])){
                        printf("%c", tolower(str[i]));
                    }else if (islower(str[i])){
                        printf("%c", toupper(str[i]));
                    }else{
                        printf("%c", str[i]);
                    }
                }
            }else{
                int i;
                for (i = 0; pos < len; i++){
                    printf("%x", str[pos++]);
                    if (i % 2 == 1) printf(" ");
                }
                int tmp = (len / 16 + 1) * 16;
                for ( ; pos < tmp; i++){
                    printf("  ");
                    pos++;
                    if (i % 2 == 1) printf(" ");
                }
                for (int i = pos - 16; i < pos; i++){
                    if (i == len) break;
                    if (isupper(str[i])){
                        printf("%c", tolower(str[i]));
                    }else if (islower(str[i])){
                        printf("%c", toupper(str[i]));
                    }else{
                        printf("%c", str[i]);
                    }
                }
            }
            printf("\n");
        }
    }
    return 0;
}
