#include <cstdio>
#include <string.h>
#include <iostream>

using namespace std;

#define MAX_LEN 100005

int n;
int arr[MAX_LEN];
int opt[MAX_LEN];

void doit(int s, int e){
    if (s == e){
        printf("0\n");
        return ;
    }
    int max1 = 0, max2 = 0, max3 = 0;
    int pos1 = 0, pos2 = 0, pos3 = 0;
    for (int i = s; i < e; ++i){
        if (arr[i] > max1){
            max1 = arr[i];
            pos1 = i;
        }
    }
    for (int i = s; i < e; ++i){
        if (i == pos1) continue;
        if (arr[i] > max2){
            max2 = arr[i];
            pos2 = i;
        }
    }
    for (int i = s; i < e; ++i){
        if (i == pos1 || i == pos2) continue;
        if (arr[i] > max3){
            max3 = arr[i];
            pos3 = i;
        }
    }
    if (e - s == 1){
        printf("pushStack\n");
        if (e < n)
            printf("1 popStack\n");
        return ;
    }else if (e - s == 2){
        printf("pushStack\n");
        printf("pushQueue\n");
        if (e < n)
            printf("2 popStack popQueue\n");
        return ;
    }else{
       opt[pos1] = 1;
       opt[pos2] = 2;
       opt[pos3] = 3;
       for (int i = s; i < e; ++i){
           if (opt[i] == 0){
               printf("pushBack\n");
           }else if (opt[i] == 1){
               printf("pushStack\n");
           }else if (opt[i] == 2){
               printf("pushQueue\n");
           }else if (opt[i] == 3){
               printf("pushFront\n");
           }
       }
       if (e < n)
           printf("3 popStack popQueue popFront\n");
       return ;
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    memset(opt, 0, sizeof(opt));
    int first = 0, last = 0;
    while (last < n){
        while (arr[last] != 0) ++last;
        doit(first, last);
        ++last;
        first = last;
    }
    return 0;
}
