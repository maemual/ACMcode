#include<cstdio>

int arr[15];
int main()
{
    char str[15];
    int m;
    int cnt = 0;
    scanf("%s", str);
    scanf("%d", &m);
    for (int i = 0; i < 10; i++){
        arr[i+1] = str[i] - '0';
        if (arr[i+1] == 1)
            cnt++;
    }
    if (cnt == 0){
        printf("NO\n");
        return 0;
    }
    if (m == 1 && cnt >= 1){
        printf("YES\n");
        for (int i = 1; i <= 10; i++){
            if (arr[i] == 1){
                printf("%d\n", i);
                return 0;
            }
        }
    }
    if (m > 1 && cnt == 1){
        printf("NO\n");
        return 0;
    }
    int mmin = 100;
    int left = -1;
    int right = -1;
    for (int i = 1; i < 10; i++){
        if (arr[i] == 1){
            int j;
            for (j = i + 1; j <= 10; j++){
                if (arr[j] == 1)
                    break;
            }
            if (j == 11)
                continue;
            if (j - i <= mmin){
                mmin = j - i;
                left = i;
                right = j;
            }
        }
    }
    if (left == -1 || right == -1){
        printf("NO\n");
        return 0;
    }
    if (left * 2 <= right){
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    for (int i = 0; i < m - 1; i++){
        if (i % 2 == 0){
            printf("%d ", left);
        }else
            printf("%d ", right);
    }
    if (m % 2 == 0)
        printf("%d\n", right);
    else
        printf("%d\n", left);
    return 0;
}
