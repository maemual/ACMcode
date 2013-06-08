#include <cstdio>
#include <cstdlib>
#include <cstring>

int arr[10][10];
char sign[3][20] = {"START", "END", "ENDOFINPUT"};

int main(void){
    int i, j;
    int r, c;
    int ave;
    char tmp[20];

    while (scanf("%s", tmp), strcmp(tmp, sign[2])){
        memset(arr, 0, sizeof(arr));
        scanf("%d%d", &r, &c);
        getchar();
        for (i = 0; i < r; i++){
            for (j = 0; j < c; j++){
                arr[i][j] = getchar() - '0';
            }
            getchar();
        }
        for (i = 1; i < r; i++){
            for (j = 1; j < c; j++){
                ave = arr[i][j] + arr[i - 1][j] + arr[i][j - 1] + arr[i - 1][j - 1];
                printf("%d", ave / 4);
            }
            printf("\n");
        }
        scanf("%s", tmp);
        getchar();
    }
    return 0;
}

