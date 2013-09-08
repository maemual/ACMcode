#include<cstdio>
using namespace std;

char arr[20][20];
char ch = 'a';
void solve(int k){
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++)
            arr[i][j] = ' ';
    for (int i = 0; i < k; i++){
        arr[i][0] = ch;
        ch = (ch - 'a' + 1) % 26 + 'a';
    }
    int x = 1;
    for (int i = k - 2; i >= 0; i--){
        arr[i][x++] = ch;
        ch = (ch - 'a' + 1) % 26 + 'a';
    }
    for (int i = 1; i < k; i++){
        arr[i][k-1] = ch;
        ch = (ch - 'a' + 1) % 26 + 'a';
    }
    for (int i = 0; i < k; i++){
        for (int j = 0; j < k; j++){
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    for (int i = 3; i <= 10; i++){
        solve(i);
    }
    return 0;
}
